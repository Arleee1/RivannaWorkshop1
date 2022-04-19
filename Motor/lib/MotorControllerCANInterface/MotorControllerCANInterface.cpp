#include "MotorControllerCANInterface.h"

MotorControllerCANInterface::MotorControllerCANInterface(PinName rd, PinName td,
                                                         PinName standby_pin)
    : CANInterface(rd, td, standby_pin) {
    can.frequency(125000);
}

void MotorControllerCANInterface::request_frames(bool power_status_frame,
                                                 bool drive_status_frame,
                                                 bool errors_frame) {
    CANMessage message;
    FrameRequest request;
    request.power_status_frame = power_status_frame;
    request.drive_status_frame = drive_status_frame;
    request.errors_frame = errors_frame;
    request.serialize(&message);
    message.id = request.get_message_ID();
    message.format = CANFormat::CANExtended;
    can.write(message);
}

void MotorControllerCANInterface::rx_handler() {
    while (true) {
        CANMessage message;
        while (can.read(message)) {
            if (message.id ==
                MOTOR_CONTROLLER_MotorControllerPowerStatus_MESSAGE_ID) {
                MotorControllerPowerStatus can_struct;
                can_struct.deserialize(&message);
                handle(&can_struct);
            } else if (message.id ==
                       MOTOR_CONTROLLER_MotorControllerDriveStatus_MESSAGE_ID) {
                MotorControllerDriveStatus can_struct;
                can_struct.deserialize(&message);
                handle(&can_struct);
            } else if (message.id ==
                       MOTOR_CONTROLLER_MotorControllerError_MESSAGE_ID) {
                MotorControllerError can_struct;
                can_struct.deserialize(&message);
                handle(&can_struct);
            }
        }
    }
}
