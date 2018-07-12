/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __SYSCALL_H__

#define __SYSCALL_H__

#define	__NR_putstring	1

#define	__NR_open	2
#define	__NR_close	3
#define	__NR_read	4
#define	__NR_write	5
#define	__NR_lseek	6

#define	__NR_fork	7
#define	__NR_vfork	8
#define	__NR_execve	9
#define	__NR_exit	10
#define	__NR_wait4	11

#define __NR_brk	12
#define __NR_reboot	13

#define __NR_chdir	14
#define __NR_getdents	15

#endif
