/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
	# .attribute arch, "rv32i" <- inny sposób ustawienia architektury

/* imm - 12 bitów */

_start:
	addi zero, zero, 0x0
	addi a1, zero, 0x1
	addi zero, zero, 0x7ff
	addi a2, zero, 0x7ff
	addi a3, a1, 0x7ff
	addi a4, zero, 0x7ff
	addi a5, a1, 0x7ff

/* dane aplikacji */