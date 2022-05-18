/*
 * DIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: WaleedSharkawy
 */

#ifndef MCAL_DIO_DIO_INT_H_
#define MCAL_DIO_DIO_INT_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1

#define DIO_OUTPUT 1
#define DIO_INPUT 0
#define DIO_HIGH 1
#define DIO_LOW 0



void DIO_vSetPinDir(u8 A_u8PortNo,u8 A_u8PinNo ,u8 A_u8Dir);
void DIO_SetPinVal(u8 A_u8PortNo,u8 A_u8PinNo,u8 A_u8Val );
u8 DIO_u8GetPinVal(u8 A_u8PortNo,u8 A_u8PinNo);

void DIO_SetPortDir(u8 A_u8PortNo,u8 A_u8Dir);
void DIO_SetPortVal(u8 A_u8PortNo,u8 A_u8Val );
u8 DIO_u8GetPortVal(u8 A_u8PortNo,u8 A_u8PinNo);


#endif /* MCAL_DIO_DIO_INT_H_ */
