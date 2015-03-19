/*
 * PWM.h
 *
 * Created: 3/19/2015 6:47:28 PM
 *  Author: Marius
 */ 


#ifndef PWM_H_
#define PWM_H_

void pwm_init();
void backwords(uint8_t value);
void forward(uint8_t value);
void left_f(uint8_t value, uint8_t direction);
void right(uint8_t value, uint8_t direction);

#endif /* PWM_H_ */