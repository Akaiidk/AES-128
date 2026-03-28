#ifndef AES_IMPLEMENTATION_GF2_8_H
#define AES_IMPLEMENTATION_GF2_8_H
#include <stdint.h>
#define M_X 0b00011011

uint8_t xtime(uint8_t a);
uint8_t time(uint8_t a, uint8_t b);

#endif