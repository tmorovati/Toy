/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 8/12/2021
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/
#include <mega32.h>
#include <stdio.h>
#include <delay.h>
#include "header.h"

// Declare your global variables here

 
//unsigned char status=NOT_READY;
unsigned char usart_buffer[MAX_USART_BUFFER_SIZE]={''};
unsigned char usart_write_index = 0 , usart_read_index = 0;
//_Bool usart_status = EMPTY;


// USART Receiver interrupt service routine
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status=UCSRA,data=UDR;

if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
    {
        uart_buffer[uart_write_index]=data;
        uart_write_index++ ; 
        if(uart_write_index==MAX_UART_BUFFER_SIZE)
        {
            uart_write_index=0;
            uart_status = FULL;
        }
    }

}

void send_command(char command , int param  )
{    
     
     char i=0 ;
     char send_command[10]= {START_BYTE, VERSION_BYTE, LENGTH_BYTE, 0, FDBACK_BYTE, 0, 0, 0, 0, END_BYTE} ;
     int checksum = ((0xFFFF - (VERSION_BYTE + LENGTH_BYTE + command + FDBACK_BYTE + param )) + 1 )  ;
     send_command[3] =  command ; 
     send_command[5] =  (( param >> 8 )& 0xFF )  ; 
     send_command[6] =  ( param &  0xFF ); 
     send_command[7] =  (( checksum >> 8 )& 0xFF )  ;
     send_command[8] =  ( checksum &  0xFF ); 
     
     for(i ; i < 10 ; i++ )
         putchar(send_command[i]); 
} 

void usart_init(void)
{

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(1<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

}
void take_query(void)
{
  
}
void main(void)
{
// Declare your local variables here
     usart_init(); 
// Global enable interrupts
#asm("sei")
      delay_ms(5000); 
      send_command(0x03 , 0x0001);
while (1)
      {
      // Place your code here

      }
}
