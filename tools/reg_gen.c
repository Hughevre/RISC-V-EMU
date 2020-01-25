#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define REG_SIZE 33

int err(char *message) {
    printf("%s\n",message);
    return -1;
}

int main(int argc, char **argv) {
    if (argc == 1)
        return err("Name of the output file not given.");

    uint32_t reg[REG_SIZE];     //32 registers + 1 PC

    for(int i=1; i<REG_SIZE; i++) {
        reg[i] = 0xFFFFFFFF;
    }

    reg[0] = 0;			        //x0 = 0

    FILE *fp = fopen(argv[1], "wb");
    if (fp == NULL)
        return err("An error occurred. Please verify that the correct path was given.");

    size_t regSize = sizeof(*reg);
    size_t regCount = sizeof(reg)/regSize;

    fwrite(reg, regSize, regCount, fp);

    fclose(fp);
    return 0;
}
