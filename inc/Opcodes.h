#ifndef OPCODES_H
#define OPCODES_H

#define ID_OP_IMM               0b0010011     //ADDI
#define ID_LUI                  0b0110111
#define ID_AUIPC                0b0010111
#define ID_OP                   0b0110011     //SLTU, XOR
#define ID_JAL                  0b1101111
#define ID_JALR                 0b1100111
#define ID_BRANCH               0b1100011     //BEQ
#define ID_LOAD                 0b0000011     //LW
#define ID_STORE                0b0100011     //SW, SB


/* funct3 codes */
#define ID_ADDI                 0b0000		  //OP-IMM

#define ID_XOR                  0b0100		  //OP
#define ID_SLTU                 0b0011		  //OP

#define ID_BEQ                  0b0000		  //BRANCH

#define ID_LW                   0b0010		  //LOAD

#define ID_SW                   0b0010		  //STORE
#define ID_SB                   0b0000		  //STORE

#endif