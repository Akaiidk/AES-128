#ifndef AES_IMPLEMENTATION_AES_H
#define AES_IMPLEMENTATION_AES_H
#include <stdint.h>
#include <stdlib.h>

extern const uint8_t aesSbox[256];
extern const uint8_t aesInvSbox[256];
extern const uint32_t Rcon[11];

uint32_t rotWord(uint32_t w);
uint32_t subWord(uint32_t w);
uint32_t ** keyExpansion(uint32_t const key[4]);
void addRoundKey(uint8_t col[4], uint32_t key);
void shiftRows(uint32_t w[4]);
void mixColumns(uint8_t col[4]);
void cipher(uint32_t w[4], uint32_t ** keys);
void invShiftRows(uint32_t w[4]);
void invSubBytes(uint32_t w[4]);
void invMixColumns(uint8_t col[4]);
void decipher(uint32_t w[4], uint32_t ** keys);

#endif