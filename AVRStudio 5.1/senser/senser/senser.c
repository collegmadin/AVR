#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>
#include <stdlib.h>
#define enable 5
#define registerselection 6

void send_a_command(unsigned char command);
void send_a_charecter(unsigned char charecter);
void send_a_string(char *string_of_charecter);

int main(void) {
	DDRB = 0xff;
	DDRA = 0;
	DDRD = 0xff;
	_delay_ms(50);
	ADMUX |= (1<<REFS0)|(1<<REFS1);
	ADCSRA |= (1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	int16_t COUNTA = 0;
	char SHOWA[3];
	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	
	ADCSRA |= (1<<ADSC);
	while (1)
	{
		COUNTA = ADC/4;
		send_a_string("Temp(c)=");
		send_a_command(0x80+0x40+8);
		itoa(COUNTA, SHOWA, 10);
		send_a_string(" ");
		send_a_command(0x80+0);
	}
}

void send_a_command(unsigned char command) {
	PORTB = command;
	PORTD &=~(1<<registerselection);
	PORTD |= 1<<enable;
	_delay_ms(20);
	PORTD &= ~1<<enable;
	PORTB=0;
}

void send_a_charecter(unsigned char charecter) {
	PORTB=charecter;
	PORTD|=1<<registerselection;
	PORTD|=1<<enable;
	_delay_ms(20);
	PORTD &= ~1<<enable;
	PORTB=0;
}

void send_a_string(char *string_of_charecter) {
	while(*string_of_charecter>0) {
		send_a_charecter(*string_of_charecter++);
	}
}