#ifndef AES_IMPLEMENTATION_IOFILE_H
#define AES_IMPLEMENTATION_IOFILE_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char * message);
uint32_t * loadFile(const char * fileName, uint32_t * size);
void saveFile(const char * fileName, const uint32_t * buffer, uint32_t size);

#endif