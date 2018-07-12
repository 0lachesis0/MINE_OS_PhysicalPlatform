/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/

#ifndef __BLOCK_H__

#define __BLOCK_H__



struct block_device_operation
{
	long (* open)();
	long (* close)();
	long (* ioctl)(long cmd,long arg);
	long (* transfer)(long cmd,unsigned long blocks,long count,unsigned char * buffer);
};

#endif
