#ifndef MEMORY_H
#define MEMORY_H

/*	Memory organization in RISC-V type mirco-controller
		Program memory size (ROM):	32KB = 32768B
		Available address space for program memory:	32768B/4B = 8192 = 0x2000

		Data memory size (RAM):		16KB = 16384B
		Available address space for data memory:	16384B/4B = 4096 = 0x1000
*/

#include <stdint.h>
#include <errno.h>

#define CODE_BASE	0x0000
#define CODE_TOP	0x2000
#define CODE_SIZE	(CODE_TOP-CODE_BASE)

#define DATA_BASE	0x0000
#define DATA_TOP	0x1000
#define DATA_SIZE	(DATA_TOP-DATA_BASE)

typedef uint8_t		Byte;
typedef uint16_t	Word;
typedef uint32_t	DWord;

typedef uint16_t	Address;

extern DWord g_code_space[CODE_SIZE];
extern DWord g_data_space[DATA_SIZE];

DWord load_code_word(Address);
DWord load_data_word(Address);

#endif 
