/*
 * USART.h
 *
 * Created: 3/19/2015 6:46:13 PM
 *  Author: Marius
 */ 


#ifndef USART_H_
#define USART_H_

/*------------Defines--------------*/
# define USART_BAUDRATE 115200
# define BAUD_PRESCALE ((( F_CPU / ( USART_BAUDRATE * 16UL))) - 1)

/*------------Prototypes--------------*/
void uart_transmit( unsigned char data );
void uart_print( char data[] );
void uart_int_transmit(unsigned int data);
void uart_int(unsigned int data);
unsigned char uart_receive(void);
void uart_init(void);
int uart_dataAvailable(void);
uint8_t uart_flush(void);
void uart_print_bits(uint8_t data);


#endif /* USART_H_ */