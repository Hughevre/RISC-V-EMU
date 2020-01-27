/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
	.option norelax

_start:
	xor a0, a0, a0
	xor a1, a1, a1
	bne a0, a1, 0x3C

	addi a0, a0, 2046
	addi a1, zero, 2046
	bne a0, a1, 0x3C

	li a0, 0
	li a1, 0
	li a2, 0
	addi a0, zero, -2047
	addi a1, zero, -2047
	bne a0, a1, 0x3C
	j error
error:
	xor a2, a0, a1


