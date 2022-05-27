/*
 * main.c
 *
 *  Created on: May 18, 2022
 *      Author: WaleedSharkawy
 */
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO_int.h"
#include "../HAL/LCD/LCD_int.h"

int main (void)
{
	HLCD_vInit();

	HLCD_vPrintString("waleed sharkawy");


	while(1)
	{

	}

	return 0;

}

