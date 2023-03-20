/*

 * Timer_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */
#include "Timer_cfg.h"
#include "Timer_init.h"
#include "STD_TYPES.h"
static void (*Timer0_OVF_FnPtr)(void) = NULL;
static void (*Timer0_OC_FnPtr)(void) = NULL;

static Timer_prescaler_t G_prescaler = 0;
static Timer0_Mode_t G_Timer0Mode = 0;

static  u32 G_prescalerArr[5] = {1,8,64,256,1024};

static unsigned int G_NumberOfOFV = 0;
static unsigned int G_Timer0Remaining = 0;

volatile static long unsigned int GcounterOverFlow = 0;

void M_Timer0_void_Init(Timer0_Mode_t Mode, Timer0_OC0_Mode_t OC0_Mode,
		Timer_prescaler_t prescaler) {
	G_prescaler = prescaler;

	TCCR0_REG &= CLEAR_PRESCALLER_MASK;

	TCCR0_REG &= CLEAR_TIMER_MODE_REG;
	TCCR0_REG |= Mode;

	TCCR0_REG &= CLEAR_WAVEG_MASK;
	TCCR0_REG |= OC0_Mode;
}

void M_Timer0_void_start() {
	TCCR0_REG &= CLEAR_PRESCALLER_MASK;
	TCNT0_REG = G_Timer0Remaining;//Check mode here
	TCCR0_REG |= G_prescaler;
}

void M_Timer0_void_stop() {
	TCCR0_REG &= CLEAR_PRESCALLER_MASK;
}

long long unsigned int M_Timer0_void_GetCounts() {
	long long unsigned int counts = GcounterOverFlow*256;
	counts += TCNT0_REG ;
	return counts;
}

void M_Timer0_void_setDelayTimeMilliSec(u32 millis){

	u32 tikTime = G_prescalerArr[G_prescaler-1] / (F_CPU / 1000000);
	u32 numberOfTiks = (millis * 1000) / tikTime;
	G_NumberOfOFV = numberOfTiks / 256;
	G_Timer0Remaining = numberOfTiks % 256;
	if (G_Timer0Remaining > 0 ) {G_NumberOfOFV++;}
	G_Timer0Remaining = 265 - G_Timer0Remaining;

}


void M_Timer0_void_setFastPWM(u8 dutyCycle ,u32 freq)
{
	u32 frequancyTest = 0;
	u32 freqDiff = 0;
	u32 miniFreqDiff = 0xFF;

	int i ;
	for(i = 0; i < 5 ; i++)
	{
		frequancyTest = F_CPU / (G_prescalerArr[i] * 256 );
		if (frequancyTest > freq)
		{
			freqDiff = frequancyTest - freq;
		}
		else if(frequancyTest < freq)
		{
			freqDiff =freq - frequancyTest;
		}

		else if(frequancyTest == freq)
		{
			break;
		}
		if(freqDiff < miniFreqDiff){
			miniFreqDiff = freqDiff;
			G_prescaler = i+1;
		}
	}

	OCR0_REG = ((dutyCycle*0.01)*256);
	TCCR0_REG &= CLEAR_PRESCALLER_MASK;
	TCCR0_REG |= G_prescaler;


}

void M_Timer0_void_EnableInt() {
	TIMSK_REG |= NORMAL_MODE_INTERRUPT_SET;
}

void M_Timer0_void_DisableInt() {
	TIMSK_REG |= NORMAL_MODE_INTERRUPT_CLEAR;
}

void M_Timer0_void_setCallBack(void (*T0_OVF_CB_FnPtr)(void))
{
	if(T0_OVF_CB_FnPtr != NULL)
	{
		Timer0_OVF_FnPtr = T0_OVF_CB_FnPtr;
	}
}


ISR(TIMER0_OVF_vect) {
	static u8 count = 0;
	count++;
	if(count == G_NumberOfOFV)
	{	count = 0;
		TCNT0_REG = G_Timer0Remaining;
		if (Timer0_OVF_FnPtr != NULL) {
			Timer0_OVF_FnPtr();
		}
	}


	GcounterOverFlow++;

}
ISR(TIMER0_COMP_vect) {
	if (Timer0_OC_FnPtr != NULL) {
		Timer0_OC_FnPtr();
	}
}



