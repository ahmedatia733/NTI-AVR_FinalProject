/*
 * SmartHome_prog.c
 *
 *  Created on: ١٨‏/٠٣‏/٢٠٢٣
 *      Author: ahmed
 */
#include "SmartHome_init.h"
#include "LDR_interface.h"
#include "LDR_config.h"
void APP_SmartHome_void_LightIntensity_init(){

	H_LDR_void_Init();

}


u8 APP_SmartHome_u8_GetIntensityLevel(){
	 u8 intensityLVL = 0;
	 u16 LDRreading = H_LDR_u16_Read(LDR_ADC_CHANNEL);

	 /*Mapping LDR_MIN_READING:LDR_MAX_READING to ---> (0:100)*/
     /*intensityLVL =
    	((LDRreading - LDR_MIN_READING) / (LDR_MAX_READING - LDR_MIN_READING))*
		(LED_MAX_INTENSITY - LED_MIN_INTENSITY) + LED_MIN_INTENSITY;*/

	 //DOES SOME KIND OF MAPPING
	 intensityLVL = LDRreading /(u16)50;
     return intensityLVL;

}

