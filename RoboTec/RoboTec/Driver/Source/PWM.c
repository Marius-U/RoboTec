/*
 * PWM.c
 *
 * Created: 3/19/2015 6:46:54 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/PWM.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"

void pwm_init()
{
	//Set the direction pins as output for the motor driver.
	DDRB |= (1 << DDB4) | (1 << DDB7);
	DDRC |= (1 << DDC7);
	DDRF |= (1 << DDF7);
	DDRB |= (1 << DDB5)|(1 << DDB6);//PWM pins
	
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM13) | (1 <<WGM12);
	TCCR1B |= (1 << CS10);
	ICR1=0xFF;
	uart_print("PWM initialization finished!\r\n");
	//uart_flush();
	
}
