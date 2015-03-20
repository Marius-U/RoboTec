/*
 * RoboTec.c
 *
 * Created: 3/19/2015 6:42:19 PM
 *  Author: Marius
 */ 

/*------------Defines--------------*/
#define TRESHOLD 500

/*------------Includes-------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include"/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"
#include"/RoboTec/RoboTec/RoboTec/Driver/Headers/PWM.h"
#include"/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"

/*------------Declarations----------*/
unsigned char sFlag=1; 
uint16_t adc_value = 0; 
uint8_t channel;



/*------------Prototypes------------*/
char CheckSensor();
void MotorControl(uint8_t state);


int main(void)
{
	uint8_t aux;
	//cli();
		uart_init();
	ADC_interuptInit();

	
	
	uart_print("Initialisation finished");
	sei();
	
    while(1)
    {

		
			aux = CheckSensor();
			uart_int_transmit(adc_value);
			//MotorControl(aux);
    }
}


char CheckSensor()
{
	uint8_t state = 0;
	
	
	while(adc_value < TRESHOLD)
	{
		if(channel >= 8)
			channel = 0;
			
		//uart_print("adc_value");
		
		ADC_setADMUX(channel);
		channel += 1;
	}
	//Todo
	
	return state;
}

void MotorControl(uint8_t state)
{
	
}

ISR(ADC_vect)
{
	//cli();
	//adc_value = ADC;
	//uart_print("ADC value");
	
	//sei();
}
