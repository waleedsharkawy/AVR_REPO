/*
 * main.c
 *
 *  Created on: May 12, 2022
 *      Author: WaleedSharkawy
 */


#include <avr/io.h>
#include <util/delay.h>
#include "BITMATH.h"

void KEYPAD_Init(void)
{
	/*PORTB -> inputs/outputs*/
	DDRB =0x0f;
	/*pull up resistor activation on inputs*/
	PORTB = 0xff;
}

unsigned char GetPressedKey(void)
{
	unsigned char Pressed_Key = 0;

	for (unsigned char col=0; col<4;col++)
	{
		/*activate current column*/
		CLR_BIT(PORTB,col);
		for (unsigned char row=0;row<4;row++)
		{
			if (GET_BIT(PINB,row+4)==0)  // a buttom is pressed
			{
				Pressed_Key=0; /*key number*/
			}
			while (GET_BIT(PINB,row+4)==0){}
			_delay_ms(10);
		}
		/*deactivate column*/
		SET_BIT(PORTB,col);
	}



	return Pressed_Key;
}

int main(void)
{
	KEYPAD_Init()
	while(1)
	{

	}
	return 0;
}
