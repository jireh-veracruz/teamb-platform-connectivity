#ifndef __HAL_COMMS_H__
#define __HAL_COMMS_H__


void hal_init(void);
void hal_service(void);
void hal_receive_data(char* data, int len);
int hal_send_data(char* data, int len);
int hal_device_ready(void);
void hal_deinit(void);
int hal_register_device(void* device);



#endif //__HAL_COMMS_H__