/*
 * AVRGCC3.c
 *
 * Created: 30-11-2023 09:18:32
 *  Author: USER
 */ 

#include <avr/io.h>

int main(void)
{
    DDRA=0XFF;
	DDRB=0X00;
	DDRC=0XFF;
	if(PINB & 0XFF)
	{
		PORTC=0XAA;
	}
	else 
	{
		PORTA=0X12;
	}
}					