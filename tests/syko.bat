@set MPATH=D:\Risc-v\bin

@set GAS=%MPATH%\riscv64-unknown-elf-as.exe
@set GLD=%MPATH%\riscv64-unknown-elf-ld.exe
@set GOBJDUMP=%MPATH%\riscv64-unknown-elf-objdump.exe
@set GOBJCOPY=%MPATH%\riscv64-unknown-elf-objcopy.exe
@set GREADELF=%MPATH%\riscv64-unknown-elf-readelf.exe

@set LD_OPTIONS=-nostartfiles 

%GAS% main.s -o main.o
%GLD% %LD_OPTIONS% -Tlinker.ld main.o -o test
%GOBJDUMP% -DxS test > test.lst
%GREADELF% -a test >test_elf.lst
@%GOBJCOPY% -j ".text" -O binary test test.bin
@%GOBJCOPY% -j ".data" -O binary test data.bin
