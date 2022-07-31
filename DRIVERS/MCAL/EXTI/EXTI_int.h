/*
 * EXTI_int.h
 *
 *  Created on: Jun 2, 2022
 *      Author: WaleedSharkawy
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

#define INT0_CTRL_Sense_ISCOO 0
#define INT0_CTRL_Sense_ISCO1 1
#define INT1_CTRL_Sense_ISC10 2
#define INT1_CTRL_Sense_ISC11 3
#define INT2_CTRL_Sense_ISC2 6
#define INT0_CTRL_ENB_PIN 6
#define INT1_CTRL_ENB_PIN 7
#define INT2_CTRL_ENB_PIN 5

void MEXTI_vInit(void);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
