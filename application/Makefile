#/***************************************************
#		 Copyright (c) 2018 MINE 田宇
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of version 2 of the GNU General Public
# License as published by the Free Software Foundation.
#
#***************************************************/

CFLAGS := -mcmodel=large -fno-builtin -m64

all: system_api_lib
	objcopy -I elf64-x86-64 -S -R ".eh_frame" -R ".comment" -O binary system_api_lib test.bin

system_api_lib: test.o lib.o errno.o printf.o  
	ld -b elf64-x86-64 -z muldefs -o system_api_lib test.o lib.o errno.o printf.o -T User.lds

test.o: test.c
	gcc  $(CFLAGS) -c test.c

lib.o: lib.c
	gcc  $(CFLAGS) -c lib.c

errno.o: errno.c
	gcc  $(CFLAGS) -c errno.c

printf.o: printf.c
	gcc  $(CFLAGS) -c printf.c

clean:
	rm -rf *.o *.s~ *.s *.S~ *.c~ *.h~ Makefile~ User.lds~ system_api_lib test.bin

