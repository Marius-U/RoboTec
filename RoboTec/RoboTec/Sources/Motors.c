/*
 * Motors.c
 *
 * Created: 3/21/2015 2:23:51 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/Motors.h"

void MotorControl(uint8_t state)
{
	
}

void backwards(uint8_t value)
{
	OCR1A = value;
	OCR1B = value;
	
	PORTC |= (1 << PORTC7);
	PORTB |= (1 << PORTB7);
	PORTF &= ~(1 << PORTF7);
	PORTB &= ~(1 << PORTB4);
}
void forward(uint8_t value)
{
	OCR1A = value;
	OCR1B = value + 10;
	
	PORTC &= ~(1 << PORTC7);
	PORTB &= ~(1 << PORTB7);
	PORTF |= (1 << PORTF7);
	PORTB |= (1 << PORTB4);
}
void left_f(uint8_t value, uint8_t direction)
{
	OCR1A = 0;
	OCR1B = value;
	
	PORTC |= (1 << PORTC7);
	PORTB |= (1 << PORTB7);
	PORTF &= ~(1 << PORTF7);
	PORTB &= ~(1 << PORTB4);
}
void right(uint8_t value, uint8_t direction)
{
	OCR1A = value;
	OCR1B = 0;
	
	PORTC |= (1 << PORTC7);
	PORTB |= (1 << PORTB7);
	PORTF &= ~(1 << PORTF7);
	PORTB &= ~(1 << PORTB4);
}