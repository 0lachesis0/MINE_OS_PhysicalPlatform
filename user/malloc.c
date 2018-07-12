/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#include "stddef.h"
#include "limits.h"
#include "stdio.h"
#include "string.h"

static unsigned long brk_start_address = 0;
static unsigned long brk_used_address = 0;
static unsigned long brk_end_address = 0;

#define	SIZE_ALIGN	(8 * sizeof(unsigned long))

void * malloc(long size)
{
	char buf[1000];
	unsigned long address = 0;

	if(size <= 0)
	{
		printf("malloc size <= 0\n");
		return NULL;
	}

	if(brk_start_address == 0)
		brk_end_address = brk_used_address = brk_start_address = brk(0);

	if(brk_end_address <= brk_used_address + SIZE_ALIGN + size)
		brk_end_address = brk(brk_end_address + ((size + SIZE_ALIGN + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1)));

	address = brk_used_address;
	brk_used_address += size + SIZE_ALIGN;

	return (void *)address;
}


void free(void * address)
{
}



