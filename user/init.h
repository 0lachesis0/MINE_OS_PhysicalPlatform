/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __TEST_H__

#define __TEST_H__

struct	buildincmd
{
	char *name;
	int (*function)(int,char**);
};

extern struct buildincmd shell_internal_cmd[];

extern char *current_dir;

#endif
