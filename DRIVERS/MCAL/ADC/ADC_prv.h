/*
 * ADC_prv.h
 *
 *  Created on: Jul 25, 2022
 *      Author: WaleedSharkawy
 */

#ifndef MCAL_ADC_ADC_PRV_H_
#define MCAL_ADC_ADC_PRV_H_


#define ADMUX        *((volatile u8*)(0x27))
#define ADCSRA       *((volatile u8*)(0x26))
#define ADCL         *((volatile u8*)(0x24))
#define ADCH         *((volatile u8*)(0x25))
#define SFIOR        *((volatile u8*)(0x50))

#define ADC          *((volatile u16*)(0x24))


/*
 * ADMUX Bits
 */
#define MUX0                        0
#define MUX1                        1
#define MUX2                        2
#define MUX3						3
#define MUX4						4
#define ADLAR						5
#define REFS0                       6
#define REFS1                       7
/*
 * ADCSRA BITS
 */
#define ADPS0						0
#define ADPS1						1
#define ADPS2						2
#define ADIE						3
#define ADIF						4
#define ADATE						5
#define ADSC						6
#define ADEN						7
/*
 * SFIOR BITS
 */
#define PSR10						0
#define PSR2						1
#define PUD							2
#define ACME						3
#define ADTS0						5
#define ADTS1						6
#define ADTS2						7



#define EXTERNAL_AREF_MODE                             1
#define INTERNAL_AREF_MODE                             2
#define Internal_AREF_LOW                              3
#define RIGHT_ADJUSMENT                                4
#define LEFT_ADJUSMENT                                 5

#define FREE_RUNNING_REG_VALUE                         0
#define Analog_Comparator_REG_VALUE                    1
#define External_Interrupt_REQUEST_0_REG_VALUE         2
#define TIMER_COUNTER0_COMPARE_MATCH_REG_VALUE         3
#define TIMER_COUNTER0_OVERFLOW_REG_VALUE              4
#define TIMER_COUNTER1_COMPARE_MATCH_B_REG_VALUE       5
#define TIMER_COUNTER1_OVERFLOW_REG_VALUE              6
#define TIMER_COUNTER1_CAPTURE_EVENT_REG_VALUE         7


#define DISABLE                              11
#define ENABLE                               12

#define FREE_RUNNING_MODE                    13
#define Analog_Comparator                    14
#define External_Interrupt_REQUEST_0         15
#define TIMER_COUNTER0_COMPARE_MATCH         16
#define TIMER_COUNTER0_OVERFLOW              17
#define TIMER_COUNTER1_COMPARE_MATCH_B       18
#define TIMER_COUNTER1_OVERFLOW              19
#define TIMER_COUNTER1_CAPTURE_EVENT         20



#define DISABLE                              11
#define ENABLE                               12
#define FREE_RUNNING_MODE                    13
#define Analog_Comparator                    14

#define External_Interrupt_REQUEST_0         15
#define TIMER_COUNTER0_COMPARE_MATCH         16
#define TIMER_COUNTER0_OVERFLOW              17
#define TIMER_COUNTER1_COMPARE_MATCH_B       18
#define TIMER_COUNTER1_OVERFLOW              19
#define TIMER_COUNTER1_CAPTURE_EVENT         20



#endif /* MCAL_ADC_ADC_PRV_H_ */
