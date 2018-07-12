/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __KEYBOARD_H__

#define __KEYBOARD_H__


#define NR_SCAN_CODES 	0x80
#define MAP_COLS	2


#define PAUSEBREAK	1
#define PRINTSCREEN	2
#define OTHERKEY	4
#define FLAG_BREAK	0x80

/*

*/

extern int shift_l,shift_r,ctrl_l,ctrl_r,alt_l,alt_r;

extern unsigned char pausebreak_scode[];

extern unsigned int keycode_map_normal[NR_SCAN_CODES * MAP_COLS];

#endif
