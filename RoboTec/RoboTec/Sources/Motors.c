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
	uint8_t tempSpeed = 0;
	int16_t count = 0;
	
	PORTC &= ~(1 << PORTC7);
	PORTB &= ~(1 << PORTB7);
	PORTF |= (1 << PORTF7);
	PORTB |= (1 << PORTB4);
	OCR1A = value;
	OCR1B = value + 5;	
}
void steer(uint8_t value_right, uint8_t value_left)
{
	OCR1A = value_left;
	OCR1B = value_right;
	
	PORTC &= ~(1 << PORTC7);
	PORTB &= ~(1 << PORTB7);
	PORTF |= (1 << PORTF7);
	PORTB |= (1 << PORTB4);
}
