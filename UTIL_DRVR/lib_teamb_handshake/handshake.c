
#include "handshake.h"
#include "common.h"

int flag_is_device_communicating = NO;


int (*handshake_send_data)(int destination, int buffer) =  NULL;
int (*handshake_receive_data)(int destination, int buffer) =  NULL;
int (*handshake_comms_ready)(void) = NULL;

void init_handshake(void)
{
    handshake_send_data = CAN_SEND;
    handshake_receive_data = CAN_RECV;
    handshake_comms_ready = CAN_READY;
}

void handshake_service(void)
{
    //wait for activity

    //if need to send, check collision detection first

    //if waiting for data, loop the targt bus

    //handler of service 
}

void handshake_receive_data(char* buff)
{
    char buff[MAX_BUFF_SIZE];

    if(handshake_receive_data(buff, 0))
    {
        //do something
    }
}

int handshake_send_data(char* data, int len)
{
    handshake_send_data(handshake_send_data, 0);
}

int handshake_device_ready(void)
{
    return handshake_comms_ready();
}

void deinit_handshake(void)
{

}

int register_device_handshake(void* device)
{

}