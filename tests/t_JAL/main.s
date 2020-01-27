/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
	# .attribute arch, "rv32i" <- inny sposób ustawienia architektury

_start:	
	jal ra, punkt1
	addi a0, zero, 0xff

punkt3:
	addi a3, zero, 0x3
	jal s3, punkt4

punkt2:
	addi a2, zero, 0x2
	jal s2, punkt3

punkt4:
	addi a4, zero, 0x4
	jal s4, punkt5

punkt1:
	addi a1, zero, 0x1
	jal s1, punkt2

punkt5:


