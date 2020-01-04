#include "../inc/Memory.h"

DWord	g_codeSpace[CODE_SIZE];
SDWord	g_dataSpace[DATA_SIZE];
Registers reg;

void throwMemoryException(DWord i, DWord j) {
	printError("ERROR code: 0x%08lx with arg. 0x%08lx at PC=0x%08lx\r\n", i, j, getPC());
	saveMemory("file_data_out.bin", &g_dataSpace, sizeof(g_dataSpace));
	saveMemory("file_reg_out.bin", &reg, sizeof(reg));
	exit(-1);
}

bool isCodeAddressInRange(Address addr) {
	if (addr < CODE_BASE && addr > CODE_TOP)
		return false;
	return true;
}

bool isDataAddressInRange(Address addr) {
	if (addr < DATA_BASE && addr > DATA_TOP)
		return false;
	return true;
}

DWord loadCodeWord(Address addr) {
	if (!isCodeAddressInRange(addr))
		throwMemoryException(OUT_OF_CODE_MEMORY_SPACE_ERROR, addr);
	return g_codeSpace[addr];
}

SDWord loadDataWord(Address addr) {
	if (!isDataAddressInRange(addr))
		throwMemoryException(OUT_OF_DATA_MEMORY_SPACE_ERROR, addr);
	return g_dataSpace[addr];
}

void storeDataWord(Address addr, SDWord val) {
	if (!isDataAddressInRange(addr))
		throwMemoryException(OUT_OF_DATA_MEMORY_SPACE_ERROR, addr);
	g_dataSpace[addr] = val;
}

Address getPC() {
	return reg.PC;
}

void setPC(Address addr) {
	//Problem do przemyślenia - jak zabezpieczyć tę funkcję przed podaniem adresu spzoa zakresu 2^32?
	//https://www.linuxquestions.org/questions/programming-9/c-how-to-check-the-overflow-flag-930420/ 
	reg.PC = addr;
}

void incPC() {
	if (reg.PC == CODE_TOP)
		throwMemoryException(INSTRUCTION_POINTER_OVERFLOW, reg.PC);
	reg.PC += 1;
}

SDWord getRegister(Byte n) {
	if (n > REGISTERS_NO)
		throwMemoryException(INVALID_REGISTER_GET, n);
	return reg.rX[n];
}

void setRegister(Byte n, SDWord value) {
	if (n > REGISTERS_NO)
		throwMemoryException(INVALID_REGISTER_SET, n);
	reg.rX[n] = value;
}

DWord getFlag(DWord val) {
	if (val > sizeof(DWord))            
		throwMemoryException(INVALID_GET_OF_FLAGS_BIT, val);
	return reg.flags & (1 << val);
}

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

DWord ord(uint8_t from, uint8_t length, uint8_t to) {
	if(length < 1)
		length = 1;
	return ((loadCodeWord(getPC()) >> from) & ((1 << length) - 1)) << to;
}

DWord ordSign(uint8_t from, uint8_t length, uint8_t to) {
	if(length < 1)
		length = 1;
	return ( ((loadCodeWord(getPC()) >> from)	&	(1 << (length - 1) - 1) ) << to) \
		 - ( ((loadCodeWord(getPC()) >> from) 	& 	(1 << (length - 1))		) << to);
}

Byte getOpCode(DWord comm) {
	return comm & 0x0000007F;
}

Byte getFunct3(DWord comm) {
	return comm & 0x00007000;
}

Byte getFunct7(DWord comm) {
	return comm & 0xFE000000;
}
