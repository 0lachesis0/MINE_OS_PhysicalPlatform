/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __TIME_H__

#define __TIME_H__

struct time
{
	int second;	//00
	int minute;	//02
	int hour;	//04
	int day;	//07
	int month;	//08
	int year;	//09+32
};

extern struct time time;
	
#define	BCD2BIN(value)	(((value) & 0xf) + ((value) >> 4 ) * 10)

void get_cmos_time(struct time *time);

#endif
