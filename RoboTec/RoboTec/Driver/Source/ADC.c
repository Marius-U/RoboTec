/*
 * ADC.c
 *
 * Created: 3/19/2015 6:45:24 PM
 *  Author: Marius
 */ 
#include <avr/io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


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
	ADMUX &= 0xF0;
	ADMUX |= channel; 
	//ADCSRA |= (1 << ADSC); //Start the ADC conversion
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