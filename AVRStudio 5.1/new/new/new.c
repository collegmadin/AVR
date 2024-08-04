/*
 * new.c
 *
 * Created: 13-06-2024 15:42:02
 *  Author: exam
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA = 0b11111111;
	PORTA = 0b00000000;
    while(1)
    {
        _delay_ms(1000);
		PORTA =~ PORTA;
    }
}