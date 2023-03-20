/*
 * Timer_types.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef TIMER0_TIMER_TYPES_H_
#define TIMER0_TIMER_TYPES_H_

typedef enum
{
	Timer0_Normal_Mode,
	Timer0_PhaseCorrecet_Mode =  0x08,
	Timer0_CTC_Mode = 0x40,
	Timer0_FastPWM_Mode =  0x48
}Timer0_Mode_t;

typedef enum
{
	Timer0_Disconnected = 0x00,
	Timer0_Toggle_Mode = 0x10,
	Timer0_CLR_Mode = 0x20,
	Timer0_SET_Mode = 0x30
}Timer0_OC0_Mode_t;

typedef enum
{
	Timer0_prescaler_NO = 0,
	Timer0_prescaler_1 ,
	Timer0_prescaler_8 ,
	Timer0_prescaler_64 ,
	Timer_prescaler_256 ,
	Timer0_prescaler_1024 ,
	Timer0_ExternalFalling ,
	Timer0_ExternalRising

}Timer_prescaler_t;


#endif /* TIMER0_TIMER_TYPES_H_ */
