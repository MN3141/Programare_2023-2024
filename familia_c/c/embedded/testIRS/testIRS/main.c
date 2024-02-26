#include <avr/io.h>
int main(void)
{
	int buttonState=0;
	DDRD=0x02;//D0 mod input,D1 mod output
	PCICR=0x04;//port D for interruptions
	PORTD=0x0;
    while (1) 
    {
		if(PIND&(1<<7))
			PORTD|=2;
		else PORTD&=~2;
		
    }
}

