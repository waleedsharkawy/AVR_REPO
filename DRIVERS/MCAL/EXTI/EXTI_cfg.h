/*
 * EXTI_cfg.h
 *
 *  Created on: Jun 2, 2022
 *      Author: WaleedSharkawy
 */

#ifndef MCAL_EXTI_EXTI_CFG_H_
#define MCAL_EXTI_EXTI_CFG_H_

#define ENABLE  1
#define DISABLE 2
#define EXTI_RAISING 3
#define EXTI_FALLING 4
#define EXTI_LOW 5
#define EXTI_ONCHANGE 6

#define EXTI_LINE0 ENABLE
#define EXTI_LINE1 ENABLE
#define EXTI_LINE2 ENABLE

#define EXTI_LIN0_SENSE_CTRL EXTI_FALLING
#define EXTI_LIN1_SENSE_CTRL EXTI_ONCHANGE
#define EXTI_LIN2_SENSE_CTRL EXTI_FALLING


#endif /* MCAL_EXTI_EXTI_CFG_H_ */
