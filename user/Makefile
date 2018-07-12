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
	objcopy -I elf64-x86-64 -S -R ".eh_frame" -R ".comment" -O binary system_api_lib init.bin

system_api_lib: init.o lib.o errno.o wait.o malloc.o printf.o string.o keyboard.o dirent.o
	ld -b elf64-x86-64 -z muldefs -o system_api_lib init.o lib.o errno.o wait.o malloc.o printf.o string.o keyboard.o dirent.o -T User.lds

init.o: init.c
	gcc  $(CFLAGS) -c init.c

lib.o: lib.c
	gcc  $(CFLAGS) -c lib.c

errno.o: errno.c
	gcc  $(CFLAGS) -c errno.c

wait.o: wait.c
	gcc  $(CFLAGS) -c wait.c

malloc.o: malloc.c
	gcc  $(CFLAGS) -c malloc.c

printf.o: printf.c
	gcc  $(CFLAGS) -c printf.c

string.o: string.c
	gcc  $(CFLAGS) -c string.c

keyboard.o: keyboard.c
	gcc  $(CFLAGS) -c keyboard.c

dirent.o: dirent.c
	gcc  $(CFLAGS) -c dirent.c

clean:
	rm -rf *.o *.s~ *.s *.S~ *.c~ *.h~ Makefile~ User.lds~ system_api_lib init.bin

