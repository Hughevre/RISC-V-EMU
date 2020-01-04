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

#define INSTRUCTION_ADRESS_MISALIGNED       0x00000100
//   (0x00, 'misaligned fetch'),
//   (0x01, 'fetch access'),
//   (0x02, 'illegal instruction'),
//   (0x03, 'breakpoint'),
//   (0x04, 'misaligned load'),
//   (0x05, 'load access'),
//   (0x06, 'misaligned store'),
//   (0x07, 'store access'),
//   (0x08, 'user_ecall'),
//   (0x09, 'supervisor_ecall'),
//   (0x0A, 'hypervisor_ecall'),
//   (0x0B, 'machine_ecall'),
//   (0x0C, 'fetch page fault'),
//   (0x0D, 'load page fault'),
//   (0x0F, 'store page fault')

//   //https://github.com/riscv/riscv-opcodes/blob/7c3db437d8d3b6961f8eb2931792eaea1c469ff3/parse-opcodes

#endif 
