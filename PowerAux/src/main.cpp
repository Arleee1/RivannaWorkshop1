#include "BPSCANInterface.h"
#include "BPSRelayController.h"
#include "DigitalOut.h"
#include "PowerAuxCANInterface.h"
#include "Printing.h"
#include "ThisThread.h"
#include "log.h"
#include "pindef.h"
#include <mbed.h>
#include <rtos.h>

PowerAuxCANInterface vehicle_can_interface(MAIN_CAN_RX, MAIN_CAN_TX,
                                           MAIN_CAN_STBY);
BPSCANInterface bps_can_interface(BMS_CAN1_RX, BMS_CAN1_TX, BMS_CAN1_STBY);

DigitalOut leftTurnSignal(LEFT_TURN_EN);
DigitalOut rightTurnSignal(RIGHT_TURN_EN);

bool fLeftSignal, fRightSignal = false;

void signalFlashHandler() {
    while (true) {
        if (fLeftSignal) {
            fLeftSignal = true;
        }
        if (fRightSignal) {
            fRightSignal = true
        }
        ThisThread::sleep_for(2000);
        fLeftSignal = false;
        fRightSignal = false;
        ThisThread::sleep_for(2000);
    }
}


void PowerAuxCANInterface::handle(ECUPowerAuxCommands *can_struct) {
    can_struct->log(LOG_INFO);

    brake_lights = can_struct->brake_lights;

    fLeftSignal = can_struct->left_turn_signal;
    fRightSignal = can_struct->right_turn_signal;
    //flashHazards = can_struct->hazards;

    signalFlashThread.flags_set(0x1);
}
void PowerAuxCANInterface::handle(ECUPowerAuxCommands *can_struct) {
    can_struct->log(LOG_INFO);

    brake_lights = can_struct->brake_lights;

    flashLSignal = can_struct->left_turn_signal;
    flashRSignal = can_struct->right_turn_signal;
    flashHazards = can_struct->hazards;

    signalFlashThread.flags_set(0x1);
}

void BPSCANInterface::handle(BPSPackInformation *can_struct) {
    can_struct->log(LOG_INFO);

    bps_relay_controller.update_state(can_struct);

    vehicle_can_interface.send(can_struct);
}

void BPSCANInterface::handle(BPSError *can_struct) {
    can_struct->log(LOG_INFO);

    bps_relay_controller.update_state(can_struct);

    vehicle_can_interface.send(can_struct);
}

void BPSCANInterface::handle(BPSCellVoltage *can_struct) {
    can_struct->log(LOG_INFO);

    vehicle_can_interface.send(can_struct);
}

void BPSCANInterface::handle(BPSCellTemperature *can_struct) {
    can_struct->log(LOG_INFO);

    vehicle_can_interface.send(can_struct);
}