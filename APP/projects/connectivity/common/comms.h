#ifndef __COMMS_H__
#define __COMMS_H__


int connectivity_comms_input(char* data, int len);
int connectivity_comms_handler(char* data, int len);
int connectivity_comms_output(char* data, int len)



#define DEV_STAT_UNKNOWN                0
#define DEV_STAT_IDLE                   1
#define DEV_STAT_BUSY                   2
#define DEV_STAT_MSG_PROC               3
#define DEV_STAT_ERROR                  4
#define DEV_STAT_WAITNG                 5

#define CONN_MAX_MSG_BUFF               10


#endif //__COMMS_H__