#include "../inc/Parser.h"
#include "../inc/Memory.h"
#include "../inc/Opcodes.h"
#include "../inc/Instructions.h"
#include "../inc/Debug.h"

int main()
{
	setDebugLevel(DEBUG);

	readMemory(FILE_CODE, &g_codeSpace, sizeof(g_codeSpace));
	readMemory(FILE_DATA_IN, &g_dataSpace, sizeof(g_dataSpace));
	readMemory(FILE_REG_IN, &reg, sizeof(reg));

	DWord inst;
	Byte funct3;
	Byte funct7;
	setPC(0x00000000);
	for (;;) {
		inst 	= loadCodeWord(getPC());
		funct3 	= getFunct3(inst);
		funct7	= getFunct7(inst);
		switch (getOpCode(inst)) {
			case ID_OP_IMM:
				switch (funct3) {
				case ID_ADDI:
					ADDI();
					break;
				default:
					printError(ERR_UNSUPPORTED_SUBINSTRUCTION3, getPC(), inst, funct3);
					goto error;
				}
				break;

			case ID_LUI:
				LUI();
				break;

			case ID_AUIPC:
				AUIPC();
				break;

			case ID_OP:
				if (funct7 != 0) {
					printError(ERR_UNSUPPORTED_SUBINSTRUCTION7, getPC(), inst, funct7);
					goto error;
				}
				switch (funct3) {
				case ID_XOR:
					XOR();
					break;
				case ID_SLTU:
					SLTU();
					break;
				default:
					printError(ERR_UNSUPPORTED_SUBINSTRUCTION3, getPC(), inst, funct3);
					goto error;
				}
				break;

			case ID_JAL:
				JAL();
				break;

			case ID_JALR:
				JALR();
				break;

			case ID_BRANCH:
				switch (funct3) {
				case ID_BEQ:
					BEQ();
					break;
				default:
					printError(ERR_UNSUPPORTED_SUBINSTRUCTION3, getPC(), inst, funct3);
					goto error;
				}
				break;

			case ID_LOAD:
				switch (funct3) {
				case ID_LW:
					LW();
					break;
				default:
					printError(ERR_UNSUPPORTED_SUBINSTRUCTION3, getPC(), inst, funct3);
					goto error;
				}
				break;

			case ID_STORE:
				switch (funct3) {
				case ID_SW:
					SW();
					break;
				case ID_SB:
					SB();
					break;
				default:
					printError(ERR_UNSUPPORTED_SUBINSTRUCTION3, getPC(), inst, funct3);
					goto error;
				}
				break;

			default:
				printError("Found unsupported instruction (PC=0x%08lx, INST=0x%08lx)\r\n", getPC(), inst);
				goto error;
		}
	}

	error:
		saveMemory(FILE_DATA_OUT, &g_dataSpace, sizeof(g_dataSpace));
		saveMemory(FILE_REG_OUT, &reg, sizeof(reg));
		return -1;

	return 0;
}
