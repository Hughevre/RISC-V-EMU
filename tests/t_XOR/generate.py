from os import mkdir



beginning = """\
/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
"""

imax = 2047
imin = -2048

vals = ["0", "1", str(imax-1), str(imax), "-1", str(imin+1), str(imin)]


def ADDI(rd, rs1, imm):
    if type(rd) is int:
        rd = "x"+str(rd)
    if type(rs1) is int:
        rs1 = "x"+str(rs1)
    return ''\
        +"\taddi"\
        +" "\
        +rd\
        +", "\
        +rs1\
        +", "\
        +str(imm)\
        +"\n"

def XOR(rd, rs1, rs2):
    if type(rd) is int:
        rd = "x"+str(rd)
    if type(rs1) is int:
        rs1 = "x"+str(rs1)
    if type(rs2) is int:
        rs2 = "x"+str(rs2)
    return ''\
        +"\txor"\
        +" "\
        +rd\
        +", "\
        +rs1\
        +", "\
        +rs2\
        +"\n"

class REG:
    _r = 0
    def __call__(self):
        self._r += 1
        return self._r if self._r < 32 else (0, print("Overflowed"))[0]
    def __invert__(self):
        return self._r


dirs = [""]
files = [f + ".s" for f in dirs]

dirs = ["XOR" + d for d in dirs]
files = ["/xor" + f for f in files]

try:
    mkdir(dirs[0])
except:
    pass
with open(dirs[0]+files[0], "w") as f:
    rd = REG()
    f.write(beginning)

    for v in vals:
        f.write(ADDI(rd(), "zero", v))
        f.write(ADDI(rd(), "zero", v))
        f.write(XOR(rd(), ~rd-2, ~rd-1))

