/*
 * experiment2.c
 *
 * Created: 20-06-2024 09:22:07
 *  Author: USER
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA = 0x00; //input
	DDRB = 0XFF; //output
	PORTA = 0XFF; //initially on its light
    while(1)
    {
		if (!(PINA&(1<<PA0))) //check port a on or off
		{
			PORTB = 0XFF; // set port b is on
		}else{
			PORTB = 0X00; //set port b is off
		}			
    }
	return 0;
}