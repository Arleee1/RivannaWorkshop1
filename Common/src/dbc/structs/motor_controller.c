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
 * This file was generated by cantools version 37.0.7 Sun Jun 19 20:24:38 2022.
 */

#include <string.h>

#include "motor_controller.h"

static inline uint8_t pack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_left_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value << shift) & mask);
}

static inline uint8_t pack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t pack_right_shift_u16(
    uint16_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value >> shift) & mask);
}

static inline uint8_t unpack_left_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) << shift);
}

static inline uint16_t unpack_left_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) << shift);
}

static inline uint8_t unpack_right_shift_u8(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint8_t)((uint8_t)(value & mask) >> shift);
}

static inline uint16_t unpack_right_shift_u16(
    uint8_t value,
    uint8_t shift,
    uint8_t mask)
{
    return (uint16_t)((uint16_t)(value & mask) >> shift);
}

int motor_controller_motor_controller_frame_request_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_frame_request_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 1);

    dst_p[0] |= pack_left_shift_u8(src_p->power_status_frame, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->drive_status_frame, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->error_frame, 2u, 0x04u);

    return (1);
}

int motor_controller_motor_controller_frame_request_unpack(
    struct motor_controller_motor_controller_frame_request_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 1u) {
        return (-EINVAL);
    }

    dst_p->power_status_frame = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->drive_status_frame = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->error_frame = unpack_right_shift_u8(src_p[0], 2u, 0x04u);

    return (0);
}

uint8_t motor_controller_motor_controller_frame_request_power_status_frame_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_frame_request_power_status_frame_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_frame_request_power_status_frame_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_frame_request_drive_status_frame_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_frame_request_drive_status_frame_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_frame_request_drive_status_frame_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_frame_request_error_frame_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_frame_request_error_frame_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_frame_request_error_frame_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int motor_controller_motor_controller_power_status_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_power_status_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 8);

    dst_p[0] |= pack_left_shift_u16(src_p->battery_voltage, 0u, 0xffu);
    dst_p[1] |= pack_right_shift_u16(src_p->battery_voltage, 8u, 0x03u);
    dst_p[1] |= pack_left_shift_u16(src_p->battery_current, 2u, 0xfcu);
    dst_p[2] |= pack_right_shift_u16(src_p->battery_current, 6u, 0x07u);
    dst_p[2] |= pack_left_shift_u8(src_p->battery_current_direction, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u16(src_p->motor_current, 4u, 0xf0u);
    dst_p[3] |= pack_right_shift_u16(src_p->motor_current, 4u, 0x3fu);
    dst_p[3] |= pack_left_shift_u8(src_p->fet_temp, 6u, 0xc0u);
    dst_p[4] |= pack_right_shift_u8(src_p->fet_temp, 2u, 0x07u);
    dst_p[4] |= pack_left_shift_u16(src_p->motor_rpm, 3u, 0xf8u);
    dst_p[5] |= pack_right_shift_u16(src_p->motor_rpm, 5u, 0x7fu);
    dst_p[5] |= pack_left_shift_u16(src_p->pwm_duty, 7u, 0x80u);
    dst_p[6] |= pack_right_shift_u16(src_p->pwm_duty, 1u, 0xffu);
    dst_p[7] |= pack_right_shift_u16(src_p->pwm_duty, 9u, 0x01u);
    dst_p[7] |= pack_left_shift_u8(src_p->lead_angle, 1u, 0xfeu);

    return (8);
}

int motor_controller_motor_controller_power_status_unpack(
    struct motor_controller_motor_controller_power_status_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 8u) {
        return (-EINVAL);
    }

    dst_p->battery_voltage = unpack_right_shift_u16(src_p[0], 0u, 0xffu);
    dst_p->battery_voltage |= unpack_left_shift_u16(src_p[1], 8u, 0x03u);
    dst_p->battery_current = unpack_right_shift_u16(src_p[1], 2u, 0xfcu);
    dst_p->battery_current |= unpack_left_shift_u16(src_p[2], 6u, 0x07u);
    dst_p->battery_current_direction = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->motor_current = unpack_right_shift_u16(src_p[2], 4u, 0xf0u);
    dst_p->motor_current |= unpack_left_shift_u16(src_p[3], 4u, 0x3fu);
    dst_p->fet_temp = unpack_right_shift_u8(src_p[3], 6u, 0xc0u);
    dst_p->fet_temp |= unpack_left_shift_u8(src_p[4], 2u, 0x07u);
    dst_p->motor_rpm = unpack_right_shift_u16(src_p[4], 3u, 0xf8u);
    dst_p->motor_rpm |= unpack_left_shift_u16(src_p[5], 5u, 0x7fu);
    dst_p->pwm_duty = unpack_right_shift_u16(src_p[5], 7u, 0x80u);
    dst_p->pwm_duty |= unpack_left_shift_u16(src_p[6], 1u, 0xffu);
    dst_p->pwm_duty |= unpack_left_shift_u16(src_p[7], 9u, 0x01u);
    dst_p->lead_angle = unpack_right_shift_u8(src_p[7], 1u, 0xfeu);

    return (0);
}

uint16_t motor_controller_motor_controller_power_status_battery_voltage_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_power_status_battery_voltage_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_battery_voltage_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t motor_controller_motor_controller_power_status_battery_current_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_power_status_battery_current_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_battery_current_is_in_range(uint16_t value)
{
    return (value <= 511u);
}

uint8_t motor_controller_motor_controller_power_status_battery_current_direction_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_power_status_battery_current_direction_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_battery_current_direction_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint16_t motor_controller_motor_controller_power_status_motor_current_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_power_status_motor_current_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_motor_current_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint8_t motor_controller_motor_controller_power_status_fet_temp_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_power_status_fet_temp_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_fet_temp_is_in_range(uint8_t value)
{
    return (value <= 31u);
}

uint16_t motor_controller_motor_controller_power_status_motor_rpm_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_power_status_motor_rpm_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_motor_rpm_is_in_range(uint16_t value)
{
    return (value <= 4095u);
}

uint16_t motor_controller_motor_controller_power_status_pwm_duty_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_power_status_pwm_duty_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_pwm_duty_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint8_t motor_controller_motor_controller_power_status_lead_angle_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_power_status_lead_angle_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_power_status_lead_angle_is_in_range(uint8_t value)
{
    return (value <= 127u);
}

int motor_controller_motor_controller_drive_status_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_drive_status_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5);

    dst_p[0] |= pack_left_shift_u8(src_p->power_mode, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->control_mode, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u16(src_p->accelerator_vr_position, 2u, 0xfcu);
    dst_p[1] |= pack_right_shift_u16(src_p->accelerator_vr_position, 6u, 0x0fu);
    dst_p[1] |= pack_left_shift_u16(src_p->regen_vr_position, 4u, 0xf0u);
    dst_p[2] |= pack_right_shift_u16(src_p->regen_vr_position, 4u, 0x3fu);
    dst_p[2] |= pack_left_shift_u8(src_p->digital_sw_position, 6u, 0xc0u);
    dst_p[3] |= pack_right_shift_u8(src_p->digital_sw_position, 2u, 0x03u);
    dst_p[3] |= pack_left_shift_u16(src_p->output_target_value, 2u, 0xfcu);
    dst_p[4] |= pack_right_shift_u16(src_p->output_target_value, 6u, 0x0fu);
    dst_p[4] |= pack_left_shift_u8(src_p->motor_status, 4u, 0x30u);
    dst_p[4] |= pack_left_shift_u8(src_p->regen_status, 6u, 0x40u);

    return (5);
}

int motor_controller_motor_controller_drive_status_unpack(
    struct motor_controller_motor_controller_drive_status_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    dst_p->power_mode = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->control_mode = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->accelerator_vr_position = unpack_right_shift_u16(src_p[0], 2u, 0xfcu);
    dst_p->accelerator_vr_position |= unpack_left_shift_u16(src_p[1], 6u, 0x0fu);
    dst_p->regen_vr_position = unpack_right_shift_u16(src_p[1], 4u, 0xf0u);
    dst_p->regen_vr_position |= unpack_left_shift_u16(src_p[2], 4u, 0x3fu);
    dst_p->digital_sw_position = unpack_right_shift_u8(src_p[2], 6u, 0xc0u);
    dst_p->digital_sw_position |= unpack_left_shift_u8(src_p[3], 2u, 0x03u);
    dst_p->output_target_value = unpack_right_shift_u16(src_p[3], 2u, 0xfcu);
    dst_p->output_target_value |= unpack_left_shift_u16(src_p[4], 6u, 0x0fu);
    dst_p->motor_status = unpack_right_shift_u8(src_p[4], 4u, 0x30u);
    dst_p->regen_status = unpack_right_shift_u8(src_p[4], 6u, 0x40u);

    return (0);
}

uint8_t motor_controller_motor_controller_drive_status_power_mode_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_drive_status_power_mode_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_power_mode_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_drive_status_control_mode_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_drive_status_control_mode_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_control_mode_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint16_t motor_controller_motor_controller_drive_status_accelerator_vr_position_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_drive_status_accelerator_vr_position_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_accelerator_vr_position_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint16_t motor_controller_motor_controller_drive_status_regen_vr_position_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_drive_status_regen_vr_position_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_regen_vr_position_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint8_t motor_controller_motor_controller_drive_status_digital_sw_position_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_drive_status_digital_sw_position_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_digital_sw_position_is_in_range(uint8_t value)
{
    return (value <= 15u);
}

uint16_t motor_controller_motor_controller_drive_status_output_target_value_encode(double value)
{
    return (uint16_t)(value);
}

double motor_controller_motor_controller_drive_status_output_target_value_decode(uint16_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_output_target_value_is_in_range(uint16_t value)
{
    return (value <= 1023u);
}

uint8_t motor_controller_motor_controller_drive_status_motor_status_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_drive_status_motor_status_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_motor_status_is_in_range(uint8_t value)
{
    return (value <= 3u);
}

uint8_t motor_controller_motor_controller_drive_status_regen_status_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_drive_status_regen_status_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_drive_status_regen_status_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

int motor_controller_motor_controller_error_pack(
    uint8_t *dst_p,
    const struct motor_controller_motor_controller_error_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    memset(&dst_p[0], 0, 5);

    dst_p[0] |= pack_left_shift_u8(src_p->analog_sensor_err, 0u, 0x01u);
    dst_p[0] |= pack_left_shift_u8(src_p->motor_current_sensor_u_err, 1u, 0x02u);
    dst_p[0] |= pack_left_shift_u8(src_p->motor_current_sensor_w_err, 2u, 0x04u);
    dst_p[0] |= pack_left_shift_u8(src_p->fet_thermistor_err, 3u, 0x08u);
    dst_p[0] |= pack_left_shift_u8(src_p->battery_voltage_sensor_err, 5u, 0x20u);
    dst_p[0] |= pack_left_shift_u8(src_p->battery_current_sensor_err, 6u, 0x40u);
    dst_p[0] |= pack_left_shift_u8(src_p->battery_current_sensor_adj_err, 7u, 0x80u);
    dst_p[1] |= pack_left_shift_u8(src_p->motor_current_sensor_adj_err, 0u, 0x01u);
    dst_p[1] |= pack_left_shift_u8(src_p->accelerator_position_err, 1u, 0x02u);
    dst_p[1] |= pack_left_shift_u8(src_p->controller_voltage_sensor_err, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->power_system_err, 0u, 0x01u);
    dst_p[2] |= pack_left_shift_u8(src_p->overcurrent_err, 1u, 0x02u);
    dst_p[2] |= pack_left_shift_u8(src_p->overvoltage_err, 3u, 0x08u);
    dst_p[2] |= pack_left_shift_u8(src_p->overcurrent_limit, 5u, 0x20u);
    dst_p[3] |= pack_left_shift_u8(src_p->motor_system_err, 0u, 0x01u);
    dst_p[3] |= pack_left_shift_u8(src_p->motor_lock, 1u, 0x02u);
    dst_p[3] |= pack_left_shift_u8(src_p->hall_sensor_short, 2u, 0x04u);
    dst_p[3] |= pack_left_shift_u8(src_p->hall_sensor_open, 3u, 0x08u);
    dst_p[4] |= pack_left_shift_u8(src_p->overheat_level, 0u, 0x03u);

    return (5);
}

int motor_controller_motor_controller_error_unpack(
    struct motor_controller_motor_controller_error_t *dst_p,
    const uint8_t *src_p,
    size_t size)
{
    if (size < 5u) {
        return (-EINVAL);
    }

    dst_p->analog_sensor_err = unpack_right_shift_u8(src_p[0], 0u, 0x01u);
    dst_p->motor_current_sensor_u_err = unpack_right_shift_u8(src_p[0], 1u, 0x02u);
    dst_p->motor_current_sensor_w_err = unpack_right_shift_u8(src_p[0], 2u, 0x04u);
    dst_p->fet_thermistor_err = unpack_right_shift_u8(src_p[0], 3u, 0x08u);
    dst_p->battery_voltage_sensor_err = unpack_right_shift_u8(src_p[0], 5u, 0x20u);
    dst_p->battery_current_sensor_err = unpack_right_shift_u8(src_p[0], 6u, 0x40u);
    dst_p->battery_current_sensor_adj_err = unpack_right_shift_u8(src_p[0], 7u, 0x80u);
    dst_p->motor_current_sensor_adj_err = unpack_right_shift_u8(src_p[1], 0u, 0x01u);
    dst_p->accelerator_position_err = unpack_right_shift_u8(src_p[1], 1u, 0x02u);
    dst_p->controller_voltage_sensor_err = unpack_right_shift_u8(src_p[1], 3u, 0x08u);
    dst_p->power_system_err = unpack_right_shift_u8(src_p[2], 0u, 0x01u);
    dst_p->overcurrent_err = unpack_right_shift_u8(src_p[2], 1u, 0x02u);
    dst_p->overvoltage_err = unpack_right_shift_u8(src_p[2], 3u, 0x08u);
    dst_p->overcurrent_limit = unpack_right_shift_u8(src_p[2], 5u, 0x20u);
    dst_p->motor_system_err = unpack_right_shift_u8(src_p[3], 0u, 0x01u);
    dst_p->motor_lock = unpack_right_shift_u8(src_p[3], 1u, 0x02u);
    dst_p->hall_sensor_short = unpack_right_shift_u8(src_p[3], 2u, 0x04u);
    dst_p->hall_sensor_open = unpack_right_shift_u8(src_p[3], 3u, 0x08u);
    dst_p->overheat_level = unpack_right_shift_u8(src_p[4], 0u, 0x03u);

    return (0);
}

uint8_t motor_controller_motor_controller_error_analog_sensor_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_analog_sensor_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_analog_sensor_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_motor_current_sensor_u_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_motor_current_sensor_u_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_motor_current_sensor_u_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_motor_current_sensor_w_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_motor_current_sensor_w_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_motor_current_sensor_w_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_fet_thermistor_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_fet_thermistor_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_fet_thermistor_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_battery_voltage_sensor_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_battery_voltage_sensor_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_battery_voltage_sensor_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_battery_current_sensor_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_battery_current_sensor_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_battery_current_sensor_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_battery_current_sensor_adj_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_battery_current_sensor_adj_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_battery_current_sensor_adj_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_motor_current_sensor_adj_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_motor_current_sensor_adj_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_motor_current_sensor_adj_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_accelerator_position_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_accelerator_position_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_accelerator_position_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_controller_voltage_sensor_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_controller_voltage_sensor_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_controller_voltage_sensor_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_power_system_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_power_system_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_power_system_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_overcurrent_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_overcurrent_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_overcurrent_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_overvoltage_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_overvoltage_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_overvoltage_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_overcurrent_limit_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_overcurrent_limit_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_overcurrent_limit_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_motor_system_err_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_motor_system_err_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_motor_system_err_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_motor_lock_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_motor_lock_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_motor_lock_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_hall_sensor_short_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_hall_sensor_short_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_hall_sensor_short_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_hall_sensor_open_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_hall_sensor_open_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_hall_sensor_open_is_in_range(uint8_t value)
{
    return (value <= 1u);
}

uint8_t motor_controller_motor_controller_error_overheat_level_encode(double value)
{
    return (uint8_t)(value);
}

double motor_controller_motor_controller_error_overheat_level_decode(uint8_t value)
{
    return ((double)value);
}

bool motor_controller_motor_controller_error_overheat_level_is_in_range(uint8_t value)
{
    return (value <= 3u);
}
