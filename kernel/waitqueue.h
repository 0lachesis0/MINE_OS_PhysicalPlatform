/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __WAITQUEUE_H__

#define __WAITQUEUE_H__

#include "lib.h"

typedef struct
{
	struct List wait_list;
	struct task_struct *tsk;
} wait_queue_T;

void wait_queue_init(wait_queue_T * wait_queue,struct task_struct *tsk);

void sleep_on(wait_queue_T * wait_queue_head);

void interruptible_sleep_on(wait_queue_T *wait_queue_head);

void wakeup(wait_queue_T * wait_queue_head,long state);

#endif
