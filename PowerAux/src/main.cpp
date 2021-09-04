#include <mbed.h>
#include <rtos.h>
#include "pindef.h"
#include "Printing.h"
#include "PowerAuxCANParser.h"
#include "CANInterface.h"

#define TESTING     // only defined if using test functions
// #define DEBUGGING   // only define if debugging

#define MAIN_LOOP_PERIOD 1s
#define CAN_PERIOD 1s

BufferedSerial device(USBTX, USBRX);

Mutex main_printing_mutex;

PowerAuxCANParser bms_can_parser;
PowerAuxCANParser vehicle_can_parser;
CANInterface bms_can_interface(CAN_RX, CAN_TX, bms_can_parser, CAN_STBY, CAN_PERIOD);
CANInterface vehicle_can_interface(CAN2_RX, CAN2_TX, vehicle_can_parser, CAN2_STBY, CAN_PERIOD);

int main() {
    // device.set_baud(38400);
    
    init_printing(&main_printing_mutex);

#ifdef TESTING
    PRINT("start main() \r\n");
#endif //TESTING
    
    bms_can_interface.start_CAN_transmission();
    vehicle_can_interface.start_CAN_transmission();

    while(1){
        #ifdef TESTING
            PRINT("main thread loop \r\n");
        #endif //TESTING

        bms_can_parser.powerAuxExampleStruct.a++;
        bms_can_parser.powerAuxExampleStruct.b += 2;
        bms_can_parser.powerAuxExampleStruct.c += 3;
        bms_can_parser.powerAuxExampleStruct.d += 4;

        ThisThread::sleep_for(MAIN_LOOP_PERIOD);
    }
}
