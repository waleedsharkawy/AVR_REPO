/*
 * SNAKE_prg.c
 *
 *  Created on: May 27, 2022
 *      Author: WaleedSharkawy
 */
#include "../BIT_MATH.h"
#include "../STD_TYPES.h"
#include "SNAKE_int.h"
#include <avr/io.h>
#include <util/delay.h>
void KEYPAD_INIT(void)
{
	DDRB=0b00000111;
	PORTB=0b00111111;
}


u8 Get_Pressed_Key(u8 *KEY_PTR)
{
	for (u8 col=0;col<3;col++)
	{
		CLR_BIT(PORTB,col);
		for (u8 row=0;row<3;row++)
		{
			if ( GET_BIT(PINB,(row+3)) == 0)
			{
				*KEY_PTR= row + (col*3) +1;
			}
			_delay_ms(50);
		}

		SET_BIT(PORTC,col);
	}
}
