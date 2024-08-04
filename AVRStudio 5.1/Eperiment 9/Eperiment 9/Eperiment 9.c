#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#define RS 6
#define E 5

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);

int main(void) {
	DDRA = 0xff;
	DDRD = 0xff;
	_delay_ms(50);
	send_a_command(0x01);
	send_a_command(0x38);
	send_a_command(0x0e);
	send_a_character(0x41);
}

void send_a_command(unsigned char command) {
	PORTA = command;
	PORTD &= ~(1 << RS);
	PORTD |= (1 << E);
	_delay_ms(50);
	PORTD &= ~(1 << E);
	PORTA = 0;
}

void send_a_character(unsigned char character) {
	PORTA = character;
	PORTD |= (1 << RS);
	PORTD |= (1 << E);
	_delay_ms(50);
	PORTD &= ~(1 << E);
	PORTA = 0;
}