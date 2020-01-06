#include "../inc/Instructions.h"

void ADDI() {
	Byte	rs1 = getRS1();
	SDWord	imm = ordSign(20, 12, 0);				//imm[11:0] sign-extended
	Byte	rd  = getRD();

	printf("0x%08x: ADDI RD:%d, RS1:%d, IMM:%d\n", getPC(), rd, rs1, imm);

	setRegister(rd, (getRegister(rs1) + imm));

	incPC();
}

void LUI() {
	DWord	imm	= ord(12, 20, 12);           		// imm[31:12]
	Byte	rd	= getRD();

	printf("0x%08x: LUI RD:%d, IMM:%d\n", getPC(), rd, imm);

	setRegister(rd, (DWord)imm);

	incPC();
}

void AUIPC() {
	DWord	imm = ord(12, 20, 12);       		  	// imm[31:12]
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
	SDWord	imm	= ordSign(31, 1, 20) + ord(21, 10, 1) + ord(20, 1, 11) + ord(12, 8, 12);	// imm[20] imm[10:1] imm[11] imm[19:12] sign-extended
	Byte	rd	= getRD();

	printf("0x%08x: JAL RD:%d, IMM:%d\n", getPC(), rd, imm);

	if(imm & 0x2) {
		printError("");								// ADRESS_MISALIGNED
		return;
	}

	setRegister(rd, getPC() + 1);     				// pc + 4 Bytes
	setPC(getPC() + (imm / 4));
}

void JALR() {
	SDWord	imm = ordSign(20, 12, 0);     			// imm[11:0] sign-extended
	Byte	rs1	= getRS1();
	Byte	rd	= getRD();

	printf("0x%08x: JALR RD:%d, RS1:%d, IMM:%d\n", getPC(), rd, rs1, imm);

	if(imm & 0x2) {
		printError("");								// ADRESS_MISALIGNED
		return;
	}
	
	setRegister(rd, getPC() + 1);
	setPC(getRegister(rs1) + ((imm / 4) & 0xFFFFFFFE));
}

void BEQ() {
	SDWord	imm = ordSign(31, 1, 12) + ord(25, 6, 5) + ord(8, 4, 1) + ord(7, 1, 11);      // imm[12] imm[10:5] imm[4:1] imm[11] sign-extended
	Byte	rs1 = getRS1();
	Byte	rs2 = getRS2();

	printf("0x%08x: BEQ RS1:%d, RS2:%d, IMM%d\n", getPC(), rs1, rs2, imm);

	if(imm & 0x2) {
		printError("");								// ADRESS_MISALIGNED
		return;
	}
	
	if (getRegister(rs1) == getRegister(rs2))
		setPC(getPC() + imm / 4);
	else
		incPC();

}
//TODO: Wczytywanie z pamięci i zapis do niej
void LW() {
	SDWord	imm = ordSign(20, 12, 0);     			// imm[11:0] sign-extended
	Byte	rs1 = getRS1();
	Byte	rd	= getRD();

	printf("0x%08x: LW RD:%d, RS1:%d, IMM:%d\n", getPC(), rd, rs1, imm);

	Address addr = imm + getRegister(rs1);

	setRegister(rd, loadDataWord(addr));

	incPC();
}

void SW() {
	SDWord	imm = ordSign(25, 7, 5) + ord(7, 5, 0);		// imm[11:5] imm[4:0] sign-extended
	Byte	rs1 = getRS1();
	Byte	rs2 = getRS2();

	printf("0x%08x: SW RS1:%d, RS2:%d, IMM:%d\n", getPC(), rs1, rs2, imm);

	Address addr = imm + getRegister(rs1);

	storeDataWord(addr, getRegister(rs2));

	incPC();
}

void SB() {
	SDWord	imm = ordSign(25, 7, 5) + ord(7, 5, 0);		// imm[11:5] imm[4:0] sign-extended
	Byte	rs1 = getRS1();
	Byte	rs2 = getRS2();

	printf("0x%08x: SB RS1%d, RS2%d, IMM%d\n", getPC(), rs1, rs2, imm);

	Address addr = imm + getRegister(rs1);

	storeDataWord(addr, getRegister(rs2) & 0xFF);		// Byte-size

	incPC();
}


