/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __UNISTD_H__

#define __UNISTD_H__

int close(int fildes);
long read(int fildes, void *buf, long nbyte);
long write(int fildes, const void *buf, long nbyte);
long lseek(int fildes, long offset, int whence);
long chdir(char *path);

int fork(void);
int vfork(void);
int execve(const char *path, char *const argv[], char *const envp[]);


#endif
