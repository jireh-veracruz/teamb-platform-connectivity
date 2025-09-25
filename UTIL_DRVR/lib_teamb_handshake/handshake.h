#ifndef __HANDSHAKE_H__
#define __HANDSHAKE_H__


#define DEV_STATUS_UNKNOWN              0
#define DEV_STATUS_IDLE                 1
#define DEV_STATUS_ACTIVE               2
#define DEV_STATUS_WAITING              3

#define MSG_PING                        0
#define MSG_PING_REPLY                  1
#define MSG_SEND_DAT                    2
#define MSG_RECV_DAT                    3
#define MSG_COMMAND                     4
#define MSG_ADDRESS                     5
#define MSG_DATA                        6
#define MSG_BROADCAST                   7


void init_handshake(void);
void handshake_service(void);
void handshake_receive_data(char* buff);
int handshake_send_data(char* data, int len);
void deinit_handshake(void);




#endif //__HANDSHAKE_H__