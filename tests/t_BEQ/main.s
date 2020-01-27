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
	addi a0, zero, 20
	addi a1, zero, 20
	bne a0, a1, 0
	addi a0, zero, 20
# srodek:
# 	li s0, 1030
# 	j koniec

# koniec:
# 	li s2, 1370


