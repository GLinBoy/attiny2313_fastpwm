/*
 * PWM2313.cpp
 *
 * Created: 9/8/2017 4:39:08 PM
 * Author : Hojjat Abedie
 */ 
 
#define F_CPU 20000000UL

#include <avr/io.h>
#include <util/delay.h>

void setup() {
	DDRB |= 1 << DDB3 | 1 << DDB4;
	TCCR1A = (1<<WGM10)|(1<<COM1A1)|(1<<COM1B1);//setup PMW, no prescaler
	TCCR1B = (1<<WGM12)|(1<<CS11)|(1<<CS10);
	//OCR1 = 0xC0; //set 75% duty cycle
	DDRD = 0xFF;
}

int main(void)
{
	setup();
    
	OCR1A = 127;
	OCR1B = 0x00;

    while (1) 
    {
		PORTD = 0xFF;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
    }
}

