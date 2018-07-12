/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __8259A_H__

#define __8259A_H__

#include "ptrace.h"


/*

*/

void init_8259A();

/*

*/

void do_IRQ(struct pt_regs * regs,unsigned long nr);

#endif
