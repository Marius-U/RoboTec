/*
 * RoboTec.c
 *
 * Created: 3/19/2015 6:42:19 PM
 *  Author: Marius
 */ 



/*------------Includes-------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "/RoboTec/RoboTec/RoboTec/Headers/main.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/ADC.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/PWM.h"
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/Armanag.h"
#include "/RoboTec/RoboTec/RoboTec/Headers/Motors.h"

/*------------Declarations----------*/
uint8_t sFlag=1; 
uint8_t state = 0;
uint16_t adc_value = 0; 
uint16_t adc_prevValue = 0;
uint16_t count = 0;
uint8_t channel = 0;
uint8_t sensor[MAX_SENSOR] = {0, 1, 4, 5, 6, 32, 33, 34}; /* Where: 0 - selection input for the ADCMUX that selects ADC0
																	1 - selection input for the ADCMUX that selects ADC1
																	4 - selection input for the ADCMUX that selects ADC4
																	5 - selection input for the ADCMUX that selects ADC5
																	6 - selection input for the ADCMUX that selects ADC6
																	32 - selection input for the ADCMUX that selects ADC8
																	33 - selection input for the ADCMUX that selects ADC9
																	34 - selection input for the ADCMUX that selects ADC10*/

int main(void)
{
	uint8_t aux;

	uart_init();
	ADC_interuptInit();
	uart_print("Initialisation finished.");
	sei();
	
    while(1)
    {
			aux = CheckSensor();
			MotorControl(aux);
    }
}



