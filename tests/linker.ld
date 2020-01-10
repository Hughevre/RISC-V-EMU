/*
 *  Na temat .riscv.attributes:
 *  https://github.com/kito-cheng/riscv-elf-psabi-doc/blob/attr-sections/riscv-elf.md
 */


MEMORY
{
  text   (rx)   : ORIGIN = 0x000000, LENGTH = 0x008000
  data   (rw!x) : ORIGIN = 0x00A000, LENGTH = 0x00E000
  .riscv.attributes (r) : ORIGIN = 0x030000, LENGTH = 0x00ffff 
}

SECTIONS
{
  .text : { *(.text) }
  .data : { *(.data) }
  .riscv.attributes : { *(.riscv.attributes) }
}