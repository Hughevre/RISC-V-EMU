/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
	addi x1, zero, -1
	addi x2, x1, 1
	addi x3, x1, 2046
	addi x4, x1, 2047
	addi x5, x1, -1
	addi x6, x1, -2047
	addi x7, x1, -2048
	addi x8, zero, -2047
	addi x9, x8, 1
	addi x10, x8, 2046
	addi x11, x8, 2047
	addi x12, x8, -1
	addi x13, x8, -2047
	addi x14, x8, -2048
	addi x15, zero, -2048
	addi x16, x15, 1
	addi x17, x15, 2046
	addi x18, x15, 2047
	addi x19, x15, -1
	addi x20, x15, -2047
	addi x21, x15, -2048
