/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __BACKTRACE_H__

#define __BACKTRACE_H__

#include "ptrace.h"

void backtrace(struct pt_regs * regs);

#endif
