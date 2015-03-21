/*
 * ADC.c
 *
 * Created: 3/19/2015 6:45:24 PM
 *  Author: Marius
 */ 

/*------------Includes-------------*/
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"

void ADC_init()
{
	ADMUX |= (1 << REFS0) | (1 << REFS1); //Foloseste referinta
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1<<ADPS0); //Prescaler pentru 16Mhz
	ACSR |= (1 << ACD);

}

void ADC_interuptInit()
{
		ADMUX |= (1 << REFS0) | (1 << REFS1); //Foloseste referinta
		ADCSRA |=  (1<<ADATE) | (1<<ADIE) ; //Prescaler pentru 16Mhz //(1 << ADPS2) | (1 << ADPS1) | (1<<ADPS0) |
		//ACSR |= (1 << ACD);    //Analog Comparator is switched off when ACD is set.
		ADCSRB |= (1<<ADHSM);
		ADCSRA |= (1<<ADEN);
		ADCSRA |= (1 << ADSC); //Start the ADC conversion
}

void ADC_setADMUX(uint8_t channel)
{
	switch(channel)
	{
		case SENSOR1 :
		{
			ADCSRB &= ~(1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX &= ~(1 << MUX2);
			ADMUX &= ~(1 << MUX1);
			ADMUX &= ~(1 << MUX0);
		}
		break;
		case SENSOR2 :
		{
			ADCSRB &= ~(1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX &= ~(1 << MUX2);
			ADMUX &= ~(1 << MUX1);
			ADMUX |= (1 << MUX0);			
		}
		break;
		case SENSOR3 :
		{
			ADCSRB &= ~(1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);	
			ADMUX |= (1 << MUX2);
			ADMUX &= ~(1 << MUX1);
			ADMUX &= ~(1 << MUX0);			
		}
		break;
		case SENSOR4 :
		{
			ADCSRB &= ~(1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX |= (1 << MUX2);
			ADMUX &= ~(1 << MUX1);
			ADMUX |= (1 << MUX0);			
		}
		break;
		case SENSOR5 :
		{
			ADCSRB &= ~(1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX |= (1 << MUX2);
			ADMUX |= (1 << MUX1);
			ADMUX &= ~(1 << MUX0);
		}
		break;
		case SENSOR6 :
		{
			ADCSRB |= (1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX &= ~(1 << MUX2);
			ADMUX &= ~(1 << MUX1);
			ADMUX &= ~(1 << MUX0);
		}
		break;
		case SENSOR7 :
		{
			ADCSRB |= (1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX &= ~(1 << MUX2);
			ADMUX &= ~(1 << MUX1);
			ADMUX |= (1 << MUX0);			
		}
		break;
		case SENSOR8 :
		{
			ADCSRB |= (1 << MUX5);
			ADMUX &= ~(1 << MUX4);
			ADMUX &= ~(1 << MUX3);
			ADMUX &= ~(1 << MUX2);
			ADMUX |= (1 << MUX1);
			ADMUX &= ~(1 << MUX0);			
		}
		break;
		
		default:
		{
			//TODO on default.
		}
	}
}

uint16_t ADC_read()//unsigned int adc_in)
{
	uint16_t x;
	
	ADMUX  = 4;
	ADCSRA |= (1 << ADEN);
	ADCSRA |= (1 << ADSC); //Start the ADC conversion
	while (ADCSRA & (1 <<ADSC))
	;
	
	x= ADC;

	return x;
}