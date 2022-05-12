/*
 * Counter_Segment.c
 *
 *  Created on: May 11, 2022
 *      Author: WaleedSharkawy
 */


#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#define NO_Zero 0b00111111
#define NO_One 0b00000110
#define NO_Two 0b01011011
#define NO_Three 0b01001111
#define NO_Four 0b01100110
#define NO_Five 0b01101101
#define NO_Six 0b01111101
#define NO_Seven 0b00000111
#define NO_Eight 0b01111111
#define NO_Nine 0b011100111

int  main(void)
{
	DDRA = 0b11111111;   //PA0 out
	DDRB = 0b11111111;   //PA0 out
	while(1)
	{
		PORTA=NO_One;
		PORTB=NO_Three;
		_delay_ms(100);
		PORTA=NO_Zero;
		PORTB=NO_Eight;
		_delay_ms(100);



	}

	return 0;
}
