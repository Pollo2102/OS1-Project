#!/bin/bash

# Test the OS
# ./load_bootloader.sh
# ./compile_kernel.sh
# ./runSim.sh

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

# Compile kernel
bcc -ansi -c -o kernel.o kernel.c

# Assemble kernel.asm
# Link all the files together and produce kernel
# Copy the kernel to floppya.img at sector 3
as86 kernel.asm -o kernel_asm.o && ld86 -o kernel -d kernel.o kernel_asm.o && dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3

# Run the OS
echo c | bochs -q -f bochsrc-2.6.9.bxrc