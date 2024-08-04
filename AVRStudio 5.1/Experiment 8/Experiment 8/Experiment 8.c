/*
 * Experiment_8.c
 *
 * Created: 04-07-2024 13:19:14
 *  Author: USER
 */ 

#include <avr/io.h>

int main(void)
{
    unsigned char x,y;
	unsigned char mybyte = 0x29;
	DDRB = DDRC = 0xff;
	x = mybyte&0x0f;
	PORTB = x | 0x30;
	y = mybyte&0xf0;
	y = y >> 4;
	PORTC = y | 0x30;
	return 0;
}