/*
 * LedIntensity.c
 *
 *  Created on: Mar 17, 2023
 *      Author: alish
 */

#include "LedIntensity.h"

void APP_void_LedIntensity_LDR_init(){

	H_LDR_void_Init();

}


u16 APP_void_LedInstensity_VoltageResult(){

	u16 result ;
	result = H_LDR_u16_Read(LDR_ADC_CHANNEL);
	return result;

}

u8 APP_void_LedIntensity_GetLevelFromLDR(){
	 u8 intensityLVL = 0;
	 u16 LDRreading = APP_void_LedInstensity_VoltageResult();

	 /*Mapping LDR_MIN_READING:LDR_MAX_READING to ---> (0:100)*/
     /*intensityLVL =
    	((LDRreading - LDR_MIN_READING) / (LDR_MAX_READING - LDR_MIN_READING))*
		(LED_MAX_INTENSITY - LED_MIN_INTENSITY) + LED_MIN_INTENSITY;*/

	 //DOES SOME KIND OF MAPPING
	 intensityLVL = LDRreading /(u16)50;
     return intensityLVL;

}

