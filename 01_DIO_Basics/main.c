/*
 * main.c
 *
 *  Created on: May 11, 2022
 *      Author: WaleedSharkawy
 */

#include <avr/io.h>
#include <util/delay.h>
#include "BITMATH.h"
int  main(void)
{
	SET_BIT(DDRA,0);   //PA0 -> Output
	CLR_BIT(DDRA,1);       //PA1 -> Input
	SET_BIT(PORTA,1);  //Enable Pull Up on PA1

	while(1)
	{
		if (GET_BIT(PINA,1)==0) //if buttom is pressed
		{
			_delay_ms(10);
			if (GET_BIT(PINA,1)==0)
			{
				TOG_BIT(PORTA,0);
			}
		}
		else
		{
			CLR_BIT(PORTA,0);
		}
	}

	return 0;
}
