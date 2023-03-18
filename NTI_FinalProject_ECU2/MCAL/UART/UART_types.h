/*
 * UART_types.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef UART_UART_TYPES_H_
#define UART_UART_TYPES_H_

typedef enum
{
	UART_BRate_4800 = 207,
	UART_BRate_9600 = 103,
	UART_BRate_14k4 = 68,
	UART_BRate_19k2 = 51,
	UART_BRate_38k4 = 25,
	UART_BRate_57k6 = 16,
	UART_BRate_76k8 = 12,
	UART_BRate_115k2 = 8,
	UART_BRate_250k = 3,
	UART_BRate_500k = 1,
	UART_BRate_1M = 0,

}UART_BaudRate_t;

typedef enum
{
	UART_Parity_disable = 0x00,
	UART_Parity_even = 0x20,
	UART_Parity_odd = 0x30,

}UART_Parity_t;

typedef enum
{
	UART_stopBits_1 = 0x00,
	UART_stopBits_2 = 0x08

}UART_stopBits_t;


typedef enum
{
	UART_wordLength_5bit = 0x80,
	UART_wordLength_6bit = 0x82,
	UART_wordLength_7bit = 0x84,
	UART_wordLength_8bit = 0x86,


}UART_wordLength_t;

typedef struct
{
	UART_BaudRate_t UART_BaudRate ;
	UART_wordLength_t UART_wordLength;
	UART_Parity_t UART_Parity;
	UART_stopBits_t UART_stopBits;

}S_UART_config_t;


#endif /* UART_UART_TYPES_H_ */
