/*
 * Copyright (c) 2025, Team B
 * All rights reserved.
 */

#ifndef __APP_H__
#define __APP_H__

//device status 
#define DEV_STAT_UNKNOWN                    0
#define DEV_STAT_IDLE                       1
#define DEV_STAT_COMM_ACTIVE                2
#define DEV_STAT_COMM_INACTIVE              3
#define DEV_STAT_COMM_ERROR                 4
#define DEV_STAT_SERVER_ACTIVE              5
#define DEV_STAT_SERVER_INACTIVE            6
#define DEV_STAT_SERVER_ERROR               7
#define DEV_STAT_DEVICE_ERROR               8

void setup_connect_app(void);
void connect_app(void);



#endif //__APP_H__