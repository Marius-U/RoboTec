/*
 * Interrupts.c
 *
 * Created: 3/20/2015 9:13:06 PM
 *  Author: Marius
 */ 
#include "/RoboTec/RoboTec/RoboTec/Headers/Interrupts.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"
#include <avr/interrupt.h>


ISR (ADC_vect)
{
	adc_value = ADC;
}
