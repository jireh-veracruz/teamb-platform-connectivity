/*
 *  This may be just a simple wrapper for actual
 *      comms handler which is also abstract to 
 *      whatever device they want to comms with 
 *      pcb peripherals
 * 
 */



#include "hal_comms.h"
#include "common.h"


int init_hal_comms(void)
{
    return -1;
}

int hal_set_comms_device_id(int device_id)
{
    return -1;
}

int hal_send_msg_from_comms(char* databuff, int len)
{
    return -1;
}

int hal_recv_msg_from_comms(char* buff, int len)
{
    return -1;
}

int deinit_hal_comms(void)
{
    return -1;
}