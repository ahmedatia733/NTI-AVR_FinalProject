/*
 * LCD_int.h
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */

#ifndef LCD_LCD_INT_H_
#define LCD_LCD_INT_H_

#include "STD_TYPES.h"



void H_LCD_void_SendData(char copy_u8Data);
void H_LCD_void_SendCommand(u8 copy_u8Data);
void H_LCD_void_sendString(char *string);
void H_LCD_void_sendIntNum(s32 copy_s32Num);
void H_LCD_void_Int(void);
void H_LCD_void_Clear(void);

#endif /* LCD_LCD_INT_H_ */
