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