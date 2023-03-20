/*
 * Timer_init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef TIMER0_TIMER_INIT_H_
#define TIMER0_TIMER_INIT_H_

#include "STD_TYPES.h"
#include "Mcu_HW.h"
#include "Timer_priv.h"
#include "Timer_types.h"



void M_Timer0_void_Init(Timer0_Mode_t Mode, Timer0_OC0_Mode_t  OC0_Mode, Timer_prescaler_t  prescaler); //done
void M_Timer0_void_start();
void M_Timer0_void_stop();
long long unsigned int M_Timer0_void_GetCounts();
void M_Timer0_void_setDelayTimeMilliSec(u32 millis);
void M_Timer0_void_EnableInt();
void M_Timer0_void_DisableInt();
void M_Timer0_void_setCallBack(void (*T0_OVF_CB_FnPtr)(void));
void M_Timer0_void_startCount();
void M_Timer0_void_setFastPWM(u8 dutyCycle ,u32 freq);
/*
void M_Timer0_void_setFastPWM(frequency ,duty);
void M_Timer0_void_ssetphaseCorrectPWM(frequency , duty);
*/
#endif /* TIMER0_TIMER_INIT_H_ */
