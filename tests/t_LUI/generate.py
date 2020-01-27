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

imax = 1048575
imin = -1048576

vals = ["0", "1", str(524287), str(524288), str(imax-1), str(imax)]


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

def LUI(rd, imm):
    if type(rd) is int:
        rd = "x"+str(rd)
    return ''\
        +"\tlui"\
        +" "\
        +rd\
        +", "\
        +str(imm)\
        +"\n"



class REG:
    _r = 0
    def __call__(self):
        self._r += 1
        return self._r if self._r < 32 else (0, print("Overflowed"))[0]
    def __invert__(self):
        return self._r


dirs = ["_test"]
files = [f + ".s" for f in dirs]

dirs = ["LUI" + d for d in dirs]
files = ["/lui" + f for f in files]
try:
    mkdir(dirs[0])
except:
    pass
with open(dirs[0]+files[0], "w") as f:
    rd = REG()
    f.write(beginning)
    for v in vals:
        f.write(LUI(rd(), v))


