 /*
 *  Created on: May 27, 2022
 *      Author: WaleedSharkawy
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXTI/EXTI_int.h"
#include "../MCAL/EXTI/EXTI_cfg.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../MCAL/GIE/GIE_int.h"
#include <util/delay.h>

ISR(INT1_vect)
{
	MDIO_vTogPinVal(DIO_PORTA, DIO_PIN0);
	// We Love you Waleed Sharkawy
}

int interruptmain(void)
{
	MDIO_vSetPinDir(DIO_PORTD, DIO_PIN3 ,DIO_INPUT);
	MDIO_vSetPinVal(DIO_PORTD, DIO_PIN3, DIO_HIGH);
	MDIO_vSetPinDir(DIO_PORTA, DIO_PIN0, DIO_OUTPUT);
	MDIO_vSetPinVal(DIO_PORTA, DIO_PIN0, DIO_HIGH);
	MEXTI_vInit();
	MGIE_vEnableGlobalInterrupt();

	while (1)
	{
	}

	return 0;
}
