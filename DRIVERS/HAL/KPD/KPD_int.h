/*
 * KPD_int.h
 *
 *  Created on: May 27, 2022
 *      Author: WaleedSharkawy
 */

#ifndef HAL_KPD_KPD_INT_H_
#define HAL_KPD_KPD_INT_H_
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_int.h"
#include <util/delay.h>
#define KPD_PORT DIO_PORTC

void HKPD_u8GetPressedKey(u8 *L_u8Postion_ptr);
void HKEYPAD_vInit(void);


#endif /* HAL_KPD_KPD_INT_H_ */




