/*
 * ADC.c
 *
 *  Created on: Jul 25, 2022
 *      Author: WaleedSharkawy
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

volatile u16 ADC_Value=0;
volatile u8 ADC_FLAG=0;

void ADC_ISR (void)
{
	ADC_Value = MADC_u16GetADCData();
	ADC_FLAG=1;

}

int main()
{

	MADC_vSetCallback(ADC_ISR);
	MADC_vInit();
	HLCD_vInit();
	MGIE_vEnableGlobalInterrupt();
	MADC_vStartConversion(CHANNEL_ADC0);


	while (1)
	{

		if (ADC_FLAG==1)
		{
			ADC_FLAG=0;
			HLCD_vSendCommand(LCD_CLEAR);
			HLCD_vPrintNumber((ADC_Value*500)/(1<<10));
			MADC_vStartConversion(CHANNEL_ADC0);
			_delay_ms(250);
		}

	}
}
