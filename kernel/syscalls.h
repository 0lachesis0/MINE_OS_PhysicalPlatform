/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/


SYSCALL_COMMON(__NR_putstring,sys_putstring)

SYSCALL_COMMON(__NR_open,sys_open)
SYSCALL_COMMON(__NR_close,sys_close)
SYSCALL_COMMON(__NR_read,sys_read)
SYSCALL_COMMON(__NR_write,sys_write)
SYSCALL_COMMON(__NR_lseek,sys_lseek)

SYSCALL_COMMON(__NR_fork,sys_fork)
SYSCALL_COMMON(__NR_vfork,sys_vfork)
SYSCALL_COMMON(__NR_execve,sys_execve)
SYSCALL_COMMON(__NR_exit,sys_exit)
SYSCALL_COMMON(__NR_wait4,sys_wait4)

SYSCALL_COMMON(__NR_brk,sys_brk)
SYSCALL_COMMON(__NR_reboot,sys_reboot)

SYSCALL_COMMON(__NR_chdir,sys_chdir)
SYSCALL_COMMON(__NR_getdents,sys_getdents)

