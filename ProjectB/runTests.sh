#!/bin/bash

cd ./src

bcc -ansi -c -o kernel.o kernel.c

as86 -o kernel-asm.o kernel.asm

ld86 -o syscall-test -d kernel.o kernel-asm.o

dd if=syscall-test of=floppya.img bs=512 count=1 seek=11 conv=notrunc