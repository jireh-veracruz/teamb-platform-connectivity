/*
 *
 * 
 */

#include "common.h"
#include "handshake.h"
#include "comms.h"
#include "comms_msgs.h"


//NOTE: no while loop inside app
int connectivity_comms_handler(char* data, int len)
{
    //comms message handler
    handshake_receive_data(data, 1);
    switch(data[0])
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

    return data[1];
}