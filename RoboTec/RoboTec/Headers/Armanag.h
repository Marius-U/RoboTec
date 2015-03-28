/*
 * Armanag.h
 *
 * Created: 3/21/2015 2:15:41 PM
 *  Author: Marius
 */ 


#ifndef ARMANAG_H_
#define ARMANAG_H_

/*---------Defines-----------*/
#define SPEED 110
//#define CORECTION_MAX_SPEED 160
//#define CORECTION_MIN_SPEED 140
#define PREVIOUS_COMAND 0x00
#define ACUTE_ANGLE_LEFT 0x01
#define ACUTE_ANGLE_RIGHT 0x02
#define MAX_RADIUS 100
#define MIN_RADIUS 15

/*---------Prototipes---------*/
uint8_t CheckSensor();
void ProcessLineState(uint8_t mask);
uint8_t getRatio(float omega, float r);
float getOmega(uint8_t angle);



#endif /* ARMANAG_H_ */