#ifndef __CAN_H__
#define __CAN_H__


#define BUS_COMM_H

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

// =======================
// Status Codes
// =======================
#define STATUS_OK              0
#define STATUS_HANDSHAKE_FAIL  1
#define STATUS_COLLISION       2
#define STATUS_TIMEOUT         3
#define STATUS_CORRUPT_DATA    4
#define STATUS_BUSY            5
#define STATUS_RETRYING        6
#define STATUS_INVALID_MSG     7
#define STATUS_ACK_RECEIVED    8
#define STATUS_NO_RESPONSE     9
#define STATUS_BUFFER_OVERFLOW 10

// =======================
// Bus Configuration
// =======================
#define BUS_MAX_DEVICES        10
#define BUS_BUFFER_SIZE        256
#define BUS_MAX_RETRIES        3
#define BUS_TIMEOUT_MS         1000

// =======================
// Device Roles
// =======================
#define ROLE_MASTER            0
#define ROLE_SLAVE             1

// =======================
// Utility Macros
// =======================
#define IS_VALID_MSG(msg)      (strcmp(msg, MSG_HANDSHAKE_INIT) == 0 || \
                                strcmp(msg, MSG_HANDSHAKE_ACK) == 0 || \
                                strcmp(msg, MSG_DATA_READY) == 0 || \
                                strcmp(msg, MSG_DATA_RECEIVED) == 0)

int can_init(void);
int can_write_to_bus(const char *msg, int device_id);
int can_read_from_bus(char *buffer, int device_id);
void can_clear_bus();
void can_device_communicate(int device_id);


#endif //__CAN_H__