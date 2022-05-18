/*
 * SSD_prg.c
 *
 *  Created on: May 18, 2022
 *      Author: WaleedSharkawy
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "SSD_int.h"

static const u8 CGS_u8SSD_Nums[]={
		NO_Zero,
		NO_One,
		NO_Two,
		NO_Three,
		NO_Four,
		NO_Five,
		NO_Six,
		NO_Seven,
		NO_Eight,
		NO_Nine,

};
void SSD_vInit(void)
{
	DIO_vSetPortDir(SSD_PORT,0xff);
}

void SSD_vDisplayNum(u8 A_u8Num)
{
	/*input validation*/
	if (A_u8Num<10)
	{
#if SSD_TYPE == COM_CATHODE
		DIO_vSetPortVal(SSD_PORT, CGS_u8SSD_Nums[A_u8Num]);
#elif SSD_TYPE == COM_ANODE
		DIO_vSetPortVal(SSD_PORT, ~CGS_u8SSD_Nums[A_u8Num]);
#endif
	}
}

void SSD_vTurnOff(void)
{
#if SSD_TYPE == COM_CATHODE
		DIO_vSetPortVal(SSD_PORT, OFFSEGMENT);
#elif SSD_TYPE == COM_ANODE
		DIO_vSetPortVal(SSD_PORT, ~OFFSEGMENT);
#endif
}

