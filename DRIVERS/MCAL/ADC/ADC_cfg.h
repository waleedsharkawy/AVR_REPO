/*
 * ADC_cfg.h
 *
 *  Created on: Jul 25, 2022
 *      Author: WaleedSharkawy
 */

#ifndef MCAL_ADC_ADC_CFG_H_
#define MCAL_ADC_ADC_CFG_H_


/*
 * OPTIONS
 * EXTERNAL_AREF_MODE
 * INTERNAL_AREF_MODE
 * Internal_AREF_LOW
 */

#define MODE           INTERNAL_AREF_MODE


/*
 * OPTIONS
 * RIGHT_ADJUSMENT
 * LEFT_ADJUSMENT
 */

#define ADJUST         RIGHT_ADJUSMENT

/**
 * OPTIONS for channel
 * CHANNEL_ADC0
 * CHANNEL_ADC1
 * CHANNEL_ADC2
 * CHANNEL_ADC3
 * CHANNEL_ADC4
 * CHANNEL_ADC5
 * CHANNEL_ADC6
 * CHANNEL_ADC7
 */


/**
 * options
 * ENABLE/DISABLE
 */
#define TRiGGER_ENB                   DISABLE
/**
 * OPTIONS
 * FREE_RUNNING
 * Analog_Comparator
 * External_Interrupt_REQUEST_0
 * TIMER_COUNTER0_COMPARE_MATCH
 * TIMER_COUNTER0_OVERFLOW
 * TIMER_COUNTER1_COMPARE_MATCH_B
 * TIMER_COUNTER1_OVERFLOW
 * TIMER_COUNTER1_CAPTURE_EVENT
 */
#define TRIGGER_MODE                FREE_RUNNING

/*
 * OPRTIONS of interrupt
 * ENABLE/DISABLE
 */
#define INTERRUPT_MODE               ENABLE

	/*
	 *PRESCALLER OPTIONS
	 *2             write 1
	 *4             Write 2
	 *8             Write 3
	 *16            Write 4
	 *32            Write 5
	 *64            Write 6
	 *128           Write 7
	 */
#define ADC_PRESCALER   4

#endif /* MCAL_ADC_ADC_CFG_H_ */
