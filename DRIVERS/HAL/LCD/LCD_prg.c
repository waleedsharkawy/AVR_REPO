/*
 * LCD_prg.c
 *
 *  Created on: May 18, 2022
 *      Author: WaleedSharkawy
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "LCD_int.h"
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_int.h"


void HLCD_vSendCommand(u8 A_u8Command)
{
	/*RS*/
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_LOW);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Command);

	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);

}
void HLCD_vSendChar(u8 A_u8Char)
{
	/*RS*/
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RS_PIN, DIO_HIGH);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_RW_PIN, DIO_LOW);
	MDIO_vSetPortVal(LCD_DATA_PORT, A_u8Char);


	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN,DIO_HIGH);
	_delay_ms(1);
	MDIO_vSetPinVal(LCD_CTRL_PORT, LCD_EN_PIN,DIO_LOW);
	_delay_ms(1);

}


void HLCD_vInit(void)
{
	/*set pin directions*/
	MDIO_vSetPortDir(LCD_DATA_PORT,0xff);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RS_PIN, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_RW_PIN, DIO_OUTPUT);
	MDIO_vSetPinDir(LCD_CTRL_PORT, LCD_EN_PIN, DIO_OUTPUT);
	/*start sequence*/
	_delay_ms(50);
	HLCD_vSendCommand(LCD_Function_SET_Command);
	_delay_ms(10);
	HLCD_vSendCommand(LCD_Display_On_Off_Command);
	_delay_ms(10);
	HLCD_vSendCommand(LCD_Display_Clear_Command);
	_delay_ms(10);
	HLCD_vSendCommand(LCD_Entry_Mood_Set_Command);
	_delay_ms(10);

}
void HLCD_vPrintString(char A_u8String[])
{
	for (u8 L_u8i=0; A_u8String[L_u8i] != '\0'; L_u8i++)
	{
		HLCD_vSendChar(A_u8String[L_u8i]);
	}
}

void HLCD_vPrintNumber(s32 A_s32Number)
{
	if(A_s32Number != 0) {
		HLCD_vPrintNumber(A_s32Number / 10);
		HLCD_vSendChar(A_s32Number % 10 + '0');
	}

//	u8 L_u8Digits[10] = {0};
//	u8 L_u8Counter = 0;
//	/* TODO: IMplement negative number handling  	*/
//	/* TODO: implement Zero in units corner case    */
//	/* save reversed in array */
//	while(A_s32Number > 0)
//	{
//		L_u8Digits[L_u8Counter] = A_s32Number%10 ;
//		L_u8Counter++;
//		A_s32Number /= 10 ;
//	}
//
//	/* print array in reverese  */
//	for(s8 L_s8PrintIndex=0; L_s8PrintIndex >= 0; L_s8PrintIndex-- )
//	{
//		HLCD_vSendChar('0' + L_u8Digits[L_s8PrintIndex]);
//	}
}
void HLCD_vSetCursorPosition(u8 A_u8Row, u8 A_u8Col)
{
	u8 L_u8DdramAddress;
	u8 L_u8Command;
	if ( (A_u8Row <= MAX_IDX_OF_ROWS) && (A_u8Col <= MAX_IDX_OF_COL) )
	{
		if (A_u8Row==FIRST_ROW_IDX)
		{
			L_u8DdramAddress = FIRST_ROW_START + A_u8Col;
		}
		else
		{
			L_u8DdramAddress = SEC_ROW_START + A_u8Col;
		}
		L_u8Command = L_u8DdramAddress + No_One_IN_SETDIR_Command;
		HLCD_vSendCommand(L_u8Command);
	}
	else
	{
		/*do Nothing*/
	}
}
void HLCD_vSaveCustomChar(u8 A_u8PatternIdx, u8 *A_u8PatternValue)
{
	u8 L_u8LoopIterator;
	/*set address counter on CGRAM*/
	switch (A_u8PatternIdx)
	{
	case 0: HLCD_vSendCommand(PATTERN_ZERO_ADDRESS); break;
	case 1: HLCD_vSendCommand(PATTERN_ONE_ADDRESS); break;
	case 2: HLCD_vSendCommand(PATTERN_TWO_ADDRESS); break;
	case 3: HLCD_vSendCommand(PATTERN_THREE_ADDRESS); break;
	case 4: HLCD_vSendCommand(PATTERN_FOUR_ADDRESS); break;
	case 5: HLCD_vSendCommand(PATTERN_FIVE_ADDRESS); break;
	case 6: HLCD_vSendCommand(PATTERN_SIX_ADDRESS); break;
	case 7: HLCD_vSendCommand(PATTERN_SEVEN_ADDRESS); break;
	}
	/*Write Pattern*/
	for (L_u8LoopIterator = 0; L_u8LoopIterator<8 ; L_u8LoopIterator++)
	{
		HLCD_vSendChar(A_u8PatternValue[L_u8LoopIterator]);
	}
}
void HLCD_vDisplayCustomChar(/* TODO: input arguments to be provided */)
{

}


