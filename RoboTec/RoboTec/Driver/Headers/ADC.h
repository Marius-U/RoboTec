/*
 * ADC.h
 *
 * Created: 3/19/2015 6:45:43 PM
 *  Author: Marius
 */ 


#ifndef ADC_H_
#define ADC_H_

void ADC_init();
void ADC_interuptInit();
void ADC_setADMUX(uint8_t channel);
uint16_t ADC_read();


#endif /* ADC_H_ */
