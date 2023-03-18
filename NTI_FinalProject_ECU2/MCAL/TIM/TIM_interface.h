/*
 * TIM_interface.h
 *
 *  Created on: Feb 25, 2023
 *      Author: alish
 */

#ifndef TIM_TIM_INTERFACE_H_
#define TIM_TIM_INTERFACE_H_

#include "STD_TYPES.h"
#include "TIM_types.h"
#include "TIM_config.h"


//TIMER0
void M_TIMER0_void_Init(TIMER0_config_t timer);
void M_TIMER0_void_SetOutputCompareMode(TIMER_output_compare_mode_t oc_mode);
void M_TIMER0_void_SetTimerMode(TIMER0_mode_t mode);
void M_TIMER0_void_Start(u8 prescaler);
void M_TIMER0_void_stop();
u32 M_TIMER0_void_GetCounts();
u32 M_TIMER0_void_SetDelayTimeMilliSec_NORMAL(u32 millisec, void (*FuncPTR)());
void M_TIMER0_void_StartFastPWM(u32 freq, u8 duty);
void M_TIMER0_void_StartPhaseCorrectPWM(u32 freq ,u8 duty);

//TIMER1
void M_TIMER1_void_ICU_init_Interrupt_OP(u8 prescaler, TIMER1_ICU_trigger_edge_t edge);
void M_TIMER1_void_Start(u8 prescaler);
void M_TIMER1_void_Stop();
void M_TIMER1_void_ICU_trigger_edge(TIMER1_ICU_trigger_edge_t edge);
u16 M_TIMER1_void_ICU_takeReading();

//APPLIES for TIMER0, TIMER1, and TIMER2
void M_TIMER_void_CallBack(TIMER_INT_SOURCE_t int_src, void (*localFuncPTR)(void));
void M_TIMER_void_EnableINT(TIMER_INT_SOURCE_t int_src);
void M_TIMER_void_DisableINT(TIMER_INT_SOURCE_t int_src);


#endif /* TIM_TIM_INTERFACE_H_ */
