/*
 * ADC_interface.h
 *
 *  Created on: Mar 16, 2023
 *      Author: alish
 */

#ifndef ADC_ADC_INTERFACE_H_
#define ADC_ADC_INTERFACE_H_

#include "STD_TYPES.h"
#include "ADC_types.h"
#include "ADC_config.h"


void M_ADC_void_Init(ADC_config_t mADC);
void M_ADC_void_StartConversion();
ADC_state_code_t M_ADC_void_GetDigitalValueSynchNonBlocking(ADC_channel_t channel, u16 * data);
void M_ADC_void_GetDigitalValueAsynchCallback(ADC_channel_t channel, void (*localCallBack)(void));

#endif /* ADC_ADC_INTERFACE_H_ */
