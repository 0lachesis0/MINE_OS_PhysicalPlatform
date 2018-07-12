/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#include "wait.h"

int wait(int * status)
{
	return wait4((int)-1, status, 0);
}

int waitpid(int pid, int *status, int options)
{
	return wait4(pid, status, options);
}
