/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#include "waitqueue.h"
#include "task.h"
#include "lib.h"

void wait_queue_init(wait_queue_T * wait_queue,struct task_struct *tsk)
{
	list_init(&wait_queue->wait_list);
	wait_queue->tsk = tsk;
}

void sleep_on(wait_queue_T * wait_queue_head)
{
	wait_queue_T wait;
	wait_queue_init(&wait,current);
	current->state = TASK_UNINTERRUPTIBLE;
	list_add_to_before(&wait_queue_head->wait_list,&wait.wait_list);

	schedule();
}

void interruptible_sleep_on(wait_queue_T *wait_queue_head)
{
	wait_queue_T wait;
	wait_queue_init(&wait,current);
	current->state = TASK_INTERRUPTIBLE;
	list_add_to_before(&wait_queue_head->wait_list,&wait.wait_list);

	schedule();
}

void wakeup(wait_queue_T * wait_queue_head,long state)
{
	wait_queue_T * wait = NULL;

	if(list_is_empty(&wait_queue_head->wait_list))
		return;

	wait = container_of(list_next(&wait_queue_head->wait_list),wait_queue_T,wait_list);

	if(wait->tsk->state & state)
	{
		list_del(&wait->wait_list);
		wakeup_process(wait->tsk);
	}
}


