/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __PREEMPT_H__

#define __PREEMPT_H__

#include "task.h"

/*

*/

#define preempt_enable()		\
do					\
{					\
	current->preempt_count--;	\
}while(0)

#define preempt_disable()		\
do					\
{					\
	current->preempt_count++;	\
}while(0)

#endif
