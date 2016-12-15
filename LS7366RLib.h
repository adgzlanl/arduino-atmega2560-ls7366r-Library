/*
 Name:		LS7366RLib.h
 Created:	5/16/2016 4:15:49 PM
 Author:	Anil Adiguzel
 Editor:	http://www.visualmicro.com
*/

#ifndef _LS7366RLib_h
#define _LS7366RLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif


//****************************STR(Status Register ) 8 bit*********************************

//*************************************************
//STR bits CY-BW-CMP-IDX-CEN-PLS-U/D-S               *
//*************************************************
#define S_BIT   = 0X00
//Select Byte Mode S bit as follows
#define	UD_BIT  = 0X01
//Select Byte Mode U/D bit as follows
#define	PLS_BIT = 0X02
//Select Byte Mode PLS bit as follows
#define	CEN_BIT = 0X04
//Select Byte Mode CEN bit as follows
#define	IDX_BIT = 0X10
//Select Byte Mode IDX bit as follows
#define	CMP_BIT = 0X20
//Select Byte Mode CMP bit as follows
#define	BW_BIT  = 0X40
//Select Byte Mode BW bit as follows
#define	CY_BIT  = 0X80
//Select Byte Mode CY bit as follows


//****************************************************************************************	








//************************IR (Instruction Register 0)  8 bit************************************ 

//*************************************************
//IR bits B7-B6-B5-B4-B3-B2-B1-B0               *
//*************************************************


//Clear Functions

#define CLR_MDR0  0x08 // 0 0 0 0 1 B2 B1 B0
#define CLR_MDR1  0x10 // 0 0 0 1 0 B2 B1 B0
#define CLR_DTR   0x18 // 0 0 0 1 1 B2 B1 B0
#define CLR_CNTR  0x20 // 0 0 1 0 0 B2 B1 B0
#define CLR_OTR   0X28 // 0 0 1 0 1 B2 B1 B0
#define CLR_STR   0X30 // 0 0 1 1 0 B2 B1 B0

//Read Functions

#define RD_MDR0  0x48 // 0 1 0 0 1 B2 B1 B0
#define RD_MDR1  0x50 // 0 1 0 1 0 B2 B1 B0
#define RD_DTR   0x58 // 0 1 0 1 1 B2 B1 B0
#define RD_CNTR  0x60 // 0 1 1 0 0 B2 B1 B0
#define RD_OTR   0X68 // 0 1 1 0 1 B2 B1 B0
#define RD_STR   0X70 // 0 1 1 1 0 B2 B1 B0

//Write Functions

#define WR_MDR0  0x88 // 1 0 0 0 1 B2 B1 B0
#define WR_MDR1  0x90 // 1 0 0 1 0 B2 B1 B0
#define WR_DTR   0x98 // 1 0 0 1 1 B2 B1 B0
#define WR_CNTR  0xA0 // 1 0 1 0 0 B2 B1 B0
#define WR_OTR   0XA8 // 1 0 1 0 1 B2 B1 B0
//Load Functions

#define LD_CNTR  0xE0 // 1 1 1 0 0 B2 B1 B0
#define LD_OTR   0XE8 // 1 1 1 0 1 B2 B1 B0









//************************MDR0 (Mode Register 0)  8 bit************************************ 

//*************************************************
//MDR0 bits B7-B6-B5-B4-B3-B2-B1-B0               *
//*************************************************


//Select quadrature Mode B1:B0 bits as follows
#define	NON_QUAD  0x0 // B7 B6 B5 B4 B3 B2 00
#define	X1_QUAD   0x01 // B7 B6 B5 B4 B3 B2 01
#define	X2_QUAD   0x02 // B7 B6 B5 B4 B3 B2 10
#define	X4_QUAD   0x03 // B7 B6 B5 B4 B3 B2 11

// Select Count Mode  B3:B2 bits as follows
#define	FREE_RUN       0x00  // B7 B6 B5 B4 00 B1 B0
#define	SINGLE_CYCLE   0x04  // B7 B6 B5 B4 01 B1 B0
#define	RANGE_LIMIT    0x08  // B7 B6 B5 B4 10 B1 B0
#define	MOD_N_CNT      0x0C  // B7 B6 B5 B4 11 B1 B0

//Select  Index Mode B5:B4 bits as follows
#define	DISABLE_IDX 0x00	  // B7 B6 00 B3 B2 B1 B0
#define	LOAD_CNTR   0x10   // B7 B6 01 B3 B2 B1 B0
#define	RST_CNTR    0x20  // B7 B6 10 B3 B2 B1 B0
#define	LOAD_OTR    0x30	  // B7 B6 11 B3 B2 B1 B0	

//Select Sync Mode B6 bit as follows
#define	ASYN_IDX     0x00  // B7 0 B5 B4 B3 B2 B1 B0
#define	SYN_IDX      0x40  // B7 1 B5 B4 B3 B2 B1 B0

//Select Filter Clock Division Mode B7 as follows
#define	CLK_DIV_1    0x00  // 0 B6 B5 B4 B3 B2 B1 B0
#define	CLK_DIV_2    0x80  // 1 B6 B5 B4 B3 B2 B1 B0

//****************************************************************************************




//****************************MDR1(Mode Register 1) 8 bit*********************************

//*************************************************
//MDR1 bits B7-B6-B5-B4-B3-B2-B1-B0               *
//*************************************************

//Select Byte Mode B1:B0 bits as follows
#define	FOUR_BYTE  0x00      // B7 B6 B5 B4 B3 B2 00
#define	THREE_BYTE 0x01     // B7 B6 B5 B4 B3 B2 01
#define	TWO_BYTE   0x02       // B7 B6 B5 B4 B3 B2 10
#define	ONE_BYTE   0x03       // B7 B6 B5 B4 B3 B2 11

// Select Enable Count Mode B2 bit as follows
#define	ENABLE_CNT   0x00     // B7 B6 B5 B4 B3 0 B1 B0
#define	DISABLE_CNT  0x04    // B7 B6 B5 B4 B3 1 B1 B0

//  B3 bit not used

// Select FLAG INDEX Mode B4 bit as follows
#define	FLAG_IDX   0x10	   // B7 B6 B5 1 B3 B2 B1 B0

// Select FLAG COMPARE Mode B5 bit as follows
#define	FLAG_CMP   0x20       // B7 B6 1 B4 B3 B2 B1 B0

// Select FLAG BORROW Mode B6 bit as follows
#define	FLAG_BW    0x40        // B7 1 B5 B4 B3 B2 B1 B0

// Select FLAG CARRY-OVER Mode B7 bit as follows
#define	FLAG_CY   0x80	      // 1 B6 B5 B4 B3 B2 B1 B0

//****************************************************************************************

#define	SEND_ZERO 0x00

class LS7366R
{

public:
	LS7366R(int);
	LS7366R(int,byte,byte);
	void ResetEncoder();
	int32_t ReadEncoder();


private:
	int SS;


};