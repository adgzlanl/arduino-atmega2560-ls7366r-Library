/*
 Name:		LS7366RLib.cpp
 Created:	5/16/2016 4:15:49 PM
 Author:	Anil Adiguzel
 Editor:	http://www.visualmicro.com
*/

#include "LS7366RLib.h"
#include <SPI.h>

/*
LS7366R - Library for LS7366R IC Decoder .
Created by Anil Adiguzel / www.about.me / aniladiguzel, MAY 12, 2016.
Released into the public domain.
*/








// InitEncoder
LS7366R::LS7366R(int SelectSlave)
{

	SS = SelectSlave;
	pinMode(SS, OUTPUT);
	digitalWrite(SS, HIGH);
	SPI.begin();

	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR0);
	SPI.transfer(X4_QUAD);
	digitalWrite(SS, HIGH);

	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR0);
	SPI.transfer(FREE_RUN);
	digitalWrite(SS, HIGH);

	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR0);
	SPI.transfer(DISABLE_IDX);
	digitalWrite(SS, HIGH);

	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR0);
	SPI.transfer(ASYN_IDX);
	digitalWrite(SS, HIGH);

	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR0);
	SPI.transfer(CLK_DIV_2);
	digitalWrite(SS, HIGH);

	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR1);
	SPI.transfer(FOUR_BYTE);
	digitalWrite(SS, HIGH);


	digitalWrite(SS, LOW);
	SPI.transfer(WR_MDR1);
	SPI.transfer(ENABLE_CNT);
	digitalWrite(SS, HIGH);

}

LS7366R::LS7366R(int SlaveSelect, byte Instruction, byte RegisterBit)
{
	digitalWrite(SS, LOW);
	SPI.transfer(Instruction);
	SPI.transfer(RegisterBit);
	digitalWrite(SS, HIGH);
}

void LS7366R::ResetEncoder()
{
	digitalWrite(SS, LOW);
	SPI.transfer(WR_DTR);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	SPI.transfer(0x00);
	digitalWrite(SS, HIGH);

	digitalWrite(SS, LOW);
	SPI.transfer(LD_CNTR);
	digitalWrite(SS, HIGH);
}

// Read Encoder
int32_t LS7366R::ReadEncoder()
{
	int32_t count_value;
	int32_t count_1, count_2, count_3, count_4;
	digitalWrite(SS, LOW);
	SPI.transfer(RD_CNTR);
	count_1 = SPI.transfer(0x00);
	count_2 = SPI.transfer(0x00);
	count_3 = SPI.transfer(0x00);
	count_4 = SPI.transfer(0x00);
	digitalWrite(SS, HIGH);

	count_value = (count_1 << 24) + (count_2 << 16) + (count_3 << 8) + (count_4);

	return count_value;
}