/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __WAIT_H__

#define __WAIT_H__

int wait(int * status);
int waitpid(int pid, int *status, int options);

#endif
