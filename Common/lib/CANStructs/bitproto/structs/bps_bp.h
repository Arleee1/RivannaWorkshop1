// Code generated by bitproto. DO NOT EDIT.

#ifndef __BITPROTO__BPS_H__
#define __BITPROTO__BPS_H__ 1

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

// Number of bytes to encode struct BitprotoBPSPackInformation
#define BYTES_LENGTH_BITPROTO_BPS_PACK_INFORMATION 6

struct BitprotoBPSPackInformation {
    uint16_t pack_voltage; // 16bit
    uint16_t pack_current; // 16bit
    uint8_t pack_soc; // 8bit
    bool discharge_relay; // 1bit
    bool charge_relay; // 1bit
};

// Number of bytes to encode struct BitprotoBPSError
#define BYTES_LENGTH_BITPROTO_BPS_ERROR 3

struct BitprotoBPSError {
    bool internal_communications_fault; // 1bit
    bool internal_conversion_fault; // 1bit
    bool weak_cell_fault; // 1bit
    bool low_cell_voltage_fault; // 1bit
    bool open_wiring_fault; // 1bit
    bool current_sensor_fault; // 1bit
    bool pack_voltage_sensor_fault; // 1bit
    bool weak_pack_fault; // 1bit
    bool voltage_redundancy_fault; // 1bit
    bool fan_monitor_fault; // 1bit
    bool thermistor_fault; // 1bit
    bool CANBUS_communications_fault; // 1bit
    bool always_on_supply_fault; // 1bit
    bool high_voltage_isolation_fault; // 1bit
    bool power_supply_12v_fault; // 1bit
    bool charge_limit_enforcement_fault; // 1bit
    bool discharge_limit_enforcement_fault; // 1bit
    bool charger_safety_relay_fault; // 1bit
    bool internal_memory_fault; // 1bit
    bool internal_thermistor_fault; // 1bit
    bool internal_logic_fault; // 1bit
};

// Number of bytes to encode struct BitprotoBPSCellVoltage
#define BYTES_LENGTH_BITPROTO_BPS_CELL_VOLTAGE 6

struct BitprotoBPSCellVoltage {
    uint16_t low_cell_voltage; // 16bit
    uint8_t low_cell_voltage_id; // 8bit
    uint16_t high_cell_voltage; // 16bit
    uint8_t high_cell_voltage_id; // 8bit
};

// Number of bytes to encode struct BitprotoBPSCellTemperature
#define BYTES_LENGTH_BITPROTO_BPS_CELL_TEMPERATURE 4

struct BitprotoBPSCellTemperature {
    uint8_t low_temperature; // 8bit
    uint8_t low_thermistor_id; // 8bit
    uint8_t high_temperature; // 8bit
    uint8_t high_thermistor_id; // 8bit
};

// Encode struct BitprotoBPSPackInformation to given buffer s.
int EncodeBitprotoBPSPackInformation(struct BitprotoBPSPackInformation *m, unsigned char *s);
// Decode struct BitprotoBPSPackInformation from given buffer s.
int DecodeBitprotoBPSPackInformation(struct BitprotoBPSPackInformation *m, unsigned char *s);
// Format struct BitprotoBPSPackInformation to a json format string.
int JsonBitprotoBPSPackInformation(struct BitprotoBPSPackInformation *m, char *s);

// Encode struct BitprotoBPSError to given buffer s.
int EncodeBitprotoBPSError(struct BitprotoBPSError *m, unsigned char *s);
// Decode struct BitprotoBPSError from given buffer s.
int DecodeBitprotoBPSError(struct BitprotoBPSError *m, unsigned char *s);
// Format struct BitprotoBPSError to a json format string.
int JsonBitprotoBPSError(struct BitprotoBPSError *m, char *s);

// Encode struct BitprotoBPSCellVoltage to given buffer s.
int EncodeBitprotoBPSCellVoltage(struct BitprotoBPSCellVoltage *m, unsigned char *s);
// Decode struct BitprotoBPSCellVoltage from given buffer s.
int DecodeBitprotoBPSCellVoltage(struct BitprotoBPSCellVoltage *m, unsigned char *s);
// Format struct BitprotoBPSCellVoltage to a json format string.
int JsonBitprotoBPSCellVoltage(struct BitprotoBPSCellVoltage *m, char *s);

// Encode struct BitprotoBPSCellTemperature to given buffer s.
int EncodeBitprotoBPSCellTemperature(struct BitprotoBPSCellTemperature *m, unsigned char *s);
// Decode struct BitprotoBPSCellTemperature from given buffer s.
int DecodeBitprotoBPSCellTemperature(struct BitprotoBPSCellTemperature *m, unsigned char *s);
// Format struct BitprotoBPSCellTemperature to a json format string.
int JsonBitprotoBPSCellTemperature(struct BitprotoBPSCellTemperature *m, char *s);

void BpXXXProcessBitprotoBPSPackInformation(void *data, struct BpProcessorContext *ctx);
void BpXXXJsonFormatBitprotoBPSPackInformation(void *data, struct BpJsonFormatContext *ctx);

void BpXXXProcessBitprotoBPSError(void *data, struct BpProcessorContext *ctx);
void BpXXXJsonFormatBitprotoBPSError(void *data, struct BpJsonFormatContext *ctx);

void BpXXXProcessBitprotoBPSCellVoltage(void *data, struct BpProcessorContext *ctx);
void BpXXXJsonFormatBitprotoBPSCellVoltage(void *data, struct BpJsonFormatContext *ctx);

void BpXXXProcessBitprotoBPSCellTemperature(void *data, struct BpProcessorContext *ctx);
void BpXXXJsonFormatBitprotoBPSCellTemperature(void *data, struct BpJsonFormatContext *ctx);

#if defined(__cplusplus)
}
#endif

#endif