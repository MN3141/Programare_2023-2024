/*
 * GccApplication1.c
 *
 * Created: 2/11/2024 10:34:27 PM
 * Author : mihai
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>
int main(void)
{
	DDRD=DDRD|2;
    /* Replace with your application code */
    while (1) 
    {
		PORTD=PORTD|2;
		_delay_ms(2000);
		PORTD=PORTD&(~2);
		_delay_ms(2000);
    }
}

