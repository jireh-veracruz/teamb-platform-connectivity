/*
 * Copyright (c) 2025, Team B
 * All rights reserved.
 */

#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int _read(int file, char *ptr, int len) {
    (void)file;
    (void)ptr;
    (void)len;
    errno = ENOSYS;
    return -1;
}

int _write(int file, char *ptr, int len) {
    // Redirect to UART or other output if needed
    (void)file;
    (void)ptr;
    return len;
}

int _sbrk(int incr) {
    extern char _end;  // Defined in linker script
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == 0) {
        heap_end = &_end;
    }

    prev_heap_end = heap_end;
    heap_end += incr;

    return (int)prev_heap_end;
}

int _close(int file) {
    (void)file;
    return -1;
}

int _fstat(int file, struct stat *st) {
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty(int file) {
    (void)file;
    return 1;
}

int _lseek(int file, int ptr, int dir) {
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}

void _exit(int status) {
    (void)status;
    while (1) {
        // Optionally trigger a breakpoint or halt
    }
}
