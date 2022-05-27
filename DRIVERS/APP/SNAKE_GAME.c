/*
 * SNAKE_GAME.c
 *
 *  Created on: May 27, 2022
 *      Author: WaleedSharkawy
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../HAL/KPD/KPD_int.h"
//#define UP_BUTTOM 9
//#define DOWN_BUTTOM 11
//#define RIGHT_BUTTOM 14
//#define LEFT_BUTTOM 6

#define UP_BUTTOM 14
#define DOWN_BUTTOM 6
#define RIGHT_BUTTOM 9
#define LEFT_BUTTOM 11

u8 PressedKey;
int main(void)
{
	HLCD_vInit();
	HKEYPAD_vInit();

	while (1)
	{
		PressedKey= HKPD_u8GetPressedKey();
		switch (PressedKey)
		{
		case RIGHT_BUTTOM:
			HLCD_vSendChar('R');
			break;
		case LEFT_BUTTOM:
			HLCD_vSendChar('L');
			break;
		case UP_BUTTOM:
			HLCD_vSendChar('U');
			break;
		case DOWN_BUTTOM:
			HLCD_vSendChar('D');
		}


	}


	return 0;
}
