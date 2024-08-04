/*
 * Experiment_6.c
 *
 * Created: 26-06-2024 09:25:35
 *  Author: USER
 */ 

#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	char myList[] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
		unsigned char z;
		DDRB = 0xff;
		for (z = 0; z <= 8; z++)
		{
			PORTB = myList[z];
			_delay_ms(1200);
		}
		while(1);
		return 0;
}