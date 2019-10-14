#!/bin/bash

# Set the working folder
cd ./src

# Compile kernel
bcc -ansi -c -o kernel.o kernel.c

# Assemble kernel.asm
# Link all the files together and produce kernel
# Copy the kernel to floppya.img at sector 3
as86 kernel.asm -o kernel_asm.o && ld86 -o kernel -d kernel.o kernel_asm.o && dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3