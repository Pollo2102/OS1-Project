#!/bin/bash

cd ./src

dd if=message.txt of=floppya.img bs=512 count=1 seek=30 conv=notrunc

./../testOS.sh