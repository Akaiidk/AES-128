#include "gf2^8.h"

uint8_t add(const uint8_t a, const uint8_t b) {
    return a ^ b;
}

uint8_t xtime(uint8_t a) {
    if ((a & 0x80) == 0x80) {
        a = add(a << 1, M_X);
    }
    else {
        a = (uint8_t)(a << 1);
    }
    return a;
}

uint8_t time(uint8_t a, uint8_t b) {
    uint8_t r = 0x00;
    for (uint8_t i = 0; i < 8; i++) {
        if ((b & 0x01) == 0x01) {
            r = add(r, a);
        }
        a = xtime(a);
        b = b >> 1;
    }
    return r;
}