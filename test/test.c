/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
� Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 8/10/2021
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
#include <delay.h>


// Declare your global variables here

// Standard Input/Output functions
#include <stdio.h>



void main(void)
{
// Declare your local variables here
  unsigned char pert = 1 ;  
         unsigned char chert = 0 ;
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
         printf ("galdi ?") ; 

         if (++chert == 0 )
         {
               pert++ ; 
               printf("%c" , pert) ;
               printf("os") ;  
               printf("%c" , chert );
               if (pert == 10 )
               {
                    printf ("done"); 
               } 
         } 
         printf ("%c" , chert );
         printf ("osd") ;   
//         putchar(0x7E);  
//         putchar(0xFF);
//         putchar(0x06);
//         putchar(0x03);
//         putchar(0x00);
//         putchar(0x00);
//         putchar(0x01);
//         putchar(0xFE);
//         putchar(0xF7);
//         putchar(0xEF);

          
          
while (1)
      {
      

      }
}
