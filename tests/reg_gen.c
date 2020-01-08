#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int err(char *message) {
    printf("%s",message);
    return -1;
}

int main(int argc, char** argv) {
    if(argc == 1)
        return err("Nie podano nazwy pliku wyjściowego.\n");

    uint32_t reg[32] = {0};

    FILE *fp = fopen(argv[1], "wb");
    if (fp == NULL)
        return err("Problem z plikiem. Czy podano poprawną ścieżkę?\n");

    size_t regSize = sizeof(*reg);
    size_t regCount = sizeof(reg)/regSize;

    fwrite(reg, regSize, regCount, fp);

    fclose(fp);
    return 0;
}