#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"
#include "merror.h"

//naglowki poszczegolnych opcodow
void F_ADDI(void);
void F_XOR(void);
void F_SLTU(void);
void F_LUI(void);
void F_AUIPC(void);
void F_JAL(void);
void F_JALR(void);
void F_BEQ(void);
void F_LW(void);
void F_SW(void);
void F_SB(void);

//wzorce opcodow
#define ID_OP_IMM               0010011     //ADDI
#define ID_LUI                  0110111
#define ID_AUIPC                0010111
#define ID_OP                   0110011     //SLTU, XOR
#define ID_JAL                  1101111
#define ID_JALR                 1100111
#define ID_BRANCH               1100011     //BEQ
#define ID_LOAD                 0111111     //LW
#define ID_STORE                0000011     //SW, SB

//wzorce funct3
//OP-IMM
#define ID_ADDI                 000

//OP
#define ID_XOR                  100
#define ID_SLTU                 011

// RANCH
#define ID_BEQ                  000

//LOAD
#define ID_LW                   010

//STORE
#define ID_SW                   010
#define ID_SB                   000


void merror(int i, int j) {
    printf("ERROR code: 0x%08lx with arg. 0x%08lx at PC=0x%08lx\r\n", i, j, getPC());
    saveMEMD(FILE_DATA_OUT);            //zapisz zawartość pamięci danych do pliku
    saveREGS(FILE_REG_OUT);             //zapisz zawartość rejestrów i PC do pliku
    exit(-1);
}

void print_error(char *opcode, int T) {
    printf("Unknown additional opcode sequence for %s: PC=0x%08lx, T=0x%08lx\r\n", opcode, getPC(), T);
    saveMEMD(FILE_DATA_OUT);            //zapisz zawartość pamięci danych do pliku
    saveREGS(FILE_REG_OUT);             //zapisz zawartość rejestrów i PC do pliku
}

int main(void) {
    CodeType T;                         //zmienna pomocnicza
    loadMEMC(FILE_CODE);                //Ładowanie pamięci kodu z pliku
    loadMEMD(FILE_DATA_IN);             //Ładowanie pamięci danych z pliku
    loadREGS(FILE_REG_IN);              //Ładowanie stanu rejestrów z pliku
    setPC(0x0000);                      //Warunki początkowe PC (RESET)
    for(;;) {
        T=getMEMC(getPC());             //T=ID operacji i arg. wbudowanych
        switch(T & 0x7F) {              //wyłuskanie właściwego kodu operacji
        case ID_OP_IMM:
            switch (T & 0x7000) {
            case ID_ADDI:
                F_ADDI();
                break;
            default:
                print_error("OP-IMM", T);
                return -1;
            }
            break;

        case ID_LUI:
            F_LUI();
            break;

        case ID_AUIPC:
            F_AUIPC();
            break;

        case ID_OP:
            switch ((T & 0x7000) && (T & 0xFE000000)) {         //sprawdzenie funct3 i funct7
            case ID_XOR:
                F_XOR();
                break;
            case ID_SLTU:
                F_SLTU();
                break;
            default:
                print_error("OP", T);
                return -1;
            }
            break;

        case ID_JAL:
            F_JAL();
            break;
            
        case ID_JALR:
            F_JALR();
            break;

        case ID_BRANCH:
            switch (T & 0x7000) {       //sprawdzenie funct3
            case ID_BEQ:
                F_BEQ();
                break;
            default:
                print_error("BRANCH", T);
                return -1;
            }
            break;

        case ID_LOAD:
            switch (T & 0x7000) {       //sprawdzenie funct3
            case ID_LW:
                F_LW();
                break;
            default:
                print_error("LOAD", T);
                return -1;
            }
            break;

        case ID_STORE:
            switch (T & 0x7000) {       //sprawdzenie funct3
            case ID_SW:
                F_SW();
                break;
            case ID_SB:
                F_SB();
                break;
            default:
                print_error("STORE", T);
                return -1;
            }
            break;

        default:
            printf("Unknown instruction: PC=0x%08lx, T=0x%08lx\r\n", getPC(), T);
            saveMEMD(FILE_DATA_OUT);    //zapisz zawartość pamięci danych do pliku
            saveREGS(FILE_REG_OUT);     //zapisz zawartość rejestrów i PC do pliku
            return -1;
        }
    }
    saveMEMD(FILE_DATA_OUT);      //zapisz zawartość pamięci danych do pliku
    saveREGS(FILE_REG_OUT);       //zapisz zawartość rejestrów i PC do pliku
    return 0;
}


