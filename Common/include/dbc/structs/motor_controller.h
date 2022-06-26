/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018-2019 Erik Moqvist
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * This file was generated by cantools version 37.1.0 Sat Jun 25 00:05:36 2022.
 */

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef EINVAL
#    define EINVAL 22
#endif

/* Frame ids. */
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_FRAME_REQUEST_FRAME_ID (0x332u)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_POWER_STATUS_FRAME_ID (0x325u)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_DRIVE_STATUS_FRAME_ID (0x315u)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_ERROR_FRAME_ID (0x115u)

/* Frame lengths in bytes. */
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_FRAME_REQUEST_LENGTH (1u)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_POWER_STATUS_LENGTH (8u)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_DRIVE_STATUS_LENGTH (5u)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_ERROR_LENGTH (5u)

/* Extended or standard frame types. */
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_FRAME_REQUEST_IS_EXTENDED (0)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_POWER_STATUS_IS_EXTENDED (0)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_DRIVE_STATUS_IS_EXTENDED (0)
#define MOTOR_CONTROLLER_MOTOR_CONTROLLER_ERROR_IS_EXTENDED (0)

/* Frame cycle times in milliseconds. */


/* Signal choices. */


/**
 * Signals in message MotorControllerFrameRequest.
 *
 * All signal values are as on the CAN bus.
 */
struct motor_controller_motor_controller_frame_request_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t power_status_frame;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t drive_status_frame;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t error_frame;
};

/**
 * Signals in message MotorControllerPowerStatus.
 *
 * All signal values are as on the CAN bus.
 */
struct motor_controller_motor_controller_power_status_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t battery_voltage;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t battery_current;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t battery_current_direction;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t motor_current;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t fet_temp;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t motor_rpm;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t pwm_duty;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t lead_angle;
};

/**
 * Signals in message MotorControllerDriveStatus.
 *
 * All signal values are as on the CAN bus.
 */
struct motor_controller_motor_controller_drive_status_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t power_mode;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t control_mode;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t accelerator_vr_position;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t regen_vr_position;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t digital_sw_position;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint16_t output_target_value;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t motor_status;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t regen_status;
};

/**
 * Signals in message MotorControllerError.
 *
 * All signal values are as on the CAN bus.
 */
struct motor_controller_motor_controller_error_t {
    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t analog_sensor_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t motor_current_sensor_u_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t motor_current_sensor_w_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t fet_thermistor_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t battery_voltage_sensor_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t battery_current_sensor_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t battery_current_sensor_adj_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t motor_current_sensor_adj_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t accelerator_position_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t controller_voltage_sensor_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t power_system_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t overcurrent_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t overvoltage_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t overcurrent_limit;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t motor_system_err;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t motor_lock;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t hall_sensor_short;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t hall_sensor_open;

    /**
     * Range: -
     * Scale: 1
     * Offset: 0
     */
    uint8_t overheat_level;
};

/**
 * Pack message MotorControllerFrameRequest.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int motor_controller_motor_controller_frame_request_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_frame_request_t *src_p,
    size_t size);

/**
 * Unpack message MotorControllerFrameRequest.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int motor_controller_motor_controller_frame_request_unpack(
    struct motor_controller_motor_controller_frame_request_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_frame_request_power_status_frame_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_frame_request_power_status_frame_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_frame_request_power_status_frame_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_frame_request_drive_status_frame_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_frame_request_drive_status_frame_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_frame_request_drive_status_frame_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_frame_request_error_frame_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_frame_request_error_frame_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_frame_request_error_frame_is_in_range(uint8_t value);

/**
 * Pack message MotorControllerPowerStatus.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int motor_controller_motor_controller_power_status_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_power_status_t *src_p,
    size_t size);

/**
 * Unpack message MotorControllerPowerStatus.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int motor_controller_motor_controller_power_status_unpack(
    struct motor_controller_motor_controller_power_status_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_power_status_battery_voltage_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_battery_voltage_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_battery_voltage_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_power_status_battery_current_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_battery_current_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_battery_current_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_power_status_battery_current_direction_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_battery_current_direction_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_battery_current_direction_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_power_status_motor_current_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_motor_current_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_motor_current_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_power_status_fet_temp_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_fet_temp_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_fet_temp_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_power_status_motor_rpm_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_motor_rpm_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_motor_rpm_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_power_status_pwm_duty_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_pwm_duty_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_pwm_duty_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_power_status_lead_angle_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_power_status_lead_angle_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_power_status_lead_angle_is_in_range(uint8_t value);

/**
 * Pack message MotorControllerDriveStatus.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int motor_controller_motor_controller_drive_status_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_drive_status_t *src_p,
    size_t size);

/**
 * Unpack message MotorControllerDriveStatus.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int motor_controller_motor_controller_drive_status_unpack(
    struct motor_controller_motor_controller_drive_status_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_drive_status_power_mode_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_power_mode_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_power_mode_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_drive_status_control_mode_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_control_mode_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_control_mode_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_drive_status_accelerator_vr_position_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_accelerator_vr_position_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_accelerator_vr_position_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_drive_status_regen_vr_position_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_regen_vr_position_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_regen_vr_position_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_drive_status_digital_sw_position_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_digital_sw_position_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_digital_sw_position_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint16_t motor_controller_motor_controller_drive_status_output_target_value_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_output_target_value_decode(uint16_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_output_target_value_is_in_range(uint16_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_drive_status_motor_status_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_motor_status_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_motor_status_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_drive_status_regen_status_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_drive_status_regen_status_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_drive_status_regen_status_is_in_range(uint8_t value);

/**
 * Pack message MotorControllerError.
 *
 * @param[out] dst_p Buffer to pack the message into.
 * @param[in] src_p Data to pack.
 * @param[in] size Size of dst_p.
 *
 * @return Size of packed data, or negative error code.
 */
int motor_controller_motor_controller_error_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_error_t *src_p,
    size_t size);

/**
 * Unpack message MotorControllerError.
 *
 * @param[out] dst_p Object to unpack the message into.
 * @param[in] src_p Message to unpack.
 * @param[in] size Size of src_p.
 *
 * @return zero(0) or negative error code.
 */
int motor_controller_motor_controller_error_unpack(
    struct motor_controller_motor_controller_error_t *dst_p,
    const uint8_t *src_p,
    size_t size);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_analog_sensor_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_analog_sensor_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_analog_sensor_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_motor_current_sensor_u_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_motor_current_sensor_u_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_motor_current_sensor_u_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_motor_current_sensor_w_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_motor_current_sensor_w_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_motor_current_sensor_w_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_fet_thermistor_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_fet_thermistor_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_fet_thermistor_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_battery_voltage_sensor_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_battery_voltage_sensor_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_battery_voltage_sensor_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_battery_current_sensor_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_battery_current_sensor_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_battery_current_sensor_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_battery_current_sensor_adj_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_battery_current_sensor_adj_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_battery_current_sensor_adj_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_motor_current_sensor_adj_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_motor_current_sensor_adj_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_motor_current_sensor_adj_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_accelerator_position_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_accelerator_position_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_accelerator_position_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_controller_voltage_sensor_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_controller_voltage_sensor_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_controller_voltage_sensor_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_power_system_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_power_system_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_power_system_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_overcurrent_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_overcurrent_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_overcurrent_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_overvoltage_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_overvoltage_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_overvoltage_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_overcurrent_limit_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_overcurrent_limit_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_overcurrent_limit_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_motor_system_err_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_motor_system_err_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_motor_system_err_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_motor_lock_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_motor_lock_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_motor_lock_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_hall_sensor_short_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_hall_sensor_short_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_hall_sensor_short_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_hall_sensor_open_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_hall_sensor_open_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_hall_sensor_open_is_in_range(uint8_t value);

/**
 * Encode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to encode.
 *
 * @return Encoded signal.
 */
uint8_t motor_controller_motor_controller_error_overheat_level_encode(double value);

/**
 * Decode given signal by applying scaling and offset.
 *
 * @param[in] value Signal to decode.
 *
 * @return Decoded signal.
 */
double motor_controller_motor_controller_error_overheat_level_decode(uint8_t value);

/**
 * Check that given signal is in allowed range.
 *
 * @param[in] value Signal to check.
 *
 * @return true if in range, false otherwise.
 */
bool motor_controller_motor_controller_error_overheat_level_is_in_range(uint8_t value);


#ifdef __cplusplus
}
#endif

#endif
