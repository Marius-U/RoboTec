/*
 * RoboTec.c
 *
 * Created: 3/19/2015 6:42:19 PM
 *  Author: Marius
 */ 



/*------------Includes-------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/PWM.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/Armanag.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/Motors.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/LCD_control.h"

/*------------Declarations----------*/
uint8_t sFlag=1; 
uint8_t state = 0;
volatile uint16_t adc_value = 0; 
volatile uint16_t adc_prevValue = 0;
volatile bool adcFlag;
volatile uint16_t count = 0;
uint8_t channel = 0;
uint8_t sensor[MAX_SENSOR] = {0, 1, 4, 5, 6, 32, 33, 34}; /* Where: 0 - selection input for the ADCMUX that selects ADC0
																	1 - selection input for the ADCMUX that selects ADC1
																	4 - selection input for the ADCMUX that selects ADC4
																	5 - selection input for the ADCMUX that selects ADC5
																	6 - selection input for the ADCMUX that selects ADC6
																	32 - selection input for the ADCMUX that selects ADC8
																	33 - selection input for the ADCMUX that selects ADC9
																	34 - selection input for the ADCMUX that selects ADC10*/

volatile uint8_t lineState;
int main(void)
{
	uint8_t aux;
	uint8_t state;
	
	
	DIDR0 |= (1 << ADC0D) | (1 << ADC1D) | (1 << ADC4D) | (1 << ADC5D) | (1 << ADC6D);
	DIDR2 |= (1 << ADC8D) | (1 << ADC9D) | (1 << ADC10D); 
	
	DDRB |= (1<<DDB5) | (1<<DDB6) | (1 << DDB7) | (1 << DDB4);         //OCR1A and OCR1B...
	DDRC |= (1 << DDC7);
	DDRF |= (1 << DDF7);

	
	uart_init();                           //USART init
	ADC_interuptInit();					   //ADC init
	pwm_init();                            //PWM init
	
	
	uart_print("Initialisation finished.");
	sei();
	
    while(1)
    {
		//	aux = CheckSensor();
		//	MotorControl(aux);
    }
}



