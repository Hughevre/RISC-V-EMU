﻿#include "Memory.h"

DWord g_codeSpace[CODE_SIZE];
DWord g_dataSpace[DATA_SIZE];
Registers reg;

void throwMemoryException(DWord i, DWord j) {
	printError("ERROR code: 0x%08lx with arg. 0x%08lx at PC=0x%08lx\r\n", i, j, getPC());
	saveMemory("file_data_out.bin", &g_dataSpace, sizeof(g_dataSpace));
	saveMemory("file_reg_out.bin", &reg, sizeof(reg));
	exit(-1);
}

bool isCodeAddressInRange(Address addr) {
	if (addr > CODE_TOP)
		return false;
	return true;
}

bool isDataAddressInRange(Address addr) {
	if (addr > DATA_TOP)
		return false;
	return true;
}

DWord loadCodeWord(Address addr) {
	if (!isCodeAddressInRange(addr))
		throwMemoryException(OUT_OF_CODE_MEMORY_SPACE_ERROR, addr);
	return g_codeSpace[addr];
}

DWord loadDataWord(Address addr) {
	if (!isDataAddressInRange(addr))
		throwMemoryException(OUT_OF_DATA_MEMORY_SPACE_ERROR, addr);
	return g_dataSpace[addr];
}

void setPC(Address addr) {
	//Problem do przemyślenia - jak zabezpieczyć tę funkcję przed podaniem adresu spzoa zakresu 2^32?
	//https://www.linuxquestions.org/questions/programming-9/c-how-to-check-the-overflow-flag-930420/ 
	reg.PC = addr;
}

Address getPC() {
	return reg.PC;
}

void incPC() {
	if (reg.PC == CODE_TOP)
		throwMemoryException(INSTRUCTION_POINTER_OVERFLOW, reg.PC);
	reg.PC += 4;
}

DWord getRegister(Byte n) {
	if (n > REGISTERS_NO)
		throwMemoryException(INVALID_REGISTER_GET, n);
	return reg.rX[n];
}

void setRegister(Byte n, DWord value) {
	if (n > REGISTERS_NO)
		throwMemoryException(INVALID_REGISTER_SET, n);
	reg.rX[n] = value;
}

//
//
//

Byte getRS1() {
	return (loadCodeWord(getPC()) & 0x000F8000) >> 15;
}

Byte getRS2() {
	return (loadCodeWord(getPC()) & 0x01F00000) >> 20;
}

Byte getRD() {
	return (loadCodeWord(getPC()) & 0x00000F80) >> 7;
}

