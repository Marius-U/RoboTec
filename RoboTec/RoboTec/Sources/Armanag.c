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
#include "/RoboTec/RoboTec/RoboTec/Headers/Motors.h"


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

void ProcessLineState(uint8_t mask)
{
	//switch(mask)
	//{
		//case 0b00000000:
		//break;
		//
		//case 0b00011000:
		//forward(speed(50));
		//break;
		//
		//case 0b00110000:
		//left_f(speed(70));
		//break;
		//
		//case 0b01100000:
		//left_f(speed(70));
		//break;
		//
		//case 0b11000000:
		//left_f(speed(70));
		//break;
		//
		//case 0b00001100:
		//right(speed(70));
		//break;		
		//
		//case 0b00000110:
		//right(speed(70));
		//break;
		//
		//case 0b00000011:
		//right(speed(70));
		//break;
		//
		//
		//
		//break;
	//}
}

