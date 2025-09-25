
#include "log.h"
#include "common.h"

int g_log_level = LOG_LVL_WARNING;

void init_log(void)
{

}

int log_write(char* data)
{

    return SUCCESS;
}

int log_set_level(int level)
{
    return SUCCESS;
}

void log_service(void)
{
    //handling for delicate devices
    //like uart where you cannot push all data 
    //at once, will cause delay

    //more critical if eeprom , you need block
    //writting and will probably take 1 sec
    //to complete cycle.

    
}