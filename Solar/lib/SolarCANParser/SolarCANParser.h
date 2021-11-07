#ifndef SOLAR_CAN_PARSER_H
#define SOLAR_CAN_PARSER_H
#include <mbed.h>

#include "CANParser.h"
#include "PowerAuxCANStructs.h"

class SolarCANParser : public CANParser {
    public:
    void parse(const CANMessage &msg) override;
    queue<CANMessage> *get_messages() override;
    
    void push_power_aux_example_struct(PowerAuxExampleStruct *example_struct);
private:
    queue<CANMessage> messages;
};


#endif