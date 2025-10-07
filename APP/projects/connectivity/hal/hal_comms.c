/*
 *  This may be just a simple wrapper for actual
 *      comms handler which is also abstract to 
 *      whatever device they want to comms with 
 *      pcb peripherals
 * 
 */



#include "hal_comms.h"
#include "common.h"


int (*hal_set_data_fptr)(int destination, int buffer) =  NULL;
int (*hal_get_data_fptr)(int destination, int buffer) =  NULL;
int (*hal_comms_ready_fptr)(void) = NULL;


void hal_init(void)
{
    hal_set_data_fptr = GENERIC_SEND;
    hal_get_data_fptr = GENERIC_RECV;
    hal_comms_ready_fptr = GENERIC_READY;

}

void hal_service(void)
{
    //do service routine
}

void hal_receive_data(char* data, int len)
{
    hal_get_data_fptr(data, len);
}

int hal_send_data(char* data, int len)
{
    return hal_set_data_fptr(data, len);
}

int hal_device_ready(void)
{
    return hal_comms_ready_fptr();
}

void hal_deinit(void)
{
    
}

int hal_register_device(void* device)
{
    return -1;
}


