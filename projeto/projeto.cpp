#include <avr/io.h>
#include <util/delay.h>
#include "hd44780/hd44780.hpp"
#include <stdio.h>
#include "uartLib/uart.hpp"
#include "hd44780/hd44780.hpp"
#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

int main (void){

	char str[1],str1[1],str2[1];

	PORTB |= (1<<PORTB2) | (1<<PORTB3) | (1<<PORTB4) |(1<<PORTB5);

    LCD_Initalize();

    uint8_t h=00;
    uint8_t m=00;
    uint8_t s=00;

    while(1){

    	if (!(PIND & 1 << PIND0)){
    	   m = m+1;
    	   s = 0;
    	 }

    	if (!(PIND & 1 << PIND1)){
    		if(m==0)
    			m=0;
    		else
    			m = m-1;
    			s =0;
    	 }

    	 if (!(PIND & 1 << PIND2)){
    	    h = h+1;
    	    s=0;
    	    m=0;
    	 }

    	  if (!(PIND & 1 << PIND3)){
    		if(h==0)
    			h=0;
    		else
    			h = h-1;
    	    	s=0;
    	    	m=0;
    	 }

    	 LCD_GoTo(0,0);
    	 LCD_WriteText("Time ");
    	 if(h<10)LCD_WriteText("0");
    	 sprintf(str, "%d", h);
    	 LCD_WriteText(str);
    	 LCD_WriteText(":");
    	 if(m<10)LCD_WriteText("0");
    	 sprintf(str1, "%d", m);
    	 LCD_WriteText(str1);
    	 LCD_WriteText(":");
    	 if(s<10)LCD_WriteText("0");
    	 sprintf(str2, "%d", s);
    	 LCD_WriteText(str2);

    	 LCD_GoTo(0,1);
    	 LCD_WriteText("Live your best");

    		 _delay_ms(1000);


    	 if(s==60){
    	   s=0;
    	   m=m+1;
    	  }

    	  if(m==60)
    	  {
    	   m=0;
    	   h=h+1;
    	  }

    	  if(h==24)
    	  {
    	   h=0;
    	  }

    	  s=s+1;
    }
}

