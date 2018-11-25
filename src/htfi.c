#include <stdlib.h>

typedef union {
    struct {
        uint64_t payload : 48;
        uint8_t command : 8;
        uint8_t device : 8;
    };
    uint64_t value;
} HTIF;

volatile HTIF tohost, fromhost;

int recv_fromhost(uint8_t dev, uint8_t cmd) {
    HTIF htif;
    htif.value = fromhost.value;
    if(htif.value) {
        fromhost.value = 0;
        if(htif.device == dev && htif.command == cmd)
            return htif.payload;
    }
    return -1;
}

void send_tohost(uint8_t dev, uint8_t cmd, uint64_t payload) {
    while(tohost.value);
    HTIF htif;
    htif.device = dev;
    htif.command = cmd;
    htif.payload = payload;
    tohost.value = htif.value;
}

int send_and_recv_host(uint8_t dev, uint8_t cmd, uint64_t payload) {
    send_tohost(dev, cmd, payload);
    return recv_fromhost(dev, cmd);
}

int8_t htif_console_getchar() {
    return send_and_recv_host(1, 0, 0);
}

void htif_console_putchar(uint8_t ch) {
    send_tohost(1, 1, ch);
}

void htif_syscall(uint32_t* args) {
    send_tohost(0, 0, (uint64_t)args);
}

void htif_rfb_configure(uint16_t width, uint16_t height) {
    send_tohost(2, 0, (32ULL << 32) | (height << 16) | width);
}

void htif_send_frame(uint32_t* frame) {
    send_tohost(2, 1, (uint64_t)frame);
}



void puts(const char* str) {
    while(*str)
        htif_console_putchar(*str++);
}

void exit(int32_t err) {
    send_tohost(0, 0, (err<<1)|1ULL);
     __builtin_unreachable();
}
