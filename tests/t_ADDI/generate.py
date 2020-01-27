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


class REG:
    _r = 0
    def __call__(self):
        self._r += 1
        return self._r if self._r < 32 else (0, print("Overflowed"))[0]
    def __invert__(self):
        return self._r


dirs = ["_unset", "_set1", "_set2"]
files = [f + ".s" for f in dirs]

dirs = ["ADDI" + d for d in dirs]
files = ["/addi" + f for f in files]
try:
    mkdir(dirs[0])
except:
    pass
with open(dirs[0]+files[0], "w") as f:
    rd = REG()
    f.write(beginning)
    f.write(ADDI("zero", "zero", imax))

    for v in vals:
        f.write(ADDI(rd(), "zero", v))

    for v in vals:
        f.write(ADDI(rd(), ~rd, v))

    rs1 = REG()
    for v in vals:
        f.write(ADDI(rd(), rs1(), v))

    for v in vals:
        f.write(ADDI(rd(), rs1(), v))

try:
    mkdir(dirs[1])
except:
    pass
with open(dirs[1]+files[1], "w") as f:
    rd = REG()
    f.write(beginning)

    for v in vals[1:4]:
        f.write(ADDI(rd(), "zero", v))
        rs1 = ~rd
        for v2 in vals[1:]:
            f.write(ADDI(rd(), rs1, v2))

try:
    mkdir(dirs[2])
except:
    pass
with open(dirs[2]+files[2], "w") as f:
    rd = REG()
    f.write(beginning)

    for v in vals[4:]:
        f.write(ADDI(rd(), "zero", v))
        rs1 = ~rd
        for v2 in vals[1:]:
            f.write(ADDI(rd(), rs1, v2))