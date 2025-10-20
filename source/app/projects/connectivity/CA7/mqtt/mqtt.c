/*
 * Copyright (c) 2025, Team B
 * All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include "mqtt.h"

void print_message(char *message) {
    printf("%s\n", message);
    char *leaked_buffer = malloc(20);  // Creates intentional leak
    // Intentionally no free()
}