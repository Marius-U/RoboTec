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
#include <util/delay.h>

/*------------Declarations----------*/
uint8_t sFlag=1; 
uint8_t state = 0;
volatile uint16_t adc_value = 0; 
volatile uint16_t adc_prevValue = 0;
volatile bool adcFlag;
volatile uint16_t count = 0;
uint8_t channel = 0;
uint8_t previousSpeed = 0;
uint8_t currentSpeed = 0;
uint8_t left_speed = 0;
uint8_t right_speed = 0;
uint8_t sensor[MAX_SENSOR] = {0, 1, 4, 5, 6, 32, 33, 34}; /* Where: 0 - selection input for the ADCMUX that selects ADC0
																	1 - selection input for the ADCMUX that selects ADC1
																	4 - selection input for the ADCMUX that selects ADC4
																	5 - selection input for the ADCMUX that selects ADC5
																	6 - selection input for the ADCMUX that selects ADC6
																	32 - selection input for the ADCMUX that selects ADC8
																	33 - selection input for the ADCMUX that selects ADC9
																	34 - selection input for the ADCMUX that selects ADC10*/

volatile uint8_t lineState; //stores the position of sensors on the line

/*---------------------prototypes--------------------------*/


int main(void)
{
	uint8_t aux;
	uint8_t state;
	
	
	//DIDR0 |= (1 << ADC0D) | (1 << ADC1D) | (1 << ADC4D) | (1 << ADC5D) | (1 << ADC6D);
	//DIDR2 |= (1 << ADC8D) | (1 << ADC9D) | (1 << ADC10D); 
	
	DDRB |=  (1<<DDB5) | (1<<DDB6) | (1 << DDB7) | (1 << DDB4);         //OCR1A and OCR1B...
	DDRC |= (1 << DDC7);
	
	DDRD &= ~(1 << DDD7);
	
	DDRB &= ~(1 << DDB0) & ~(1 << DDB1) & ~(1 << DDB2) & ~(1 << DDB3);
	DDRF &= ~(1 << DDF6) & ~(1 << DDF5) & ~(1 << DDF4);
	
	
	PORTB &= ~(1 << PORTB0) & ~(1 << PORTB1) & ~(1 << PORTB2) & ~(1 << PORTB3);
	PORTF &= ~(1 << PORTF4) & ~(1 << PORTF5) & ~(1 << PORTF6) ;
	PORTD &= ~(1 << PORTD7);
	
	DDRD |= (1 << DDD0);
	
	uart_init();                           //USART init
	//ADC_interuptInit();					   //ADC init
	pwm_init();                            //PWM init
	
	//
	uart_print("Initialisation finished.");
	//sei();
	//forward(speed(30));
	
    while(1)
    {
		lineState = CheckSensor();
	//	PORTD ^= 0x01; //DD0
		//_delay_ms(300);
		//uart_print_bits(lineState);
		ProcessLineState(lineState);

    }
}



