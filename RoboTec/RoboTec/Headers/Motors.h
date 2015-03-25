/*
 * Motors.h
 *
 * Created: 3/21/2015 2:24:11 PM
 *  Author: Marius
 */ 


#ifndef MOTORS_H_
#define MOTORS_H_

#define speed(x) ((int)((float)x*(float)2.55))

void MotorControl(uint8_t state);
void backwards(uint8_t value);
void forward(uint8_t value);
void left_f(uint8_t value, uint8_t direction);
void right(uint8_t value, uint8_t direction);



#endif /* MOTORS_H_ */

