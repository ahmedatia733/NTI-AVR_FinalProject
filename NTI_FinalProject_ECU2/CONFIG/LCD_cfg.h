/*
 * LCD_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "Dio_types.h"


#define LCD_COL_COUNT 20
#define LCD_ROW_COUNT 4


/*
 * set LCD interface PINS
 * */
#define H_LCD_EN_PIN DIO_PA2
#define H_LCD_RS_PIN DIO_PA3

/*
 * for 4bit mode
 * */
#define H_LCD_DB4_PIN DIO_PB0
#define H_LCD_DB5_PIN DIO_PB1
#define H_LCD_DB6_PIN DIO_PB2
#define H_LCD_DB7_PIN DIO_PB4

/*
 * set pins for 8 bit modes
 * */
#define H_LCD_DB0_PIN 0
#define H_LCD_DB1_PIN 0
#define H_LCD_DB2_PIN 0
#define H_LCD_DB3_PIN 0

#define H_LCD_MOED BIT4_MODE // set mode to 4 bit or 8 bit

#define BIT4_MODE 1
#define BIT8_MODE 0
#endif /* LCD_CFG_H_ */
