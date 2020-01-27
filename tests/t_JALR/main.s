/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
	# .attribute arch, "rv32i" <- inny sposób ustawienia architektury

_start:	
	jal s0, punkt1
	addi a0, zero, 0xff

punkt3:
	addi a3, zero, 0x3
	jalr a1, 28

punkt2:
	addi a2, zero, 0x2
	jalr s2, 4

punkt4:
	addi a4, zero, 0x4
	j punkt5

punkt1:
	addi a1, zero, 0x1
	jalr s1, 0(s0)

punkt5:
	addi a5, zero, 0xee


