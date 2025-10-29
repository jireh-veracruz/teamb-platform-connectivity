/*
 * Copyright (c) 2025, Team B
 * All rights reserved.
 */

#include "comms_msgs.h"
#include "common.h"
#include "handshake.h"

// NOTE: no while loop inside app
int connectivity_comms_handler(char* data, int len) {
    (void)len;
    // comms message handler
    teamb_handshake_receive_data(data, 1);
    switch (data[0]) {
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
            break;  // do nothing !!!
    }

    return data[1];
}
