/*
 *  Connectivity PCB
 *  the goal of this project is create a peripheral
 *  that will facilitate the connection to the
 *  cloud server, we have multiple options, it can be
 *  CAN protocol or RS485 bus connected to other 
 *  peripherals in the system
 *  
 *  from here, once we capture the data and apply the
 *  appropriate condition like, need to summarize the
 *  data or of sending to cloud failed, it should
 *  be stored in sdcard or eeprom
 * 
 */

#include "common.h"
#include "handshake.h"
#include "comms_data.h"

#define SERVER_IP           "8.8.8.8"
#define USERNAME            "kermithcute"
#define PASSWORD            "123456"

char msg_recv = MSG_NONE;
int status_device = 

void establish_connectivity_to_server(void)
{

}


void connect_setup_app(void)
{
    //init_devices()
    //init_peripherals();
}

//NOTE: no while loop inside app
void connect_app(void)
{
    
    //input handler - wait do we have pushbotton or keyboard???

    //comms message handler
    handshake_receive_data(&msg_recv);
    switch(msg_recv)
    {
        case COMMON_MSG_NONE:
            break;
        case COMMON_MSG_HI:
            break;
        case COMMON_MSG_HELLO:
            break;
        case COMMON_MSG_BROADCAST:
            break;
        case COMMON_MSG_ID_DESTI:
            break;
        case COMMON_MSG_RAND_HOLD:
            break;
        case COMMON_MSG_READ:
            break;
        case COMMON_MSG_WRITE:
            break;
        case COMMON_MSG_CMD:
            break;
        default:
            ;   //do nothing !!!
    }


    //process what to do with the input

    //output - execute the planned outcome from
    // process


    

    handshake_service();
}