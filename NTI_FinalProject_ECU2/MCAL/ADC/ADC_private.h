/*
 * ADC_private.h
 *
 *  Created on: Mar 16, 2023
 *      Author: alish
 */

#ifndef ADC_ADC_PRIVATE_H_
#define ADC_ADC_PRIVATE_H_

#include "ADC_types.h"
#include "STD_TYPES.h"


static void (*ADC_CallBackPTR)(void) = NULL;

ADC_adjust_result_t ADC_ADJUSTMENT = ADC_RIGHT_ADJUST;


#endif /* ADC_ADC_PRIVATE_H_ */
