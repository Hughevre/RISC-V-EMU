/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
	addi x1, zero, -2048
	addi x2, zero, 0
	sltu x3, x2, x1
	addi x4, zero, 0
	addi x5, zero, 1
	sltu x6, x5, x4
	addi x7, zero, 1
	addi x8, zero, 2046
	sltu x9, x8, x7
	addi x10, zero, 2046
	addi x11, zero, 2047
	sltu x12, x11, x10
	addi x13, zero, 2047
	addi x14, zero, -1
	sltu x15, x14, x13
	addi x16, zero, -1
	addi x17, zero, -2047
	sltu x18, x17, x16
	addi x19, zero, -2047
	addi x20, zero, -2048
	sltu x21, x20, x19
