/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
	addi x1, zero, 2047
	addi x1, x1, 1
	addi x1, x1, 512
	sw x1, 0(x1)
	addi x2, zero, 0
	addi x1, x1, 4
	sw x2, 0(x1)
	addi x3, zero, 1
	addi x1, x1, 4
	sw x3, 0(x1)
	addi x4, zero, 2046
	addi x1, x1, 4
	sw x4, 0(x1)
	addi x5, zero, 2047
	addi x1, x1, 4
	sw x5, 0(x1)
	addi x6, zero, -1
	addi x1, x1, 4
	sw x6, 0(x1)
	addi x7, zero, -2047
	addi x1, x1, 4
	sw x7, 0(x1)
	addi x8, zero, -2048
	addi x1, x1, 4
	sw x8, 0(x1)
	addi x9, x1, 0
	addi x1, x1, 4
	sw x9, 0(x1)
	addi x10, x1, 1
	addi x1, x1, 4
	sw x10, 0(x1)
	addi x11, x1, 2046
	addi x1, x1, 4
	sw x11, 0(x1)
	addi x12, x1, 2047
	addi x1, x1, 4
	sw x12, 0(x1)
	addi x13, x1, -1
	addi x1, x1, 4
	sw x13, 0(x1)
	addi x14, x1, -2047
	addi x1, x1, 4
	sw x14, 0(x1)
	addi x15, x1, -2048
	addi x1, x1, 4
	sw x15, 0(x1)
