#include "iofile.h"
#include <stdint.h>

void error(char * message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

uint32_t * loadFile(const char * fileName, uint32_t * size) {
    FILE * file = fopen(fileName, "rb");
    if (!file) {
        error("Erreur lors de l'ouverture du fichier");
    }
    fseek(file, 0, SEEK_END);
    long const initSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    uint32_t const padding = (16 - (initSize % 16)) % 16;
    *size = (initSize + padding) / 4;
    uint32_t * buffer = calloc(*size, sizeof(uint32_t));
    if (!buffer) {
        fclose(file);
        error("Erreur allocation memoire");
    }
    fread(buffer, 1, initSize, file);
    fclose(file);
    return buffer;
}

void saveFile(const char * fileName, const uint32_t * buffer, const uint32_t size) {
    if (buffer == NULL) {
        error("Erreur lors de l'ecriture du message");
    }
    FILE * file = fopen(fileName, "wb");
    if (!file) {
        error("Erreur lors de la création du fichier");
    }
    const uint8_t * byteBuffer = (const uint8_t *)buffer;
    if (byteBuffer == NULL) {
        error("Erreur lors de la sauvagarde");
    }
    uint32_t byteSize = size * sizeof(uint32_t);
    while (byteSize > 0 && byteBuffer[byteSize - 1] == 0) {
        byteSize--;
    }
    const uint32_t written = fwrite(byteBuffer, 1, byteSize, file);
    if (written != byteSize) {
        fclose(file);
        error("Erreur lors de l'écriture des données");
    }
    fclose(file);
}