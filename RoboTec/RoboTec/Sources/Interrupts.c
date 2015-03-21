/*
 * Interrupts.c
 *
 * Created: 3/20/2015 9:13:06 PM
 *  Author: Marius
 */ 
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"
#include <avr/interrupt.h>


ISR (ADC_vect)
{
	if(count == 10000)
	{
		/*Store the previous value of the conversion*/
		adc_prevValue = adc_value;
	
		/*Store the current value of the conversion*/
		adc_value = ADC;
		
		count = 0;		
	}
	else
	{
		count++;
	}

}
