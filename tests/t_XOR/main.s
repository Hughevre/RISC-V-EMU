/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
	# .attribute arch, "rv32i" <- inny sposób ustawienia architektury

_start:
	li a2, 0
	li a3, 1
	xor	a0, a2, a3

	li a4, -1
	xor	a1, a3, a4
	
	li a5, -2048
	xor	a1, a3, a5
/* dane aplikacji */