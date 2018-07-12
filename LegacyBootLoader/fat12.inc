;/***************************************************
;		 Copyright (c) 2018 MINE 田宇
;
; This program is free software; you can redistribute it and/or
; modify it under the terms of version 2 of the GNU General Public
; License as published by the Free Software Foundation.
;
;***************************************************/

RootDirSectors			equ	14
SectorNumOfRootDirStart	equ	25
SectorNumOfFAT1Start	equ	1

	BS_OEMName	db	'MINEboot'
	BPB_BytesPerSec	dw	0x200
	BPB_SecPerClus	db	0x8
	BPB_RsvdSecCnt	dw	0x1
	BPB_NumFATs	db	0x2
	BPB_RootEntCnt	dw	0xe0
	BPB_TotSec16	dw	0x7d82
	BPB_Media	db	0xf0
	BPB_FATSz16	dw	0xc
	BPB_SecPerTrk	dw	0x3f
	BPB_NumHeads	dw	0xff
	BPB_hiddSec	dd	0
	BPB_TotSec32	dd	0
	BS_DrvNum	db	0
	BS_Reserved1	db	0
	BS_BootSig	db	29h
	BS_VolID	dd	0
	BS_VolLab	db	'boot loader'
	BS_FileSysType	db	'FAT12   '

