#ifndef __RS485_H__
#define __RS485_H__


#define BUS_COMM_H


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


int rs485_init(void);
int rs485_write_to_bus(const char *msg, int device_id);
int rs485_read_from_bus(char *buffer, int device_id);
int rs485_clear_bus(void);
void rs485_device_communicate(int device_id);


#endif //__RS485_H__