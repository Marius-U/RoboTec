/*
 * RoboTec.c
 *
 * Created: 3/19/2015 6:42:19 PM
 *  Author: Marius
 */ 

/*------------Defines--------------*/
#define TRESHOLD 0x1F4 //500
#define MAX_SENSOR	8

/*------------Includes-------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/PWM.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"

/*------------Declarations----------*/
unsigned char sFlag=1; 
uint8_t state = 0;
uint16_t adc_value = 0; 
uint16_t adc_prevValue = 0;
uint16_t count = 0;
uint8_t channel;
uint8_t sensor[MAX_SENSOR] = {0, 1, 4, 5, 6, 32, 33, 34}; /* Where: 0 - input selection for the ADCMUX that selects ADC0
																	1 - input selection for the ADCMUX that selects ADC1
																	4 - input selection for the ADCMUX that selects ADC4
																	5 - input selection for the ADCMUX that selects ADC5
																	6 - input selection for the ADCMUX that selects ADC6
																	32 - input selection for the ADCMUX that selects ADC8
																	33 - input selection for the ADCMUX that selects ADC9
																	34 - input selection for the ADCMUX that selects ADC10*/




/*------------Prototypes------------*/
char CheckSensor();
void MotorControl(uint8_t state);


int main(void)
{
	uint8_t aux;
	//cli();
	uart_init();
	ADC_interuptInit();
	//ADC_setADMUX(channel);
	uart_print("Initialisation finished.");
	adc_value = 123;
	sei();
	
    while(1)
    {

		
			aux = CheckSensor();
			
			//MotorControl(aux);
    }
}


char CheckSensor()
{
	while(TRESHOLD > adc_value)
	{
		//
		//uart_int_transmit(adc_value);
		//uart_transmit(channel+48);
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

void MotorControl(uint8_t state)
{
	
}
