/*
 * main.c
 *
 *  Created on: May 11, 2022
 *      Author: WaleedSharkawy
 */

#include <avr/io.h>
#include <util/delay.h>

int  main(void)
{
	DDRA = 0b00001111;   //PA0 out
	//PORTA =0b00000001;  //set to high
	//_delay_ms(1000);    //delay
	//PORTA=0;            // set to low
	//_delay_ms(1000)    //delay
	while(1)
	{
		PORTA = 0b00000001;  //PA0 high (5v)
		for (int i=0;i<4;++i)
		{
			_delay_ms(300);
			PORTA <<= 1;

		}



	}

	return 0;
}
