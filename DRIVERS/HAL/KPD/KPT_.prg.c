/*
 * KPT_.prg.c
 *
 *  Created on: May 27, 2022
 *      Author: WaleedSharkawy
 */


#include "KPD_int.h"


void HKEYPAD_vInit(void)
{
	MDIO_vSetPortDir(KPD_PORT,0x0f);
	MDIO_vSetPortVal(KPD_PORT, 0xff);
}

void HKPD_u8GetPressedKey(u8 *L_u8Postion_ptr)
{
	for(u8 col=0; col<4; col++)
	{
		MDIO_vSetPinVal(KPD_PORT, col, DIO_LOW);
		for(u8 row=0; row<4; row++)
		{
			if(MDIO_u8GetPinVal(KPD_PORT, row+4) == 0)
			{
				*L_u8Postion_ptr = row + (col*4) +1  ;
			}
			while(MDIO_u8GetPinVal(KPD_PORT, row+4) == 0){}
			_delay_ms(10);
		}
		/* deactivate current column */
		MDIO_vSetPinVal(KPD_PORT, col, DIO_HIGH);
	}
}
