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

ending = """
/* dane aplikacji */
	.data
"""

mdata = """\
/* zmienna, wstepnie zadeklarowana typu long */
	.globl	{0}
	.align	2	/* alokacja co 2B */
	.type	{0}, @object
	.size	{0}, 8
{0}:
	.dword  {1}

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

def SW(rs1, rs2, imm):
    if type(rs1) is int:
        rs1 = "x"+str(rs1)
    if type(rs2) is int:
        rs2 = "x"+str(rs2)
    return ''\
        +"\tsw"\
        +" "\
        +rs1\
        +", "\
        +str(imm)\
        +"("\
        +rs2\
        +")\n"

class REG:
    _r = 0
    def __call__(self):
        self._r += 1
        return self._r if self._r < 32 else (0, print("Overflowed"))[0]
    def __invert__(self):
        return self._r


dirs = ["_test", "_face", "_reverse"]
files = [f + ".s" for f in dirs]

dirs = ["SW" + d for d in dirs]
files = ["/sw" + f for f in files]

try:
    mkdir(dirs[0])
except:
    pass
with open(dirs[0]+files[0], "w") as f:
    rd = REG()
    f.write(beginning)

    addr = rd()

    f.write(ADDI(addr, "zero", imax))
    f.write(ADDI(addr, addr, 1))
    f.write(ADDI(addr, addr, 512))
    f.write(SW(addr, addr, 0))

    for v in vals:
        f.write(ADDI(rd(), "zero", v))
        f.write(ADDI(addr, addr, 4))
        f.write(SW(~rd, addr, 0))

    for v in vals:
        f.write(ADDI(rd(), addr, v))
        f.write(ADDI(addr, addr, 4))
        f.write(SW(~rd, addr, 0))


