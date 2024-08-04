/*
 * Experimet_7.c
 *
 * Created: 27-06-2024 13:55:08
 *  Author: USER
 */ 

#include <avr/io.h>

int main(void)
{
	unsigned char bcdbyte;
	unsigned char w='4';
	unsigned char z='7';
	DDRB=0xff;
	w=w&0x0f;
	w=w<<4;
	z=z&0x0f;
	bcdbyte=w|z;
	PORTB=bcdbyte;
	return 0;
}