/*
 * experiment4.c
 *
 * Created: 20-06-2024 09:43:10
 *  Author: USER
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA = 0XFF;
	DDRB = 0XFF;
	DDRC = 0b00000000;
	PORTC = 0b00000010;
    while(1)
    {
        if (PINC&0b00000010)
        {
			PORTB = 0X10;
        } 
        else
        {
			PORTB = 0XAA;
        }
    }
	return 0;
}