/*
 * test.c
 *
 * Created: 5/21/2021 12:28:54 PM
 * Author : Tahoura Morovati
 */ 

#include <avr/io.h>


int main(void)
{
	unsigned char z ; 	
	DDRB = 0xFF ; //PORTB is output	
	DDRA = 0x0F ; 
	for (z = 0 ; z<= 5 ; z++ )
	{
		PORTB = z ; 
		PORTA = 0x01 ; 
		//PORTA = 0b00000011 ; 
		//PORTA = 0b00000101 ; 
		//PORTA = 0b00000110 ; 
	}
	return 0 ; 
}

