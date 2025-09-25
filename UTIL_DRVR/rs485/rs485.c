
#include "rs485.h"


int rs485_init(void)
{

}

int rs485_write_to_bus(const char *msg, int device_id)
{
    RS485_WRITE(device_id);
    RS485_WRITE(msg);
}

int rs485_read_from_bus(char *buffer, int device_id)
{
    RS485_READ(RS485_READ);
    RS485_READ(buffer);

    return buffer;
}

int rs485_clear_bus(void)
{

}

void rs485_device_communicate(int device_id)
{

}
