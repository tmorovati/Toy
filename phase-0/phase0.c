#include <mega32.h>
#include <delay.h>
#include <stdio.h>
#include "header.h"

void send_command(char command , int param  )
{    
     
     char i=0 ;
     char send_command[10]= {START_BYTE, VERSION, LENGTH, 0, FEEDBACK, 0, 0, 0, 0, END_BYTE} ;
     int checksum = ((0xFFFF - (VERSION + LENGTH + command + FEEDBACK + param )) + 1 )  ;
     send_command[3] =  command ; 
     send_command[5] =  (( param >> 8 )& 0xFF )  ; 
     send_command[6] =  ( param &  0xFF ); 
     send_command[7] =  (( checksum >> 8 )& 0xFF )  ;
     send_command[8] =  ( checksum &  0xFF ); 
     
     for(i ; i < 10 ; i++ )
         putchar(send_command[i]); 
} 
int take_query()
{

    char take_query[10]= {START_BYTE, VERSION, LENGTH, 0, FEEDBACK, 0, 0, 0, 0, END_BYTE} ; 
}
void main(void)
{
    
    
// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: Off
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;
          delay_ms(5000); 
          send_command(0x03 , 0x0001); 
          

    while (1)
          {
          } 
     
}
