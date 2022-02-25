#include <mbed.h>
#include <rtos.h>
#include "pindef.h"
#include "Printing.h"
#include "ECUCANInterface.h"
#include "ECUInputReader.h"
#include "ECUCANStructs.h"

#define TESTING     // only defined if using test functions
// #define DEBUGGING   // only define if debugging

#define MAIN_LOOP_PERIOD 1s
#define CAN_PERIOD 1s
#define MOTOR_THREAD_PERIOD 1s
#define POWERAUX_THREAD_PERIOD 1s

// Can Interface //
ECUCANInterface vehicle_can_interface(CAN_RX, CAN_TX, CAN_STBY);

// Input Reader //
ECUInputReader input_reader;

// CAN Messages //
ECUMotorCommands to_motor;
ECUPowerAuxCommands to_poweraux;

// Cruise Control Logic //
uint8_t current_speed;

// Message Sending Threads //
Thread motor_thread;
Thread poweraux_thread;

void motor_message_handler()
{
    while (true)
    {
        // Read motor commands
        to_motor.throttle = input_reader.readThrottle();
        to_motor.regen = input_reader.readRegen();
        to_motor.forward_en = input_reader.readForwardEn();
        to_motor.reverse_en = input_reader.readReverseEn();
        to_motor.cruise_control_en = input_reader.readCruiseThrottleEn();
        to_motor.cruise_control_speed = current_speed + input_reader.readCruiseSpeedUp() - input_reader.readCruiseSpeedDown();
        to_motor.motor_on = input_reader.readMotorOn();

        // Send message

        PRINT("Motor Message Send Status: %d\r\n", vehicle_can_interface.send(&to_motor));

        // Sleep
        ThisThread::sleep_for(MOTOR_THREAD_PERIOD);
    }
}

void poweraux_message_handler()
{
    while (true)
    {
        // Read poweraux commands
        to_poweraux.hazards = input_reader.readHazards();
        to_poweraux.brake_lights = input_reader.readBrakePedal();
        to_poweraux.headlights = input_reader.readRunningLights();
        to_poweraux.left_turn_signal = input_reader.readLeftTurnSignal();
        to_poweraux.right_turn_signal = input_reader.readRightTurnSignal();

        // Send message
        PRINT("PowerAux Message Send Status: %d\r\n", vehicle_can_interface.send(&to_poweraux));


        // Sleep
        ThisThread::sleep_for(POWERAUX_THREAD_PERIOD);
    }

}

int main() {
#ifdef TESTING
    PRINT("start main() \r\n");
#endif //TESTING

    motor_thread.start(motor_message_handler);
    poweraux_thread.start(poweraux_message_handler);

    while(true)
    {
        #ifdef TESTING
            PRINT("main thread loop \r\n");
        #endif //TESTING

        // PowerAuxExampleStruct a(1, 2, 3, 4);
        // vehicle_can_interface.send(&a);

        ThisThread::sleep_for(MAIN_LOOP_PERIOD);
    }
}
