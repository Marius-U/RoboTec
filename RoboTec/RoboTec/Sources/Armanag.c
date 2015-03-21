/*
 * Armanag.c
 *
 * Created: 3/21/2015 2:15:22 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include "/RoboTec/RoboTec/RoboTec/Headers/Armanag.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"


char CheckSensor()
{
	while(TRESHOLD > adc_value)
	{
		uart_transmit('A');
		uart_transmit(':');
		uart_int_transmit(adc_value);
		uart_transmit('C');
		uart_transmit(':');
		uart_transmit(channel+48);
		uart_transmit('\r');
		uart_transmit('\n');
		
		if(channel >= 8)
		{
			channel = 0;
		}
		else
		{
			ADC_setADMUX(sensor[channel]);
			channel += 1;
		}
		
	}

	return state;
}