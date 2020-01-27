/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
	addi x1, zero, 0
	addi x2, zero, 0
	xor x3, x1, x2
	addi x4, zero, 1
	addi x5, zero, 1
	xor x6, x4, x5
	addi x7, zero, 2046
	addi x8, zero, 2046
	xor x9, x7, x8
	addi x10, zero, 2047
	addi x11, zero, 2047
	xor x12, x10, x11
	addi x13, zero, -1
	addi x14, zero, -1
	xor x15, x13, x14
	addi x16, zero, -2047
	addi x17, zero, -2047
	xor x18, x16, x17
	addi x19, zero, -2048
	addi x20, zero, -2048
	xor x21, x19, x20
