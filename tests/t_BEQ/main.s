/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
	# .attribute arch, "rv32i" <- inny sposób ustawienia architektury

_start:
	li a0, 10
	li a1, 20
	beq a0, a1, 4

srodek:
	li s0, 1030
	j koniec

koniec:
	li s2, 1370


