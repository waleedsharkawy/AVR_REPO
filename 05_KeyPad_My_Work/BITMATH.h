/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define Set_Bit(Reg, bitnum)       (Reg |=1<<bitnum)
#define Clear_Bit(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define Toggle_Bit(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define Get_Bit(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
#define Set_Byte(Reg,value)         ( Reg = value )


#endif
