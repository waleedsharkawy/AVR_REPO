/*
 * ADC_prg.c
 *
 *  Created on: Jul 25, 2022
 *      Author: WaleedSharkawy
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_int.h"
#include "ADC_prv.h"
#include "ADC_cfg.h"

void (*ADC_Call_Back)(void);
void MADC_vInit(void)
{
	/*
	 * setting of reference voltage
	 * EXTERNAL_AREF_MODE
	 * INTERNAL_AREF_MODE
	 * Internal_AREF_LOW
	 */
#if MODE==EXTERNAL_AREF_MODE
	CLR_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#elif MODE==INTERNAL_AREF_MODE
	SET_BIT(ADMUX, REFS0);
	CLR_BIT(ADMUX, REFS1);
#elif MODE==Internal_AREF_LOW
	SET_BIT(ADMUX, REFS0);
	SET_BIT(ADMUX, REFS1);
#else
#error "you entered the wrong choice"
#endif
	/*
	 *setting the adjustment mode
	*/

#if ADJUST==RIGHT_ADJUSMENT
	CLR_BIT(ADMUX, ADLAR);
	/*
	 * SET_PRESCALLER
	 */
	ADCSRA = ( ADCSRA & 11111000) | (ADC_PRESCALER);
#elif ADJUST==LEFT_ADJUSMENT
	SET_BIT(ADMUX, ADLAR);
#else
#error "you have enter the wrong choice"
#endif

	/*
	 * Setup Triggering mode
	 */
#if TRiGGER_ENB==DISABLE
	CLR_BIT(ADCSRA, ADATE);
#elif TRiGGER_ENB==ENABLE
	SET_BIT(ADCSRA, ADATE);
#if TRIGGER_MODE == FREE_RUNNING
	SFIOR = (SFIOR & 00001111) | FREE_RUNNING_REG_VALUE;
#elif TRIGGER_MODE == Analog_Comparator
	SFIOR = (SFIOR & 00001111) | Analog_Comparator_REG_VALUE;
#elif TRIGGER_MODE == External_Interrupt_REQUEST_0
	SFIOR = (SFIOR & 00001111) | External_Interrupt_REQUEST_0_REG_VALUE;
#elif TRIGGER_MODE == TIMER_COUNTER0_COMPARE_MATCH
	SFIOR = (SFIOR & 00001111) | TIMER_COUNTER0_COMPARE_MATCH_REG_VALUE;
#elif TRIGGER_MODE == TIMER_COUNTER0_OVERFLOW
	SFIOR = (SFIOR & 00001111) | TIMER_COUNTER0_OVERFLOW__REG_VALUE;
#elif TRIGGER_MODE == TIMER_COUNTER1_COMPARE_MATCH_B
	SFIOR = (SFIOR & 00001111) | TIMER_COUNTER1_COMPARE_MATCH_B_REG_VALUE;
#elif TRIGGER_MODE == TIMER_COUNTER1_OVERFLOW
	SFIOR = (SFIOR & 00001111) | TIMER_COUNTER1_OVERFLOW_REG_VALUE;
#elif TRIGGER_MODE == TIMER_COUNTER1_CAPTURE_EVENT
	SFIOR = (SFIOR & 00001111) | TIMER_COUNTER1_CAPTURE_EVENT_REG_VALUE;
#endif
#endif
	/*
	 *INTERRUPT ENABLE/DISABLE
	 */
#if INTERRUPT_MODE == ENABLE
	SET_BIT(ADCSRA, ADIE);
#elif INTERRUPT_MODE == DISABLE
	CLR_BIT(ADCSRA, ADIE);
#endif

	/*
	 * Enabling Conversion
	 */
	SET_BIT(ADCSRA, ADEN);
}




u16  MADC_u16AnalogRead(u8 A_u8ChannelNo )
{

	/*selecting channel*/
	ADMUX = (ADMUX & 0x0E) | (A_u8ChannelNo & 0x07);
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
	/* 3- Poll on Flag if interrupt DISABLED */
	CLR_BIT(ADCSRA, 3);
	while( GET_BIT(ADCSRA, ADIF) != 1 ){}
	/* 4- Clear Flag       */
	SET_BIT(ADCSRA, ADIF);
	/* 5- return ADC Data  */
	return ADC;
}


void MADC_vStartConversion(u8 A_u8ChannelNo)
{
	/*selecting channel*/
	ADMUX = (ADMUX & 0x0E) | (A_u8ChannelNo & 0x07);
	/* 2- Start Conversion */
	SET_BIT(ADCSRA, ADSC);
}

u16   MADC_u16GetADCData(void)
{
	return ADC;
}

void MADC_vSetCallback( void (*A_fptr)(void)  )
{
	ADC_Call_Back=A_fptr;
}


void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	ADC_Call_Back();
}
