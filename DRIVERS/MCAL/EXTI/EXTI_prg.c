/*
 * EXTI_prg.c
 *
 *  Created on: Jun 2, 2022
 *      Author: WaleedSharkawy
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "EXTI_int.h"
#include "EXTI_cfg.h"

void MEXTI_vInit(void)
{
	/**
	 * this function is to initialize EXTI Driver info is gotten from datasheet
	 * PINS
	 * INT0 PD2/ INT1 PD3 / INT2 PB2
	 */
#if EXTI_LINE0==ENABLE
	/*
	 * Interrupt Sense control setting
	 */
	/*
	 *setting for LOW_MODE
	 */
#if EXTI_LIN0_SENSE_CTRL==EXTI_LOW
	CLR_BIT(MCUCR, INT0_CTRL_Sense_ISCOO);
	CLR_BIT(MCUCR, INT0_CTRL_Sense_ISCO1);
	/*
	*setting for Falling_Mode
	*/
#elif EXTI_LIN0_SENSE_CTRL==EXTI_FALLING
	SET_BIT(MCUCR, INT0_CTRL_Sense_ISCO1);
	CLR_BIT(MCUCR, INT0_CTRL_Sense_ISCOO);
	/*
	*setting for Rising_Mode
	*/
#elif EXTI_LIN0_SENSE_CTRL==EXTI_RASING
	SET_BIT(MCUCR, INT0_CTRL_Sense_ISCO1);
	SET_BIT(MCUCR, INT0_CTRL_Sense_ISCOO);
	/*
	*setting for ON_Change
	*/
#elif EXTI_LIN0_SENSE_CTRL==EXTI_ONCHANGE
	CLR_BIT(MCUCR, INT0_CTRL_Sense_ISCO1);
	SET_BIT(MCUCR, INT0_CTRL_Sense_ISCOO);
#else
#error "Sense Control must be Falling, Rising, ONCHANGE and LOW"
#endif
	/*
	 *Enable Interrupt PIN PIE (Programmable Interrupt Enable)
	 */
	SET_BIT(GICR, INT0_CTRL_ENB_PIN);
#endif
#if EXTI_LINE1==ENABLE
	/*
	 * Interrupt Sense control setting
	 */
	/*
	 *setting for LOW_MODE
	 */
#if EXTI_LIN1_SENSE_CTRL==EXTI_LOW
	CLR_BIT(MCUCR, INT1_CTRL_Sense_ISC10);
	CLR_BIT(MCUCR, INT1_CTRL_Sense_ISC11);
	/*
	*setting for Falling_Mode
	*/
#elif EXTI_LIN1_SENSE_CTRL==EXTI_FALLING
	SET_BIT(MCUCR, INT1_CTRL_Sense_ISC11);
	CLR_BIT(MCUCR, INT1_CTRL_Sense_ISC10);
	/*
	*setting for Rising_Mode
	*/
#elif EXTI_LIN1_SENSE_CTRL==EXTI_RASING
	SET_BIT(MCUCR, INT1_CTRL_Sense_ISC11);
	SET_BIT(MCUCR, INT1_CTRL_Sense_ISC10);
	/*
	*setting for ON_Change
	*/
#elif EXTI_LIN1_SENSE_CTRL==EXTI_ONCHANGE
	CLR_BIT(MCUCR, INT1_CTRL_Sense_ISC11);
	SET_BIT(MCUCR, INT1_CTRL_Sense_ISC10);
#else
#error "Sense Control must be Falling, Rising, ONCHANGE and LOW"
#endif
	/*
	 *Enable Interrupt PIN PIE (Programmable Interrupt Enable)
	 */
	SET_BIT(GICR, INT1_CTRL_ENB_PIN);
#endif

#if EXTI_LINE2==ENABLE
	/*
	 * Interrupt Sense control setting
	 */
	/*
	 *setting for FALLING MODE
	 */
#if EXTI_LIN2_SENSE_CTRL==EXTI_FALLING
	CLR_BIT(MCUCSR, INT2_CTRL_Sense_ISC2);
	/*
	*setting for Rising_Mode
	*/
#elif EXTI_LIN2_SENSE_CTRL==EXTI_RASING
	SET_BIT(MCUCSR, INT2_CTRL_Sense_ISC2);
#else
#error "Sense Control must be Falling, Rising"
#endif
	/*
	 *Enable Interrupt PIN PIE (Programmable Interrupt Enable)
	 */
	SET_BIT(GICR, INT2_CTRL_ENB_PIN);
#endif

}
