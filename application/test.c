/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#include "stdio.h"
#include "stdlib.h"

int main(int argc,char *argv[])
{
	int i = 0;
	printf("Hello World!\n");
	printf("argc:%d,argv:%#018lx\n",argc,argv);
	for(i = 0;i<argc;i++)
		printf("argv[%d]:%s\n",i,argv[i]);
	exit(0);
	return 0;
}

