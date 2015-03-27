/*
 * USART.c
 *
 * Created: 3/19/2015 6:46:33 PM
 *  Author: Marius
 */ 

/*------------Includes-------------*/
#include <avr/io.h>
#include <stdlib.h>
#include <string.h>
#include <avr/interrupt.h>
#include "/RoboTec/RoboTec/RoboTec/Driver/Headers/USART.h"



/*------------Declarations----------*/
unsigned char a[5];
volatile int valid=0;


// transmit a char to uart
void uart_transmit( unsigned char data )
{
	// wait for empty transmit buffer
	while ( ! ( UCSR1A & ( 1 << UDRE1 ) ) )
	;
	
	// put data into buffer, sends data
	UDR1 = data;
}
// write a string to the uart
void uart_print( char data[] )
{
	//cli();
	uint8_t count = 0;
	uint8_t length = strlen(data);
	
	for ( count = 0; count < length; count++ )
	uart_transmit(data[count]);
	
	uart_transmit('\r');
	uart_transmit('\n');
	//sei();
}
void uart_print_bits(uint8_t data)
{
	uint8_t temp = data;
	uart_int_transmit(data);
	
	while(temp > 0)
	{
		uart_transmit((temp%2)+48);
		temp = temp/2;
	}
	uart_transmit('\r');
	uart_transmit('\n');
}
void uart_int_transmit(uint16_t data)
{
	//unsigned int i=0;
	//char temp;
	//a[5] = '\n';
	//for(i=4 ; i >= 0 ; i --)
	//{
		//itoa((data%10),temp,10);
		//a[i] = temp;
		//data = data / 10;
	//}
	//uart_print(a);
	//
	uint8_t d1 = (data%10)+48;
	data = data / 10;
	
	uint8_t d2 = (data%10)+48;
	data = data / 10;
	
	uint8_t d3 = (data%10)+48;
	data = data / 10;
	
	uint8_t d4 = (data%10)+48;
	data = data / 10;
	
	if( d4 != 48)
	{
		uart_transmit(d4);
	}
	if( d3 != 48)
	{
		uart_transmit(d3);
	}
	if( d2 != 48)
	{
		uart_transmit(d2);
	}
	if( d1 != 48)
	{
		uart_transmit(d1);
	}
	
	uart_transmit('\r');
	uart_transmit('\n');
	
}
void uart_int(unsigned int data)
{
	while ( ! ( UCSR1A & ( 1 << UDRE1 ) ) )
	;
	UDR1 = data;
}
// read a char from uart
unsigned char uart_receive(void)
{
	while (!( UCSR1A & ( 1 << RXC1) ))
	;
	
	return UDR1;
}

// init uart
void uart_init(void)
{
	// set baud rate
	unsigned int baud = 16u;//BAUD_PRESCALE;
	
	UBRR1H = (unsigned char) (baud >> 8 );
	UBRR1L = (unsigned char)baud;
	UCSR1A |= (1 << U2X1);
	
	// enable received and transmitter
	UCSR1B = ( 1 << RXEN1 ) | ( 1 << TXEN1 );
	
	// set frame format ( 8data, 1stop )
	UCSR1C = (1 << UCSZ10) | (1 << UCSZ11);
}

// check if there are any chars to be read
int uart_dataAvailable(void)
{
	if ( UCSR1A & ( 1 << RXC1) )
	return 1;
	
	return 0;
}

uint8_t uart_flush(void)
{
	uint8_t dummy = 0;
	
	while(UCSR1A & (1 << RXC1))
	dummy = UDR1;
	
	return dummy;
}