#ifndef __CONNECT01_TREE_H__
#define __CONNECT01_TREE_H__

#ifdef UART3
#define UART3_TX_GPIO       PORTA_BIT4
#define UART3_RX_GPIO       PORTA_BIT5

// #define UART3_TX_GPIO       PORTA_BIT6
// #define UART3_RX_GPIO       PORTA_BIT7

// #define UART3_TX_GPIO       PORTB_BIT0
// #define UART3_RX_GPIO       PORTB_BIT1

#define UART3_BAUD          115200
// #define UART3_BAUD          9600
// #define UART3_BAUD          2400

#define UART3_DATA_BIT          8
// #define UART3_DATA_BIT          9

#define UART3_PARITY            UART_PARITY_NONE
#define UART3_PARITY            UART_PARITY_EVEN
#define UART3_PARITY            UART_PARITY_ODD

// #define UART3_STOP_BIT          0
#define UART3_STOP_BIT          1
// #define UART3_STOP_BIT          2

#define UART3_SEND_BUFF     uart_send_data
#define UART3_RECV_BUFF     uart_recv_data

#endif

#ifdef RS485_BUS
#define RS485_WRITE(x)         uart_send_data(x)
#define RS485_READ(x)          uart_recv_data(x)
#endif


#ifdef HANDSHAKE_COMMS

#ifdef CAN_BUS
#include "can.h"
#define CAN_SEND        can_write_to_bus
#define CAN_RECV        can_read_from_bus
#define CAN_READY       can_clear_bus
#endif 

#ifdef RS485_BUS
#include "rs485.h"
#define CAN_SEND        rs485_write_to_bus
#define CAN_RECV        rs485_read_from_bus
#define CAN_READY       rs485_clear_bus
#endif 

#endif //HANDSHAKE_COMMS



#endif //__CONNECT01_TREE_H__