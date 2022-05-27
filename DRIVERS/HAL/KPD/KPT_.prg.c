/*
 * KPT_.prg.c
 *
 *  Created on: May 27, 2022
 *      Author: WaleedSharkawy
 */


#include "KPD_int.h"


void HKEYPAD_vInit(void)
{
	DIO_vSetPortDir(KPD_PORT,0x0f);
	DIO_vSetPortVal(KPD_PORT, 0xff);
}

u8 HKPD_u8GetPressedKey(void)
{
	u8 pressed_key = 0;
	for(u8 col=0; col<4; col++)
	{
		DIO_vSetPinVal(KPD_PORT, col, DIO_LOW);
		for(u8 row=0; row<4; row++)
		{
			if(DIO_u8GetPinVal(KPD_PORT, row+4) == 0)
			{
				pressed_key = row + (col*4) +1  ;
			}
			while(DIO_u8GetPinVal(KPD_PORT, row+4) == 0){}
			_delay_ms(10);
		}
		/* deactivate current column */
		DIO_vSetPinVal(KPD_PORT, col, DIO_HIGH);
	}
	return pressed_key;
}
