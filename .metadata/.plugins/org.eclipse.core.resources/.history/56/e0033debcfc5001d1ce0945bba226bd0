/*
 * LDR_prog.c
 *
 *  Created on: Mar 17, 2023
 *      Author: alish
 */

#define F_CPU 16000000UL

#include "LDR_interface.h"
#include <util/delay.h>
#define LDR_NUM_OF_SAMPLES	10

extern ADC_config_t LDR_ADC_config_struct;
/*** HOW to use
 * - You provide ADC_config_t structure with the desired ADC configurations
 *   to read LDR outputs.
 *  ***/
void H_LDR_void_Init(){
	M_ADC_void_Init(LDR_ADC_config_struct);
}


/***
 * - After initializing the ADC reading LDR through H_LDR_void_Init
 * - You provide the channel that LDR is connected to
 * - The function does a 1-shoot ADC conversion and return the voltage in millieVolts
 * - The function uses the non-blocking ADC reading function, but H_LDR_u16_Read itself
 *   blocks the code because it loops until the Reading function returns ADC_SUCCEED  ***/
u16 H_LDR_u16_Read(ADC_channel_t channel){

	f64 analog_volt;
	u16 ADC_result;
	u8 state = ADC_FAILED;
	u16 readings[LDR_NUM_OF_SAMPLES] ;
	int i,j;

	//taking 5 readings
	for( i = 0 ; i< LDR_NUM_OF_SAMPLES ;i++){

		M_ADC_void_StartConversion();
		while(state == ADC_FAILED){
			state = M_ADC_void_GetDigitalValueSynchNonBlocking(channel, &ADC_result);
		}
		readings[i] = ADC_result;
		_delay_us(100);
	}

	//Sorting readings (Bubble Sort)
	u8 temp;
    for (i = 0; i < LDR_NUM_OF_SAMPLES; i++) {
        for (j = 0; j < LDR_NUM_OF_SAMPLES-j-1; j++) {
            if (readings[j] > readings[j+1]) {
                temp = readings[j];
                readings[j] = readings[j+1];
                readings[j+1] = temp;
            }
        }
    }

    // Find the median value in the window
    if (LDR_NUM_OF_SAMPLES % 2 == 0) {
        ADC_result = (readings[LDR_NUM_OF_SAMPLES/2] + readings[LDR_NUM_OF_SAMPLES/2-1])/2;
    }
    else {
        ADC_result = readings[LDR_NUM_OF_SAMPLES/2];
    }


	analog_volt = ADC_result * (((f64)5.0*1000)/1024);  //in millieVolts

	return analog_volt;
	//return ADC_result;

}
