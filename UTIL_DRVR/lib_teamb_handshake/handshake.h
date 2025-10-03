#ifndef __HANDSHAKE_H__
#define __HANDSHAKE_H__


#define DEV_STATUS_UNKNOWN              0
#define DEV_STATUS_IDLE                 1
#define DEV_STATUS_ACTIVE               2
#define DEV_STATUS_WAITING              3

//change this to enum
#define HANDSHAKE_MSG_PING                        0
#define HANDSHAKE_MSG_PING_REPLY                  1
#define HANDSHAKE_MSG_SEND_DAT                    2
#define HANDSHAKE_MSG_RECV_DAT                    3
#define HANDSHAKE_MSG_COMMAND                     4
#define HANDSHAKE_MSG_ADDRESS                     5
#define HANDSHAKE_MSG_DATA                        6
#define HANDSHAKE_MSG_BROADCAST                   7

#define MAX_BUFF_SIZE                   10

// =======================
// Message Constants
// =======================
#define MSG_HANDSHAKE_INIT     "HELLO"
#define MSG_HANDSHAKE_ACK      "ACK"
#define MSG_DATA_READY         "DATA_READY"
#define MSG_DATA_RECEIVED      "DATA_RECEIVED"
#define MSG_ERROR_CORRUPT      "ERROR_CORRUPT"
#define MSG_ERROR_TIMEOUT      "ERROR_TIMEOUT"
#define MSG_COLLISION_DETECTED "COLLISION"
#define MSG_RETRY              "RETRY"
#define MSG_IDLE               "IDLE"


#if 0
int init_handshake(void);
void handshake_service(void);

void handshake_receive_data(int id, char* data);
int handshake_send_data(int id, char* data);

int handshake_send_handshake_request(int id);
int handshake_reply_to_handshake_request(int id);

int handshake_device_ready(void);
int deinit_handshake(void);
int register_device_handshake(void* device);
#endif

void init_handshake(void);
void teamb_handshake_service(void);
void teamb_handshake_receive_data(char* data, int len);
int teamb_handshake_send_data(char* data, int len);
int teamb_handshake_device_ready(void);
void teamb_deinit_handshake(void);
int teamb_register_device_handshake(void);


#endif //__HANDSHAKE_H__