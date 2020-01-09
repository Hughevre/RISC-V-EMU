#ifndef MERRORS_H
#define MERRORS_H

#define OUT_OF_CODE_MEMORY_SPACE_ERROR      0x00000001
#define OUT_OF_DATA_MEMORY_SPACE_ERROR      0x00000002
#define INVALID_REGISTER_GET                0x00000004
#define INVALID_REGISTER_SET                0x00000008
#define INVALID_SET_OF_FLAGS_BIT            0x00000010
#define INVALID_GET_OF_FLAGS_BIT            0x00000020
#define INVALID_RESET_OF_FLAGS_BIT          0x00000040
#define INSTRUCTION_POINTER_OVERFLOW		0x00000080

#define ERR_UNSUPPORTED_SUBINSTRUCTION3     "**** Found unsupported subinstruction funct3 (PC=0x%08lx, INST=0x%08lx, FUNCT3=0x%04lx) ****\r\n"
#define ERR_UNSUPPORTED_SUBINSTRUCTION7     "**** Found unsupported subinstruction funct7 (PC=0x%08lx, INST=0x%08lx, FUNCT7=0x%04lx) ****\r\n"
#define ERR_UNSUPPORTED_INSTRUCTION         "**** Found unsupported instruction (PC=0x%08lx, INST=0x%08lx) ****\r\n"
#define ERR_INSTRUCTION_ADRESS_MISALIGNED   "**** Instruction address misaligned (PC=0x%08lx, INST=0x%08lx, IMM=0x%08lx) ****\r\n"

#endif 
