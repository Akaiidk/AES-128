#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "iofile.h"
#include "../include/aes.h"

int main(int argc, char** argv) {
    if (argc == 1) {
        error("Nombre de paramètre incorrect");
    }
    if (strcmp(argv[1], "CBCMAC") != 0 && strcmp(argv[1], "ECB") != 0 && strcmp(argv[1], "CBC") != 0) {
        error("Parametre de mode AES incorrect");
    }
    if (strcmp(argv[1], "CBCMAC") == 0 && argc != 5) {
        error("Nombre de paramètre incorrect");
    }
    if (strcmp(argv[1], "ECB") == 0 || strcmp(argv[1], "CBC") == 0) {
        if (argc != 6) {
            error("Nombre de paramètre incorrect");
        }
        if (strcmp(argv[5], "-c") != 0 && strcmp(argv[5], "-d") != 0) {
            error("Parametre de chiffrement et dechiffrement incorrect");
        }
    }
    if (strlen(argv[2]) != 32) {
        error("La cle n'est pas de bonne taille");
    }
    uint32_t key[4];
    for (int i = 0; i <= 3; i++) {
        sscanf(argv[2]+(i * 8), "%8x", key+i);
    }
    uint32_t lengthMessage;
    uint32_t * message = loadFile(argv[3], &lengthMessage);
    uint32_t ** keys = keyExpansion(key);
    uint32_t tmp[4] = {0, 0, 0, 0};
    if (strcmp(argv[1], "CBCMAC") == 0 || strcmp(argv[5], "-c") == 0) {
        for (uint32_t i = 0; i <= lengthMessage - 4; i += 4) {
            if (strcmp(argv[1], "ECB") != 0) {
                for (uint32_t j = 0; j <= 3; j++) {
                    message[i + j] = message[i + j] ^ tmp[j];
                }
            }
            uint32_t bloc[4] = {message[i], message[i + 1], message[i + 2], message[i + 3]};
            cipher(bloc, keys);
            for (uint32_t j = 0; j <= 3; j++) {
                tmp[j] = bloc[j];
                message[i+j] = bloc[j];
            }
        }
    }
    else {
        uint32_t tmp2[4] = {0, 0, 0, 0};
        for (uint32_t i = 0; i <= lengthMessage - 4; i += 4) {
            uint32_t bloc[4] = {message[i], message[i + 1], message[i + 2], message[i + 3]};
            decipher(bloc, keys);
            for (uint32_t j = 0; j <= 3; j++) {
                tmp2[j] = message[i+j];
                message[i+j] = bloc[j];
            }
            if (strcmp(argv[1], "ECB") != 0) {
                for (uint32_t j = 0; j <= 3; j++) {
                    message[i + j] = message[i + j] ^ tmp[j];
                    tmp[j] = tmp2[j];
                }
            }
        }
    }
    if (strcmp(argv[1], "CBCMAC") != 0) {
        saveFile(argv[4], message, lengthMessage);
    }
    else {
        uint32_t lastBloc[4] = {message[lengthMessage - 4], message[lengthMessage - 3], message[lengthMessage - 2], message[lengthMessage - 1]};
        saveFile(argv[4], lastBloc, 4);
    }
    for (uint32_t i = 0; i <= 10; i++) {
        free(keys[i]);
    }
    free(keys);
    free(message);
    exit(0);
}