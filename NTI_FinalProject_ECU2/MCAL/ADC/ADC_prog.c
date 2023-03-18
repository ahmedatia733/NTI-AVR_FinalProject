/*
 * ADC_prog.c
 *
 *  Created on: Mar 16, 2023
 *      Author: alish
 */


#include "ADC_config.h"


#if ADC_SWITCH

#include "ADC_private.h"
#include "Mcu_HW.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"


void M_ADC_void_Init(ADC_config_t mADC){


	//Right "0" or Left "1" Adjustment of the ADC data register
	ADMUX_REG |= (ADC_ADJUSTMENT<<ADMUX_ADLAR);

	//Voltage Reference
	//ADMUX_REG &= 0x3F; //Zeroing the last 2 bits
	ADMUX_REG |= ((mADC.volt_ref)<<ADMUX_REFS0);

	//Auto trigger enable/disable
	ADCSRA_REG |= ((mADC.auto_trigger)<<ADCSRA_ADATE);

	//Interrupt Enable/Disable
	ADCSRA_REG |= ((mADC.interrupt)<<ADCSRA_ADIE);

	//Prescaler Select
	ADCSRA_REG &= 0xF8;
	ADCSRA_REG |= ((mADC.prescaler)<<ADCSRA_ADPS0);

	//Auto trigger Source
	SFIOR_REG &= 0x0F;
	SFIOR_REG |= ((mADC.auto_trigger_source)<<SFIOR_ADTS0);

	//Finally Enable
	ADCSRA_REG |= (1<<ADCSRA_ADEN);


}

void M_ADC_void_StartConversion(){

	//Start Conversion
	ADCSRA_REG |= (1<<ADCSRA_ADSC);


}
//Polling NonBlocking (conversion is started externally)
ADC_state_code_t M_ADC_void_GetDigitalValueSynchNonBlocking(ADC_channel_t channel, u16* data){

	//Channel
	ADMUX_REG &= 0xE0;
	ADMUX_REG |= channel ;


	if((GET_BIT(ADCSRA_REG,ADCSRA_ADIF)) == 0){
		return ADC_FAILED;
	}
	else{
	ADCSRA_REG |= (1<<ADCSRA_ADIF); //clear the flag

	switch(ADC_ADJUSTMENT){
	case ADC_LEFT_ADJUST:
		(*data) = ADCL_REG;
		(*data) |= ADCH_REG<<2;
		break;
	case ADC_RIGHT_ADJUST:
		(*data) = ADCL_REG;
		(*data) |= (ADCH_REG<<8);
		break;
	}

	return ADC_SUCCEED;

	}
}

//(conversion is started externally)
void M_ADC_void_GetDigitalValueAsynchCallback(ADC_channel_t channel, void (*localCallBack)(void)){

	//Channel
	ADMUX_REG &= 0xE0;
	ADMUX_REG |= channel ;

	ADC_CallBackPTR = localCallBack;

}


ISR(ADC_vect){

	if(ADC_CallBackPTR != NULL){
		ADC_CallBackPTR();
	}



}

#endif
