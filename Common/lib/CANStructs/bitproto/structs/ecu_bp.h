// Code generated by bitproto. DO NOT EDIT.

#ifndef __BITPROTO__ECU_H__
#define __BITPROTO__ECU_H__ 1

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

#include "bitproto.h"

#if defined(__cplusplus)
extern "C" {
#endif

// Number of bytes to encode struct BitprotoECUMotorCommands
#define BYTES_LENGTH_BITPROTO_ECU_MOTOR_COMMANDS 4

struct BitprotoECUMotorCommands {
    uint8_t throttle; // 8bit
    uint8_t regen; // 8bit
    bool forward_en; // 1bit
    bool reverse_en; // 1bit
    bool cruise_control_en; // 1bit
    uint8_t cruise_control_speed; // 8bit
    bool motor_on; // 1bit
};

// Number of bytes to encode struct BitprotoECUPowerAuxCommands
#define BYTES_LENGTH_BITPROTO_ECU_POWER_AUX_COMMANDS 1

struct BitprotoECUPowerAuxCommands {
    bool hazards; // 1bit
    bool brake_lights; // 1bit
    bool headlights; // 1bit
    bool left_turn_signal; // 1bit
    bool right_turn_signal; // 1bit
};

// Encode struct BitprotoECUMotorCommands to given buffer s.
int EncodeBitprotoECUMotorCommands(struct BitprotoECUMotorCommands *m, unsigned char *s);
// Decode struct BitprotoECUMotorCommands from given buffer s.
int DecodeBitprotoECUMotorCommands(struct BitprotoECUMotorCommands *m, unsigned char *s);
// Format struct BitprotoECUMotorCommands to a json format string.
int JsonBitprotoECUMotorCommands(struct BitprotoECUMotorCommands *m, char *s);

// Encode struct BitprotoECUPowerAuxCommands to given buffer s.
int EncodeBitprotoECUPowerAuxCommands(struct BitprotoECUPowerAuxCommands *m, unsigned char *s);
// Decode struct BitprotoECUPowerAuxCommands from given buffer s.
int DecodeBitprotoECUPowerAuxCommands(struct BitprotoECUPowerAuxCommands *m, unsigned char *s);
// Format struct BitprotoECUPowerAuxCommands to a json format string.
int JsonBitprotoECUPowerAuxCommands(struct BitprotoECUPowerAuxCommands *m, char *s);

void BpXXXProcessBitprotoECUMotorCommands(void *data, struct BpProcessorContext *ctx);
void BpXXXJsonFormatBitprotoECUMotorCommands(void *data, struct BpJsonFormatContext *ctx);

void BpXXXProcessBitprotoECUPowerAuxCommands(void *data, struct BpProcessorContext *ctx);
void BpXXXJsonFormatBitprotoECUPowerAuxCommands(void *data, struct BpJsonFormatContext *ctx);

#if defined(__cplusplus)
}
#endif

#endif