/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __DIRENT_H__

#define __DIRENT_H__

struct dirent
{
	long d_offset;
	long d_type;
	long d_namelen;
	char d_name[];
};


#endif
