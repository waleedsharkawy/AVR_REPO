/*
 * KeyPadMyWork.c
 *
 *  Created on: May 13, 2022
 *      Author: WaleedSharkawy
 */
#include "VaribaleDef.h"
#include <avr/io.h>
#include <util/delay.h>
#include "macros.h"
#include "BITMATH.h"

u8 Display_Number[10] = {NO_Zero,NO_One,NO_Two,NO_Three,NO_Four,NO_Five,NO_Six,NO_Seven,NO_Eight,NO_Nine};

void KEYPAD_INIT(void)
{
	DDRA = 0xff;
	DDRB = 0xff;
	DDRD = 0x0f;
	PORTD =0xff;

}


u8 Get_Pressed_Key(void)
{
	u8 Pressed_Key=0;
	for (u8 col=0;col<4;col++)
	{
		Clear_Bit(PORTD,col);
		for (u8 row=0;row<4;row++)
		{
			if ( Get_Bit(PIND,(row+4)) == 0)
			{
				Pressed_Key= row + (col*4) +1;
			}
			while (Get_Bit(PIND,(row+4)) == 0){}
			_delay_ms(10);
		}
		Set_Bit(PORTD,col);
	}
	return Pressed_Key;
}
int main (void)
{
	u8 key=0;
	u8 reminder=0;
	KEYPAD_INIT();
	while (1)
	{
		key = Get_Pressed_Key();
		reminder = key%10;

		if (key<10)
		{
			PORTA = Display_Number[key];
			PORTB = OFFSEGMENT;
		}
		else if (key>=10)
		{
			PORTA = NO_One;
			PORTB = Display_Number[reminder];
		}
	}

	return 0;

}
