#/***************************************************
#		 Copyright (c) 2018 MINE 田宇
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of version 2 of the GNU General Public
# License as published by the Free Software Foundation.
#
#***************************************************/

CFLAGS := -mcmodel=large -fno-builtin -m64

ASFLAGS := --64

PIC := APIC

all: system_tmp kallsyms.o
	ld -b elf64-x86-64 -z muldefs -o system head.o entry.o APU_boot.o main.o printk.o trap.o memory.o interrupt.o PIC.o task.o cpu.o keyboard.o mouse.o disk.o SMP.o time.o HPET.o softirq.o timer.o schedule.o fat32.o VFS.o sys.o syscalls.o semaphore.o waitqueue.o kallsyms.o -T Kernel.lds
	objcopy -I elf64-x86-64 -S -R ".eh_frame" -R ".comment" -O binary system kernel.bin

system_tmp:	head.o entry.o APU_boot.o main.o printk.o trap.o memory.o interrupt.o PIC.o task.o cpu.o keyboard.o mouse.o disk.o SMP.o time.o HPET.o softirq.o timer.o schedule.o fat32.o VFS.o sys.o syscalls.o semaphore.o waitqueue.o
	ld -b elf64-x86-64 -z muldefs -o system_tmp head.o entry.o APU_boot.o main.o printk.o trap.o memory.o interrupt.o PIC.o task.o cpu.o keyboard.o mouse.o disk.o SMP.o time.o HPET.o softirq.o timer.o schedule.o fat32.o VFS.o sys.o syscalls.o semaphore.o waitqueue.o -T Kernel.lds 

head.o:	head.S
	gcc -E head.S > head.s
	as $(ASFLAGS) -o head.o head.s

entry.o: entry.S
	gcc -E entry.S > entry.s
	as $(ASFLAGS) -o entry.o entry.s

APU_boot.o: APU_boot.S
	gcc -E APU_boot.S > APU_boot.s
	as $(ASFLAGS) -o APU_boot.o APU_boot.s

main.o:	main.c
	gcc  $(CFLAGS) -c main.c -D$(PIC)

printk.o: printk.c
	gcc  $(CFLAGS) -c printk.c

trap.o: trap.c
	gcc  $(CFLAGS) -c trap.c

memory.o: memory.c
	gcc  $(CFLAGS) -c memory.c

interrupt.o: interrupt.c
	gcc  $(CFLAGS) -c interrupt.c

ifeq ($(PIC),APIC)
PIC.o: APIC.c
	gcc  $(CFLAGS) -c APIC.c -o PIC.o
else
PIC.o: 8259A.c
	gcc  $(CFLAGS) -c 8259A.c -o PIC.o
endif
	
task.o: task.c
	gcc  $(CFLAGS) -c task.c	

cpu.o: cpu.c
	gcc  $(CFLAGS) -c cpu.c

keyboard.o: keyboard.c
	gcc  $(CFLAGS) -c keyboard.c

mouse.o: mouse.c
	gcc  $(CFLAGS) -c mouse.c

disk.o: disk.c
	gcc  $(CFLAGS) -c disk.c

SMP.o: SMP.c
	gcc  $(CFLAGS) -c SMP.c

time.o: time.c
	gcc  $(CFLAGS) -c time.c

HPET.o: HPET.c
	gcc  $(CFLAGS) -c HPET.c

softirq.o: softirq.c
	gcc  $(CFLAGS) -c softirq.c

timer.o: timer.c
	gcc  $(CFLAGS) -c timer.c

schedule.o: schedule.c
	gcc  $(CFLAGS) -c schedule.c

fat32.o: fat32.c
	gcc  $(CFLAGS) -c fat32.c

VFS.o: VFS.c
	gcc  $(CFLAGS) -c VFS.c

sys.o: sys.c
	gcc  $(CFLAGS) -c sys.c

syscalls.o: syscalls.c
	gcc  $(CFLAGS) -c syscalls.c

semaphore.o: semaphore.c
	gcc  $(CFLAGS) -c semaphore.c

waitqueue.o: waitqueue.c
	gcc  $(CFLAGS) -c waitqueue.c
	
kallsyms.o: kallsyms.c system_tmp
	gcc -o kallsyms kallsyms.c
	nm -n system_tmp | ./kallsyms > kallsyms.S
	gcc -c kallsyms.S

clean:
	rm -rf *.o *.s~ *.s *.S~ *.c~ *.h~ system system_tmp Makefile~ Kernel.lds~ kernel.bin  kallsyms kallsyms.o kallsyms.S

