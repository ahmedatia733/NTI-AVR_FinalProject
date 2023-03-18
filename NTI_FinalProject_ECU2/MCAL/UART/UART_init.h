/*
 * UART_init.h
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */

#ifndef UART_UART_INIT_H_
#define UART_UART_INIT_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Mcu_HW.h"
#include "UART_cfg.h"
#include "UAART_priv.h"
#include "UART_types.h"
u8 M_UART_void_UARTAvalepale();
void M_UART_void_ReceiveString(char *strPtr);
void M_UART_void_UARTInit(S_UART_config_t UART_config);
void M_UART_void_UARTSendByte(u8 Byte);
void M_UART_void_UARTSendString(char* strPtr);
void M_UART_void_UARTSendBytes(u8* byteArr , u8 Arrlength);
char M_UART_u8_receiveByteASynchNonBlocking(void);



#endif /* UART_UART_INIT_H_ */
