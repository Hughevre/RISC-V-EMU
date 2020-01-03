#include "Functions.h"

void ADDI() {
	Byte	rs1 = getRS1();
	SDWord	imm = (loadCodeWord(getPC()) & 0xFFF00000) >> 20;     //imm[11:0]
	Byte	rd  = getRD();

	imm -= (imm & 0x800) << 1;                                // 12-bit immediate sign-extended

	printf("0x%08x: ADDI RD:%d, RS1:%d, IMM:%d\n", getPC(), rd, rs1, imm);

	setRegister(rd, (getRegister(rs1) + imm));

	incPC();
}

void LUI() {
	DWord	imm	= (loadCodeWord(getPC()) & 0xFFFFF000) >> 12;           // imm[31:12]
	Byte	rd	= getRD();

	printf("0x%08x: LUI RD:%d, IMM:%d\n", getPC(), rd, imm);

	setRegister(rd, (DWord)imm);

	incPC();
}

void AUIPC() {
	DWord	imm = (loadCodeWord(getPC()) & 0xFFFFF000) >> 12;         // imm[31:12]
	Byte	rd	= getRD();

	printf("0x%08x: AUIPC RD:%d, IMM:%d\n", getPC(), rd, imm);

	setRegister(rd, (DWord)(imm + getPC()));

	incPC();
}

void XOR() {
	Byte rs1	= getRS1();
	Byte rs2	= getRS2();
	Byte rd		= getRD();

	printf("0x%08x: XOR RD:%d, RS1:%d, RS2:%d\n", getPC(), rd, rs1, rs2);

	setRegister(rd, getRegister(rs1) ^ getRegister(rs2));

	incPC();
}

void SLTU() {
	Byte rs1	= getRS1();
	Byte rs2	= getRS2();
	Byte rd		= getRD();

	printf("0x%08x: SLTU RD:%d, RS1:%d, RS2:%d\n", getPC(), rd, rs1, rs2);

	if ((DWord)getRegister(rs1) < (DWord)getRegister(rs2))
		setRegister(rd, 1);
	else
		setRegister(rd, 0);

	incPC();
}

void JAL() {
	SDWord	imm	= (loadCodeWord(getPC()) & 0xFFFFF000) >> 12;     // imm[20] imm[10:1] imm[11] imm[19:12]
	Byte	rd	= getRD();

	imm = ((imm >> 9) & 0x3FF) + ((imm << 2) & 0x400) + ((imm << 11) & 0x7FE00) - (imm & 0x80000);
	imm <<= 1;                      // bit 0. pusty

	printf("0x%08x: JAL RD:%d, IMM:%d\n", getPC(), rd, imm);

	setRegister(rd, getPC() + 1);     // pc+4 bajty (d³ugoœæ s³owa)
	setPC(getPC() + (imm / 4));         // trzeba chyba zmieniæ sposób adresowania PC na 4 na skok
}

void JALR() {
	SDWord	imm = (loadCodeWord(getPC()) & 0xFFF00000) >> 20;     // imm[11:0]
	Byte	rs1	= getRS1();
	Byte	rd	= getRD();

	imm = (imm & 0xFFE) - ((imm & 0x800) << 1);

	printf("0x%08x: JALR RD:%d, RS1:%d, IMM:%d\n", getPC(), rd, rs1, imm);

	setRegister(rd, getPC() + 1);
	setPC(getPC() + ((rd + imm) & 0xFFFFFFFE) / 4);
}

void BEQ() {
	SDWord	imm = (loadCodeWord(getPC()) & 0xFE000F80) >> 7;      // imm[12] imm[10:5] imm[4:1] imm[11]
	Byte	rs1 = getRS1();
	Byte	rs2 = getRS2();

	imm = ((imm >> 1) & 0x00F) + ((imm >> 14) & 0x3F0) + ((imm << 10) & 0x400) - ((imm >> 13) & 0x800);
	imm <<= 1;                      // bit 0. pusty

	printf("0x%08x: BEQ RS1:%d, RS2:%d, IMM%d\n", getPC(), rs1, rs2, imm);

	if (getRegister(rs1) == getRegister(rs2))
		setPC(getPC() + imm / 4);
	else
		incPC();

}

void LW() {
	SDWord	imm = (loadCodeWord(getPC()) & 0xFFF00000) >> 20;     // imm[11:0]
	Byte	rs1 = getRS1();
	Byte	rd	= getRD();

	imm -= (imm & 0x800) << 1;        // 12-bit immediate sign-extended

	printf("0x%08x: LW RD:%d, RS1:%d, IMM:%d\n", getPC(), rd, rs1, imm);

	Address addr = imm + getRegister(rs1);

	setRegister(rd, loadDataWord(addr));

	incPC();
}

void SW() {
	SDWord	imm = (loadCodeWord(getPC()) & 0xFE000F80) >> 7;      // imm[11:5] rs2 rs1 funct3 imm[4:0]
	Byte	rs1 = getRS1();
	Byte	rs2 = getRS2();

	imm = (imm & 0x01F) + ((imm >> 13) & 0xFE0);
	imm -= (imm & 0x800) << 1;        // 12-bit immediate sign-extended

	printf("0x%08x: SW RS1:%d, RS2:%d, IMM:%d\n", getPC(), rs1, rs2, imm);

	Address addr = imm + getRegister(rs1);

	storeDataWord(addr, getRegister(rs2));

	incPC();
}

void SB() {
	SDWord	imm = (loadCodeWord(getPC()) & 0xFE000F80) >> 7;      // imm[11:5] rs2 rs1 funct3 imm[4:0]
	Byte	rs1 = getRS1();
	Byte	rs2 = getRS2();

	imm = (imm & 0x01F) + ((imm >> 13) & 0xFE0);
	imm -= (imm & 0x800) << 1;        // 12-bit immediate sign-extended

	printf("0x%08x: SB RS1%d, RS2%d, IMM%d\n", getPC(), rs1, rs2, imm);

	Address addr = imm + getRegister(rs1);

	storeDataWord(addr, getRegister(rs2) & 0xFF);        // 8-bitów

	incPC();
}


