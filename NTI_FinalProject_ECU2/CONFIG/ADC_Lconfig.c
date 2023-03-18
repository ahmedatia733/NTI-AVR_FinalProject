/*
 * ADC_Lconfig.c
 *
 *  Created on: Mar 16, 2023
 *      Author: alish
 */

#include "ADC_config.h"


/*
 * READY-TO-USE configuration structures for the LM35 and LDR sensors
 * -both are equal and can be used interchangeably */
//LDR
ADC_config_t LDR_ADC_config_struct = {
		ADC_AVCC,
		ADC_AUTO_TRIGGER_DISABLE,
		ADC_INTERRUPT_DISABLE,
		ADC_PRESCALER_128,
		ADC_FREE_RUNNING,
};

//LM35
ADC_config_t LM35_ADC_config_struct = {
		ADC_AVCC,
		ADC_AUTO_TRIGGER_DISABLE,
		ADC_INTERRUPT_DISABLE,
		ADC_PRESCALER_128,
		ADC_FREE_RUNNING,
};

