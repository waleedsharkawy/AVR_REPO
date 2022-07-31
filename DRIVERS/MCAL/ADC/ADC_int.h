/*
 * ADC_int.h
 *
 *  Created on: Jul 25, 2022
 *      Author: WaleedSharkawy
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

#define CHANNEL_ADC0                         0
#define CHANNEL_ADC1                         1
#define CHANNEL_ADC2                         2
#define CHANNEL_ADC3                         3
#define CHANNEL_ADC4                         4
#define CHANNEL_ADC5                         5
#define CHANNEL_ADC6                         6
#define CHANNEL_ADC7                         7

void MADC_vInit(void);
u16  MADC_u16AnalogRead(u8 A_u8ChannelNo );
/* Interrupt based APIs */
void MADC_vStartConversion(u8 A_u8ChannelNo);
u16   MADC_u16GetADCData(void);
void MADC_vSetCallback( void (*A_fptr)(void)  );

#endif /* MCAL_ADC_ADC_INT_H_ */
