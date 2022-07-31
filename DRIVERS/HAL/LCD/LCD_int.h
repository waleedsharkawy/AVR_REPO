/*
 * LCE_int.h
 *
 *  Created on: May 18, 2022
 *      Author: WaleedSharkawy
 */

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_


#define LCD_CTRL_PORT DIO_PORTB
#define LCD_DATA_PORT DIO_PORTD

#define LCD_RS_PIN DIO_PIN0
#define LCD_RW_PIN DIO_PIN1
#define LCD_EN_PIN DIO_PIN2

#define MAX_IDX_OF_ROWS 1
#define MAX_IDX_OF_COL 15
#define FIRST_ROW_IDX 0
#define FIRST_ROW_START 0x00
#define SEC_ROW_START 0x40
#define No_One_IN_SETDIR_Command 0x80


#define LCD_Function_SET_Command 0b00111000
#define LCD_Display_On_Off_Command 0b00001100
#define LCD_Display_Clear_Command 0b00000001
#define LCD_Entry_Mood_Set_Command 0b00111000

#define LCD_CLEAR 0b00000001

#define PATTERN_ZERO_ADDRESS  0b01000000
#define PATTERN_ONE_ADDRESS   0b01001000
#define PATTERN_TWO_ADDRESS   0b01010000
#define PATTERN_THREE_ADDRESS 0b01011000
#define PATTERN_FOUR_ADDRESS  0b01100000
#define PATTERN_FIVE_ADDRESS  0b01101000
#define PATTERN_SIX_ADDRESS   0b01110000
#define PATTERN_SEVEN_ADDRESS 0b01111000



void HLCD_vInit(void);
void HLCD_vSendCommand(u8 A_u8Command);
void HLCD_vSendChar(u8 A_u8Char);
void HLCD_vPrintString(char A_u8String[]);
void HLCD_vPrintNumber(s32 A_s32Number);
void HLCD_vSetCursorPosition(u8 A_u8LinePos, u8 A_u8LineNo);
void HLCD_vSaveCustomChar(u8 A_u8PatternIdx, u8 *A_u8PatternValue);
void HLCD_vDisplayCustomChar(/* TODO: input arguments to be provided */);
void HLCD_vClearScreen();
void HLCD_vScroll(/* TODO: input arguments to be provided */);
#endif /* HAL_LCD_LCD_INT_H_ */
