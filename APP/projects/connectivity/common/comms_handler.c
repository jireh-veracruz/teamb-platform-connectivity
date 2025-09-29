/*
 *
 * 
 */

#include "common.h"
#include "handshake.h"
#include "comms.h"
#include "comms_msgs.h"


char msg_recv = COMMON_MSG_NONE;
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
    handshake_receive_data(0, &msg_recv);
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




}