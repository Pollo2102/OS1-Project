#!/bin/bash

# Set the working folder
cd ./src

# assemble the bootloader
nasm bootload.asm

# Open the newly created bootloader file
# hexedit bootload

# fill the floppy disk with zeroes.
dd if=/dev/zero of=floppya.img bs=512 count=2280

# copy bootload to the floppy
dd if=bootload of=floppya.img bs=512 count=1 conv=notrunc

# copy the readable portion of the file into sector 30
dd if=message.txt of=floppya.img bs=512 count=1 seek=30 conv=notrunc

# Compile kernel
bcc -ansi -c -o kernel.o kernel.c

# Compile test
bcc -ansi -c -o test.o test.c

# Compile os_api
as86 os_api.asm -o os_api.o

# Link the test program
ld86 -o syscall-test -d test.o os_api.o


# Assemble kernel.asm
# Link all the files together and produce kernel
# Copy the kernel to floppya.img at sector 3
#as86 kernel.asm -o kernel_asm.o && as86 start.asm -o start.o && ld86 -o kernel -d kernel.o kernel_asm.o start.o && dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3
as86 kernel.asm -o kernel_asm.o && ld86 -o kernel -d kernel.o kernel_asm.o && dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3
# as86 kernel.asm -o kernel_asm.o && ld86 -o kernel -d kernel.o kernel_asm.o && dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3

# Copy the test program into sector 11
dd if=syscall-test of=floppya.img bs=512 count=1 seek=11 conv=notrunc

# Run the OS
echo c | bochs -q -f bochsrc-2.6.9.bxrc