/*
 *
 * 
 */

#include "common.h"
#include "comms.h"
#include "comms_msgs.h"


int msg_recv = MSG_NONE;
int status_device = 0;


void setup_connect_app(void)
{
    //init variables and device here!!!
}

//NOTE: no while loop inside app
void connect_app(void)
{
    
    //input handler - wait do we have pushbotton or keyboard???

    //comms message handler
    handshake_receive_data(&msg_recv);
    switch(msg_recv)
    {
        case MSG_NONE:
            break;
        case MSG_HI:
            break;
        case MSG_HELLO:
            break;
        case MSG_BROADCAST:
            break;
        case MSG_ID_DESTI:
            break;
        case MSG_RAND_HOLD:
            break;
        case MSG_READ:
            break;
        case MSG_WRITE:
            break;
        case MSG_CMD:
            break;
        default:
            ;   //do nothing !!!
    }




}