/*
 * WIFI_prog.c
 *
 *  Created on: Mar 8, 2023
 *      Author: alish
 */

#include "UART_init.h"
#include <String.h>
#include "millis.h"
#include "WIFI_init.h"
#include <Avr/delay.h>
#include "stdio.h"
#include "string.h"

#if(WIFI_DEBUG)
#include "LCD/LCD_int.h"
#endif

extern u8 RX_Counter_UART;
extern S_UART_config_t UART_config  ;

char buff[100];

void H_WIFI_void_WIFIInit(S_WIFI_Config_t S_WIFI_Config) {

	char command[100];
	M_UART_void_UARTInit(UART_config);
	//_delay_ms(500);
	sprintf(command, "AT+CWMODE=%d\r\n", S_WIFI_Config.WIFI_Mode);
	WIFI_command_statue_t command_statue = H_WIFI_command_statue_t_sendData(
			command, buff, 2000);
#if(WIFI_DEBUG)
	//configuar LCD here
	if (command_statue == WIFI_command_ok) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("WIFI mode updated");
		_delay_ms(2000);
	} else if (command_statue == WIFI_command_error) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("WIFI mode update error!");
		_delay_ms(2000);
		H_LCD_void_Clear();
		H_LCD_void_sendString(buff);
	} else if (command_statue == WIFI_command_timeOute) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("WIFI mode update timeout");

	}
#endif

	sprintf(command, "AT+CWJAP=\"%s\",\"%s\"\r\n", S_WIFI_Config.ssid,
			S_WIFI_Config.password);
	command_statue = H_WIFI_command_statue_t_sendData(command, buff, 2000);

#if(WIFI_DEBUG)
	if (command_statue == WIFI_command_ok) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("WIFI SSID Pass updated");
		_delay_ms(2000);
	} else if (command_statue == WIFI_command_error) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("WIFI SSID update error!");
		_delay_ms(2000);
		H_LCD_void_Clear();
		H_LCD_void_sendString(buff);
	} else if (command_statue == WIFI_command_timeOute) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("WIFI SSID update timeout");

	}
#endif

}

void H_WIFI_void_StartTCPServer(void) {
	WIFI_command_statue_t command_statue = H_WIFI_command_statue_t_sendData(
			"AT+CIPMUX=1\r\n", buff, 2000);
	command_statue = H_WIFI_command_statue_t_sendData("AT+CIPSERVER=1\r\n",
			buff, 2000);

#if(WIFI_DEBUG)
	if (command_statue == WIFI_command_ok) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("TCP server started");
		_delay_ms(2000);
	} else if (command_statue == WIFI_command_error) {
		H_LCD_void_Clear();
		H_LCD_void_sendString("TCP server failed!");
		_delay_ms(2000);
		H_LCD_void_Clear();
		H_LCD_void_sendString(buff);
	}
#endif
}

WIFI_command_statue_t H_WIFI_statue_t_cheakOk(char *response) {
	for (int i = 0; i <= UART_BUFFER_SIZE; i++) {
		if (*(response + i) == 'O')
			if (*(response + i + 1) == 'K')
				return WIFI_command_ok;
	}
	return WIFI_command_error;

}

WIFI_command_statue_t H_WIFI_command_statue_t_sendData(char *command,
		char *response, const int timeout) {
	init_millis(16000000);
	M_UART_void_UARTSendString(command);
	int counter = 0;
	long int time = millis();
	while (1) {
		if ((time + 2000) < millis())
			break;
		while (RX_Counter_UART) {
			*(response + counter) = M_UART_u8_receiveByteASynchNonBlocking();
			if (*(response + counter))
				counter++;
		}
	}

	*(response + counter) = 0;
	if (counter == 0)
		return WIFI_command_timeOute;
	return H_WIFI_statue_t_cheakOk(response);

}

WIFI_TCPCommand_t H_WIFI_TCPCommand_t_TCPCommand(char *StrReceved) {
	char *command;
	command = strstr(StrReceved, "REL");
	if (command != NULL) {
		u8 LEDstatues = *(command + 3) - '0';
		if (LEDstatues == 0) {


			return TCPCommand_RelayOFF;
		} else if (LEDstatues == 1) {


			return TCPCommand_RelayON;
		}
	}

	return TCPCommand_NULL;
}



WIFI_Receive_statue_t H_WIFI_ReceiveStatue_t_WIFIreceive(char *recevBuffer)
{
	if(M_UART_void_UARTAvalepale() > 0)
	{
		M_UART_void_ReceiveString(recevBuffer);
		return WIFI_Data_Receved;
	}
	return WIFI_NO_data_receved;
}
