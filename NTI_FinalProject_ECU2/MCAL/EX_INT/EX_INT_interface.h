/*
 * EX_INT_interface.h
 *
 *  Created on: Feb 24, 2023
 *      Author: alish
 */

#ifndef EX_INT_EX_INT_INTERFACE_H_
#define EX_INT_EX_INT_INTERFACE_H_

#include "EX_INT_config.h"



void M_EX_INT_void_Enable(EX_INT_config_t );
void M_EX_INT_void_Disable(EX_INT_config_t );
void M_EX_INT_void_SetCallBack(EX_INT_config_t , void (*call_back_func)(void));
void M_EX_INT_void_SetTriggering(EX_INT_config_t);



#endif /* EX_INT_EX_INT_INTERFACE_H_ */
