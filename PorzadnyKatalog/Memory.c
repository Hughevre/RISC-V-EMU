#include "Memory.h"

DWord g_code_space[CODE_SIZE];
DWord g_data_space[DATA_SIZE];

DWord load_code_word(Address addr) {
	if (addr < CODE_SIZE)
		return g_code_space[addr];
	return ENOMEM;
}

DWord load_data_word(Address addr) {
	if (addr < DATA_SIZE)
		return g_data_space[addr];
	return ENOMEM;
}
