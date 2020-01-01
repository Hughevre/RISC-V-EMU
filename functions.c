#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "mem_abs.h"


void F_ADDI(void) {
    DataType RS1=getRS1();
    SignedType IMM=(getMEMC(getPC()) & 0xFFF00000)>>20;     //imm[11:0]
    DataType RD=getRD();

    IMM -= (IMM & 0x800)<<1;                                // 12-bit immediate sign-extended

    printf("0x%08x: ADDI RD%d, RS1%d, IMM%d\n", getPC(), RD, RS1, IMM);

    //ADDI nie uwzględnia przeniesienia
    setRegister(RD, (getRegister(RS1) + IMM) % MAX_DATA_VAL);

    incPC();
}

void F_LUI(void) {
    DataType IMM=(getMEMC(getPC()) & 0xFFFFF000);           // imm[31:12]
    DataType RD=getRD();

    printf("0x%08x: LUI RD%d, IMM%d\n", getPC(), RD, IMM);

    setRegister(RD, IMM);

    incPC();
}

void F_AUIPC(void) {
    DataType IMM=(getMEMC(getPC()) & 0xFFFFF000);           // imm[31:12]
    DataType RD=getRD();

    printf("0x%08x: AUIPC RD%d, IMM%d\n", getPC(), RD, IMM);

    setRegister(RD, IMM + getPC());

    incPC();
}

void F_XOR(void) {
    DataType RS1=getRS1();
    DataType RS2=getRS2();
    DataType RD=getRD();

    printf("0x%08x: XOR RD%d, RS1%d, RS2%d\n", getPC(), RD, RS1, RS2);

    setRegister(RD, getRegister(RS1) ^ getRegister(RS2));

    incPC();
}

void F_SLTU(void) {
    DataType RS1=getRS1();
    DataType RS2=getRS2();
    DataType RD=getRD();

    printf("0x%08x: SLTU RD%d, RS1%d, RS2%d\n", getPC(), RD, RS1, RS2);

    if(getRegister(RS1) < getRegister(RS2))
        setRegister(RD, 1);
    else
        setRegister(RD, 0);

    incPC();
}

void F_JAL(void) {
    OffsetType IMM=(getMEMC(getPC()) & 0xFFFFF000)>>12;     // imm[20] imm[10:1] imm[11] imm[19:12]
    DataType RD=getRD();

    IMM = ((IMM>>9) & 0x3FF) + ((IMM<<2) & 0x400) + ((IMM<<11) & 0x7FE00) - (IMM & 0x80000);
    IMM <<= 1;                      // bit 0. pusty

    printf("0x%08x: JAL RD%d, IMM%d\n", getPC(), RD, IMM);

    setRegister(RD, getPC()+1);     // pc+4 bajty (długość słowa)
    setPC(getPC()+(IMM/4));         // trzeba chyba zmienić sposób adresowania PC na 4 na skok
}

void F_JALR(void) {
    OffsetType IMM=(getMEMC(getPC()) & 0xFFF00000)>>20;     // imm[11:0]
    DataType RS1=getRS1();
    DataType RD=getRD();

    IMM = (IMM & 0xFFE) - ((IMM & 0x800)<<1);

    printf("0x%08x: JALR RD%d, RS1%d, IMM%d\n", getPC(), RD, RS1, IMM);

    setRegister(RD, getPC()+1);
    setPC(getPC()+IMM/2);
}

void F_BEQ(void) {
    OffsetType IMM=(getMEMC(getPC()) & 0xFE000F80)>>7;      // imm[12] imm[10:5] imm[4:1] imm[11]
    DataType RS1=getRS1();
    DataType RS2=getRS2();

    IMM = ((IMM>>1) & 0x00F) + ((IMM>>14) & 0x3F0) + ((IMM<<10) & 0x400) - ((IMM>>13) & 0x800);
    IMM <<= 1;                      // bit 0. pusty

    printf("0x%08x: BEQ RS1%d, RS2%D, IMM%d\n", RS1, RS2, IMM);

    if(getRegister(RS1) == getRegister(RS2))
        setPC(getPC()+IMM/4);
    else
        incPC();

}

void F_LW(void) {
    OffsetType IMM=(getMEMC(getPC()) & 0xFFF00000)>>20;     // imm[11:0]
    DataType RS1=getRS1();
    DataType RD=getRD();

    IMM -= (IMM & 0x800)<<1;        // 12-bit immediate sign-extended

    printf("0x%08x: LW RD%d, RS1%d, IMM%d\n", getPC(), RD, RS1, IMM);

    AddressType T = IMM + getRegister(RS1);

    setRegister(RD, getMEMD(T));

    incPC();
}

void F_SW(void) {
    OffsetType IMM=(getMEMC(getPC()) & 0xFE000F80)>>7;      // imm[11:5] rs2 rs1 funct3 imm[4:0]
    DataType RS1=getRS1();
    DataType RS2=getRS2();

    IMM = (IMM & 0x01F) + ((IMM>>13) & 0xFE0);
    IMM -= (IMM & 0x800)<<1;        // 12-bit immediate sign-extended

    printf("0x%08x: SW RS1%d, RS2%d, IMM%d\n", getPC(), RS1, RS2, IMM);

    AddressType T = IMM + getRegister(RS1);

    setMEMD(T, getRegister(RS2));

    incPC();
}

void F_SB(void) {
    OffsetType IMM=(getMEMC(getPC()) & 0xFE000F80)>>7;      // imm[11:5] rs2 rs1 funct3 imm[4:0]
    DataType RS1=getRS1();
    DataType RS2=getRS2();

    IMM = (IMM & 0x01F) + ((IMM>>13) & 0xFE0);
    IMM -= (IMM & 0x800)<<1;        // 12-bit immediate sign-extended

    printf("0x%08x: SB RS1%d, RS2%d, IMM%d\n", getPC(), RS1, RS2, IMM);

    AddressType T = IMM + getRegister(RS1);

    setMEMD(T, getRegister(RS2) & 0xFF);        // 8-bitów

    incPC();
}

