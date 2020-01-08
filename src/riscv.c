#include "../inc/Parser.h"
#include "../inc/Memory.h"
#include "../inc/Opcodes.h"
#include "../inc/Instructions.h"
#include "../inc/Debug.h"

int main()
{
	setDebugLevel(TRACE);

	readMemory("file_code.bin", &g_codeSpace, sizeof(g_codeSpace));
	readMemory("file_data_in.bin", &g_dataSpace, sizeof(g_dataSpace));
	readMemory("file_reg_in.bin", &reg, sizeof(reg.rX));

	for(int i=0; i<20; i++){
		printf("%#x\n",g_dataSpace[i]);
	}

	DWord inst;
	setPC(0x00000000);
	for (;;) {
		inst = loadCodeWord(getPC());
		switch (getOpCode(inst)) {
			case ID_OP_IMM:
				switch (getFunct3(inst)) {
				case ID_ADDI:
					ADDI();
					break;
				default:
					printError("**** Found unsupported subinstruction (PC=0x%08lx, INST=0x%08lx, FUNCT3=0x%04lx) ****\r\n", getPC(), inst, getFunct3(inst));
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
				switch (getFunct3(inst) + getFunct7(inst)) {
				case ID_XOR:
					XOR();
					break;
				case ID_SLTU:
					SLTU();
					break;
				default:
					printError("**** Found unsupported subinstruction (PC=0x%08lx, INST=0x%08lx, FUNCT3=0x%04lx) ****\r\n", getPC(), inst, getFunct3(inst));
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
				switch (getFunct3(inst)) {    
				case ID_BEQ:
					BEQ();
					break;
				default:
					printError("**** Found unsupported subinstruction (PC=0x%08lx, INST=0x%08lx, FUNCT3=0x%04lx) ****\r\n", getPC(), inst, getFunct3(inst));
					goto error;
				}
				break;

			case ID_LOAD:
				switch (getFunct3(inst)) {       
				case ID_LW:
					LW();
					break;
				default:
					printError("**** Found unsupported subinstruction (PC=0x%08lx, INST=0x%08lx, FUNCT3=0x%04lx) ****\r\n", getPC(), inst, getFunct3(inst));
					goto error;
				}
				break;

			case ID_STORE:
				switch (getFunct3(inst)) {     
				case ID_SW:
					SW();
					break;
				case ID_SB:
					SB();
					break;
				default:
					printError("**** Found unsupported subinstruction (PC=0x%08lx, INST=0x%08lx, FUNCT3=0x%04lx) ****\r\n", getPC(), inst, getFunct3(inst));
					goto error;
				}
				break;

			default:
				printError("Found unsupported instruction (PC=0x%08lx, INST=0x%08lx)\r\n", getPC(), inst);
				goto error;
		}
	}

	error:
		saveMemory("file_data_out.bin", &g_dataSpace, sizeof(g_dataSpace));
		saveMemory("file_reg_out.bin", &reg, sizeof(reg.rX));
		return -1;

	saveMemory("file_data_out.bin", &g_dataSpace, sizeof(g_dataSpace));
	saveMemory("file_reg_out.bin", &reg, sizeof(reg.rX));
	return 0;
}