
/*
 * main.h
 *
 * Created: 3/20/2015 8:39:32 PM
 *  Author: Marius
 */ 

/*------------Includes-------------*/
#include <avr/io.h>
#include <stdbool.h>

/*------------Defines--------------*/
#define F_CPU 16000000UL
#define TRESHOLD  0x1F4 //500
#define MAX_SENSOR	8
#define SENSOR1 0
#define SENSOR2 1
#define SENSOR3	4
#define SENSOR4 5
#define SENSOR5 6
#define SENSOR6 32
#define SENSOR7 33
#define SENSOR8 34



/*------------Extern variables--------------*/
extern volatile uint16_t adc_value;
extern volatile uint16_t adc_prevValue; 
extern volatile uint16_t count;
extern volatile bool adcFlag;
extern uint8_t channel;
extern uint8_t sensor[MAX_SENSOR];
extern uint8_t state;
extern uint8_t sFlag;
extern volatile uint8_t lineState;

