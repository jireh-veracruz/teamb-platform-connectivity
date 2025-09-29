#ifndef __HAL_COMMS_H__
#define __HAL_COMMS_H__


int init_hal_comms(void);
int hal_set_comms_device_id(int device_id);
int hal_send_msg_from_comms(char* databuff, int len);
int hal_recv_msg_from_comms(char* buff, int len);
int deinit_hal_comms(void);



#endif //__HAL_COMMS_H__