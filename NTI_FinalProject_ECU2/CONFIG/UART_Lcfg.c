/*
 * UART_Lcfg.c
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */


#include "UART_types.h"


S_UART_config_t UART_config = {
		UART_BRate_115k2 ,
		UART_wordLength_8bit ,
		UART_Parity_disable ,
		UART_stopBits_1
};
