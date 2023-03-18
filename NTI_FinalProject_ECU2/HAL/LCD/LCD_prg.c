/*
 * LCD_prg.c
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */

#include "avr/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "LCD_cfg.h"
#include "LCD_int.h"
#include "LCD_priv.h"

static void H_LCD_void_LachByte(u8 copy_u8Byte) {
#if(H_LCD_MOED == BIT4_MODE)
	H_LCD_void_LachNibble(copy_u8Byte);
	H_LCD_void_LachNibble(copy_u8Byte << 4); //send the first niblle
	//send the second niblle
#else if(H_LCD_MOED == BIT8_MODE)

#endif
}

static void H_LCD_void_LachNibble(u8 copy_u8Nibble) {
	M_DIO_voidSetPinValue(H_LCD_DB7_PIN, GET_BIT(copy_u8Nibble, 7));
	M_DIO_voidSetPinValue(H_LCD_DB6_PIN, GET_BIT(copy_u8Nibble, 6));
	M_DIO_voidSetPinValue(H_LCD_DB5_PIN, GET_BIT(copy_u8Nibble, 5));
	M_DIO_voidSetPinValue(H_LCD_DB4_PIN, GET_BIT(copy_u8Nibble, 4));
	M_DIO_voidSetPinValue(H_LCD_EN_PIN, DIO_LOW); // set EN to LOW
	_delay_us(10);
	M_DIO_voidSetPinValue(H_LCD_EN_PIN, DIO_HIGH); // set EN to HIGH
	_delay_us(100);
	M_DIO_voidSetPinValue(H_LCD_EN_PIN, DIO_LOW); // set EN to HIGH
	_delay_ms(1); // wait for 1 ms
}

void H_LCD_void_SendCommand(u8 copy_u8Data) {
	M_DIO_voidSetPinValue(H_LCD_RS_PIN, DIO_LOW); //set RS LOW for command mode
	H_LCD_void_LachByte(copy_u8Data);

}

void H_LCD_void_Clear(void) {
	H_LCD_void_SendCommand(0x01);
}

void H_LCD_void_SendData(char copy_u8Data) {
	M_DIO_voidSetPinValue(H_LCD_RS_PIN, DIO_HIGH); //set RS HIGH for Data mode
	H_LCD_void_LachByte(copy_u8Data);

}

void H_LCD_void_sendString(char *string) {
	static u8 stCounter =0;
	//for (char *it = string; *it; it++) {
	for(int i = 0; i < 100 ; i++){
		if(*(string+i) == 0)
			break;
		H_LCD_void_SendData(*(string+i));
	/*	if(++stCounter == 40)
		{
			stCounter = 0;
			_delay_ms(2000);
			H_LCD_void_Clear();
		}*/
	}
}

void H_LCD_void_sendIntNum(s32 copy_s32Num) {
	char buff[10];
	int n = 0;
	while (copy_s32Num) {
		buff[n] = (copy_s32Num % 10) + '0';
		copy_s32Num /= 10;
		n++;
	}
	buff[n] = '\0';

	for (int i = n - 1; i >= 0; i--) {
		H_LCD_void_SendData(buff[i]);
	}
}

void H_LCD_void_Int(void) {
	_delay_ms(50); //delay for 50 ms
#if(H_LCD_MOED == BIT4_MODE)

	M_DIO_voidSetPinValue(H_LCD_EN_PIN, DIO_LOW); // set EN to LOW
	M_DIO_voidSetPinValue(H_LCD_RS_PIN, DIO_LOW); // set RS to LOW for command mode

	//sending 0010 to set 4bit mode
	H_LCD_void_LachNibble(0b00100000);

	//sending 0010 to set 4bit mode
	H_LCD_void_LachNibble(0b00100000);

	//sending 0010 to set 4bit mode
	H_LCD_void_LachNibble(0b00110000); // nf

	_delay_ms(1);

	//H_LCD_void_SendCommand(
	//LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);

	u8 lcd_displayparams = 0; //= LCD_CURSOROFF | LCD_BLINKOFF;
	//H_LCD_void_SendCommand(LCD_DISPLAYCONTROL | lcd_displayparams);

	lcd_displayparams |= LCD_DISPLAYON;
	H_LCD_void_SendCommand(LCD_DISPLAYCONTROL | lcd_displayparams);

	_delay_ms(1);

	H_LCD_void_SendCommand(LCD_CLEARDISPLAY);

	_delay_ms(3);

	H_LCD_void_SendCommand(LCD_ENTRYMODESET | LCD_ENTRYSHIFTINCREMENT);

	_delay_ms(3);

#endif
}

