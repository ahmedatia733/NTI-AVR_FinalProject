/*
 * APP.c
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */
#include <avr/delay.h>
#include "Port_int.h"
#include "LCD/LCD_int.h"
#include "SmartHome_init.h"
#include "stdio.h"

extern const Port_Configtype Port_ConfigArr[PORT_PINS_CONFIG_ARR_SIZE];
char buff[100];
int main() {
	M_PORT_voidInit(Port_ConfigArr);
	H_LCD_void_Int();
	H_LCD_void_sendString("test");

	__asm__ __volatile__ ("sei" ::);

	APP_void_StartWIFIserver();
	_delay_ms(2000);
	H_LCD_void_Clear();
	H_LCD_void_sendString("waiting new user");
	while (1) {

		if (APP_UpdateStatus_t_WIFIUpdate(buff) == APP_WIFI_Updated) {
			H_LCD_void_Clear();
			H_LCD_void_sendString(buff);
		}
	}

	return 0;
}
