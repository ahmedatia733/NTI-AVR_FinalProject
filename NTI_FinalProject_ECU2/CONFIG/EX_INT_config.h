/*
 * EX_INT_config.h
 *
 *  Created on: Feb 24, 2023
 *      Author: alish
 */

#define EX_INT_SWITCH	 0

#include "EX_INT_types.h"

typedef struct{


	EX_INT_source_t int_src ;
	EX_INT_state_t  int_state;
	EX_INT_trigger_t int_trigger;


}EX_INT_config_t;

