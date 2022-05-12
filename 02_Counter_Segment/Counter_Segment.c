/*
 * main.c
 *
 *  Created on: May 11, 2022
 *      Author: WaleedSharkawy
 */

#include <avr/io.h>
#include <util/delay.h>
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
	//PORTA =0b00000001;  //set to high
	//_delay_ms(1000);    //delay
	//PORTA=0;            // set to low
	//_delay_ms(1000)    //delay
	while(1)
	{
		PORTA = NO_Zero;  //PA0 high (5v)
		_delay_ms(300);
		PORTA= NO_One;
		_delay_ms(300);
		PORTA= NO_Two;
		_delay_ms(300);
		PORTA= NO_Three;
		_delay_ms(300);
		PORTA= NO_Four;
		_delay_ms(300);
		PORTA= NO_Five;
		_delay_ms(300);
		PORTA= NO_Six;
		_delay_ms(300);
		PORTA= NO_Seven;
		_delay_ms(300);
		PORTA= NO_Eight;
		_delay_ms(300);
		PORTA= NO_Nine;
		_delay_ms(700);
		PORTA= NO_Eight;
		_delay_ms(300);
		PORTA= NO_Seven;
		_delay_ms(300);
		PORTA= NO_Six;
		_delay_ms(300);
		PORTA= NO_Five;
		_delay_ms(300);
		PORTA= NO_Four;
		_delay_ms(300);
		PORTA= NO_Three;
		_delay_ms(300);
		PORTA= NO_Two;
		_delay_ms(300);
		PORTA= NO_One;
		_delay_ms(300);
		PORTA= NO_Zero;
		_delay_ms(300);

	}

	return 0;
}
