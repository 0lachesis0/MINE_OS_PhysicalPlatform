/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __SEMAPHORE_H__

#define __SEMAPHORE_H__

#include "atomic.h"
#include "lib.h"
#include "task.h"
#include "schedule.h"
#include "waitqueue.h"

typedef struct 
{
	atomic_T counter;
	wait_queue_T wait;
} semaphore_T;

void semaphore_init(semaphore_T * semaphore,unsigned long count);

void semaphore_up(semaphore_T * semaphore);

void semaphore_down(semaphore_T * semaphore);

#endif
