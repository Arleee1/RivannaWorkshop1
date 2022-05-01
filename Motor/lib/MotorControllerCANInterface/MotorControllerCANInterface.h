#ifndef MOTOR_CONTROLLER_CAN_INTERFACE_H
#define MOTOR_CONTROLLER_CAN_INTERFACE_H

#include "CANInterface.h"
#include "MotorControllerCANStructs.h"

class MotorControllerCANInterface : public CANInterface {
  public:
    MotorControllerCANInterface(PinName rd, PinName td, PinName standby_pin);
    void request_frames(bool power_status_frame, bool drive_status_frame,
                        bool errors_frame);
    void handle(MotorControllerPowerStatus *can_struct);
    void handle(MotorControllerDriveStatus *can_struct);
    void handle(MotorControllerError *can_struct);

  private:
    void rx_handler() override;
};

#endif
