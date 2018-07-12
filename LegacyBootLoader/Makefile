#/***************************************************
#		 Copyright (c) 2018 MINE 田宇
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of version 2 of the GNU General Public
# License as published by the Free Software Foundation.
#
#***************************************************/

all: boot.bin loader.bin

loader.bin:
	nasm loader.asm -o loader.bin

boot.bin:
	nasm boot.asm -o boot.bin

clean:
	rm -rf *.bin *.asm~ Makefile~ loader.bin boot.bin
