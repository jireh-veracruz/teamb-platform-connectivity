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
#include "comms_msgs.h"
#include "comms.h"

#define SERVER_IP           "8.8.8.8"
#define USERNAME            "kermithcute"
#define PASSWORD            "123456"

char msg_recv = COMMON_MSG_NONE;
int status_device = DEV_STAT_UNKNOWN;

char data_buffer[CONN_MAX_MSG_BUFF];
int returnvalue = 0;

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
    returnvalue = connectivity_comms_input(&data_buffer, 1);
    if(returnvalue == SUCCESS)
    {
        //do this!!!
    }

    //comms message handler
    returnvalue = connectivity_comms_handler(&data_buffer, 1);
    //process what to do with the input

    //output - execute the planned outcome from
    // process
    returnvalue = connectivity_comms_output(&data_buffer, 5);

    
    //service area
    teamb_handshake_service();
}