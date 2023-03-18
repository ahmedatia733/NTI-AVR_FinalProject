/*
 * LM35_Lconfig.c
 *
 *  Created on: Mar 16, 2023
 *      Author: alish
 */


#include "LM35_config.h"


ADC_config_t lm35_adc_config = {
		ADC_AVCC,
		ADC_1,
		ADC_AUTO_TRIGGER_DISABLE,
		ADC_INTERRUPT_DISABLE,
		ADC_PRESCALER_128,
		ADC_FREE_RUNNING
};


//ADC_config_t LM35_ADC_config;


