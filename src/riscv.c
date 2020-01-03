#include "Parser.h"
#include "Memory.h"
#include "Opcodes.h"
#include "Functions.h"
#include "Debug.h"

int main()
{
	readMemory("file_code.bin", &g_codeSpace, sizeof(g_codeSpace)); //  ..\\tests\\file_code.bin
	readMemory("file_data_in.bin", &g_dataSpace, sizeof(g_dataSpace)); //   ..\\tests\\file_data_in.bin
	readMemory("file_reg_in.bin", &reg, sizeof(reg)); // ..\\tests\\

	setDebugLevel(TRACE);

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
					printError("");
					return -1;
				}
				break;

			case ID_LUI:
				LUI();
				break;

			case ID_AUIPC:
				AUIPC();
				break;

			case ID_OP:
				switch (getFunct3(inst) && getFunct7(inst)) {       
				case ID_XOR:
					XOR();
					break;
				case ID_SLTU:
					SLTU();
					break;
				default:
					printError("");
					return -1;
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
					printError("");
					return -1;
				}
				break;

			case ID_LOAD:
				switch (getFunct3(inst)) {       
				case ID_LW:
					LW();
					break;
				default:
					printError("");
					return -1;
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
					printError("");
					return -1;
				}
				break;

			default:
				printError("Found unsupported instruction (PC=0x%08lx, T=0x%08lx)\r\n", getPC(), inst);
				saveMemory("..\\tests\\file_data_out.bin", &g_dataSpace, sizeof(g_dataSpace));
				saveMemory("..\\tests\\file_reg_out.bin", &reg, sizeof(reg));
				return -1;
				break;
		}
	}

	return 0;
}