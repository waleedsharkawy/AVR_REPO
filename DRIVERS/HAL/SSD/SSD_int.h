/*
 * SSD_int.h
 *
 *  Created on: May 18, 2022
 *      Author: WaleedSharkawy
 */

#ifndef HAL_SSD_SSD_INT_H_
#define HAL_SSD_SSD_INT_H_

#define NO_Zero 0b10111111
#define NO_One 0b10000110
#define NO_Two 0b11011011
#define NO_Three 0b11001111
#define NO_Four 0b11100110
#define NO_Five 0b11101101
#define NO_Six 0b11111101
#define NO_Seven 0b10000111
#define NO_Eight 0b11111111
#define NO_Nine 0b11101111
#define OFFSEGMENT 0b10000000

#define COM_CATHODE 1
#define COM_ANODE 0
#define SSD_TYPE COM_ANODE

#define SSD_PORT DIO_PORTA

void SSD_vInit(void);
void SSD_vDisplayNum(u8 A_u8Num);
void SSD_vTurnOff(void);


#endif /* HAL_SSD_SSD_INT_H_ */
