
#include "can.h"


#define BUS_SIZE 100
#define HANDSHAKE_MSG "HELLO"
#define HANDSHAKE_ACK "ACK"
#define MAX_DEVICES 2

char bus[BUS_SIZE];       // Shared bus
int bus_busy = 0;         // Flag to simulate bus occupancy

// Simulate writing to the bus
int can_write_to_bus(const char *msg, int device_id) {
    if (bus_busy) {
        printf("Device %d: Collision detected! Bus is busy.\n", device_id);
        return -1;
    }

    bus_busy = 1;
    strncpy(bus, msg, BUS_SIZE);
    printf("Device %d: Wrote to bus: %s\n", device_id, msg);
    return 0;
}

// Simulate reading from the bus
int can_read_from_bus(char *buffer, int device_id) {
    if (strlen(bus) == 0) {
        printf("Device %d: Bus is empty. Timeout error.\n", device_id);
        return -1;
    }

    strncpy(buffer, bus, BUS_SIZE);
    printf("Device %d: Read from bus: %s\n", device_id, buffer);
    return 0;
}

// Simulate clearing the bus
void can_clear_bus() {
    memset(bus, 0, BUS_SIZE);
    bus_busy = 0;
}

// Simulated device communication
void can_device_communicate(int device_id) {
    char buffer[BUS_SIZE];

    // Handshake
    if (can_write_to_bus(HANDSHAKE_MSG, device_id) != 0) return;

    if (can_read_from_bus(buffer, device_id) != 0) return;

    if (strcmp(buffer, HANDSHAKE_MSG) != 0) {
        printf("Device %d: Handshake failed. Received corrupted message.\n", device_id);
        clear_bus();
        return;
    }

    can_clear_bus();
    if (can_write_to_bus(HANDSHAKE_ACK, device_id) != 0) return;

    printf("Device %d: Handshake successful.\n", device_id);
    can_clear_bus();
}