/*
 * experiment5.c
 *
 * Created: 20-06-2024 10:28:52
 *  Author: USER
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRA = 0XFF;
	DDRB = 0XFF;
	DDRC = 0XFF;
	DDRD = 0XFF;
	unsigned char Data_in1 = 0X32;
	unsigned char Data_in2 = 0XAB;
	PORTA =~ PORTA;
	PORTB = Data_in1 | Data_in2;
	PORTC = Data_in1 & Data_in2;
	PORTD = Data_in1 ^ Data_in2;
	
    while(1);
	return 0;
}