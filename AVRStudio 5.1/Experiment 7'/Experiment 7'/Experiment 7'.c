/*
 * Experiment_7_.c
 *
 * Created: 26-06-2024 11:11:54
 *  Author: USER
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#define pin 3

int main(void)
{
	unsigned char conbyte = 0x44;
	unsigned char regalsb;
	unsigned char x;
	regalsb = conbyte;
	DDRC |= (1<<pin);
	for (x = 0; x < 8; x++)
	{
		if (regalsb & 0x01)
		{
			PORTC |= (1<<pin);
		}else{
			PORTC &= ~(1<<pin);
		}
		_delay_ms(1000);
		regalsb = regalsb >> 1;
	}
	return 0;
}