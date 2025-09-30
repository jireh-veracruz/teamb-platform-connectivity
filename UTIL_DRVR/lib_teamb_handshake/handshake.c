
#include "handshake.h"
#include "common.h"

#include "hal_comms.h"

int flag_is_device_communicating = NO;




void init_handshake(void)
{

}

void teamb_handshake_service(void)
{
    //wait for activity

    //if need to send, check collision detection first

    //if waiting for data, loop the targt bus

    //handler of service 

    hal_service();
}

void teamb_handshake_receive_data(char* data, int len)
{
    char buff[MAX_BUFF_SIZE];

    hal_receive_data(buff, 1);
    if(buff == 0xFF)
    {
        //do something
    }
}

int teamb_handshake_send_data(char* data, int len)
{
    hal_send_data(data, 1);
}

int teamb_handshake_device_ready(void)
{
    return hal_device_ready();
}

void teamb_deinit_handshake(void)
{

}

int teamb_register_device_handshake(void* device)
{

}