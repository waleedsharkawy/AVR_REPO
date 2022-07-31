/*
 * GIE_prg.c
 *
 *  Created on: Jun 2, 2022
 *      Author: WaleedSharkawy
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include <avr/io.h>
#include "GIE_int.h"


void MGIE_vEnableGlobalInterrupt(void)
{
	SET_BIT(SREG, GLOBAL_INTERRUPT_PIN);
}
void MGIE_vDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG, GLOBAL_INTERRUPT_PIN);
}

