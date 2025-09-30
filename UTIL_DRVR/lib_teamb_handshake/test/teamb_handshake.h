#ifndef __TEAMB_HANDSHAKEN_H__
#define __TEAMB_HANDSHAKEN_H__


#include "comms_msgs.h"


#define TEST_MAX_CTR            10

    //param1    len1        param2      len2        expected    actual
char* test_table[] = {
    0xAA,       0x0A,       0,          0,          0xA,        0xA,
    0xAA,       0x0B,       0,          0,          0xA,        0xA,
    0xAA,       0xBB,       0,          0,          0xA,        0xA,
    0xAA,       0xAB,       0,          0,          0xA,        0xA,
    0xAA,       0xBA,       0,          0,          0xA,        0xA,
    0xAA,       0xFE,       0,          0,          0xA,        0xA,
    0xAA,       0xEE,       0,          0,          0xA,        0xA,
    0xAA,       0xEA,       0,          0,          0xA,        0xA,
    0xAA,       0xBB,       0,          0,          0xA,        0xA,
    0xAA,       0xBB,       0,          0,          0xA,        0xA,
    0xAA,       0xBB,       0,          0,          0xA,        0xA,
    0xAA,       0xBB,       0,          0,          0xA,        0xA,
    0xAA,       0xBB,       0,          0,          0xA,        0xA,
};




#endif //__TEAMB_HANDSHAKEN_H__
