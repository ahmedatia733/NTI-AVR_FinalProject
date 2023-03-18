/*
 * TIM_private.h
 *
 *  Created on: Feb 25, 2023
 *      Author: alish
 */

#ifndef TIM_TIM_PRIVATE_H_
#define TIM_TIM_PRIVATE_H_

#include "STD_TYPES.h"

#define MCU_FREQ 16000000UL

/*
 * Static global variable that will be used to maintain the number of OVF or Compare matches
   depending on the timer mode
*/
static volatile u8 timerResetsCount = 0;
static volatile u8 OVF_COUNTER = 0;

//static pointers for interrupt service routines callbacks
static void (*TIMER0_OVERFLOW_PTR)(void)  = NULL;
static void (*TIMER0_ON_COMP_PTR)(void)   = NULL;
static void (*TIMER1_OVERFLOW_PTR)(void)  = NULL;
static void (*TIMER1_ON_COMP_A_PTR)(void) = NULL;
static void (*TIMER1_ON_COMP_B_PTR)(void) = NULL;
static void (*TIMER1_CAPT_PTR)(void)	  = NULL;
static void (*TIMER2_OVERFLOW_PTR)(void)  = NULL;
static void (*TIMER2_ON_COMP_PTR)(void)   = NULL;



#endif /* TIM_TIM_PRIVATE_H_ */
