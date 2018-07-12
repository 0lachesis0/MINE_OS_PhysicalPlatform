/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#include "dirent.h"
#include "unistd.h"
#include "fcntl.h"
#include "stddef.h"
#include "stdlib.h"

struct DIR* opendir(const char *path)
{
	int fd = 0;
	struct DIR* dir = NULL;

	fd = open(path,O_DIRECTORY);

	if(fd >= 0)
		dir = (struct DIR*)malloc(sizeof(struct DIR));
	else
		return NULL;
	memset(dir,0,sizeof(struct DIR));
	dir->fd = fd;
	dir->buf_pos = 0;
	dir->buf_end = 256;
	
	return dir;
}

int closedir(struct DIR *dir)
{
	close(dir->fd);
	free(dir);
	return 0;
}

struct dirent *readdir(struct DIR *dir)
{
	int len = 0;
	memset(dir->buf,0,256);
	len = getdents(dir->fd,(struct dirent *)dir->buf,256);
	if(len > 0)
		return (struct dirent *)dir->buf;
	else
		return NULL;
}

