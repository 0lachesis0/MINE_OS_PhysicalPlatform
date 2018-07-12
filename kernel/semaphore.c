/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#include "atomic.h"
#include "lib.h"
#include "task.h"
#include "schedule.h"
#include "waitqueue.h"
#include "semaphore.h"


void semaphore_init(semaphore_T * semaphore,unsigned long count)
{
	atomic_set(&semaphore->counter,count);
	wait_queue_init(&semaphore->wait,NULL);
}

void __up(semaphore_T * semaphore)
{
	wait_queue_T * wait = container_of(list_next(&semaphore->wait.wait_list),wait_queue_T,wait_list);

	list_del(&wait->wait_list);
	wait->tsk->state = TASK_RUNNING;
	insert_task_queue(wait->tsk);
	current->flags |= NEED_SCHEDULE;
}

void semaphore_up(semaphore_T * semaphore)
{
	if(list_is_empty(&semaphore->wait.wait_list))
		atomic_inc(&semaphore->counter);
	else
		__up(semaphore);
}

void __down(semaphore_T * semaphore)
{
	wait_queue_T wait;
	wait_queue_init(&wait,current);
	current->state = TASK_UNINTERRUPTIBLE;
	list_add_to_before(&semaphore->wait.wait_list,&wait.wait_list);

	schedule();
}

void semaphore_down(semaphore_T * semaphore)
{
	if(atomic_read(&semaphore->counter) > 0)
		atomic_dec(&semaphore->counter);
	else
		__down(semaphore);
}

