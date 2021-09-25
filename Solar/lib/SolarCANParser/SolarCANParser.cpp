#include "SolarCANParser.h"
#include "Printing.h"

void SolarCANParser::parse(const CANMessage& msg)
{
    uint8_t messagePriority = CAN_PRIORITY(msg.id);
    uint8_t messageNodeID = CAN_NODE_ID(msg.id);

    SolarExampleStruct example_struct;
    example_struct.deserialize(msg.data, msg.len);

    PRINT("[ID: %d] Data received: a=%u, b=%u, c=%u, d=%d\r\n", msg.id, example_struct.a, example_struct.b, example_struct.c, example_struct.d);
}

queue<CANMessage> *SolarCANParser::get_messages()
{
    return &messages;
}

void SolarCANParser::push_solar_example_struct(SolarExampleStruct *example_struct) {
    static int id = 0;
    if (++id == 10) {
        id = 0;
    }

    CANMessage message;
    message.id = id;
    example_struct->serialize(message.data, &(message.len));

    PRINT("[ID: %d] Data queued: a=%u, b=%u, c=%u, d=%d\r\n", id, example_struct->a, example_struct->b, example_struct->c, example_struct->d);

    messages.push(message);
}
