/*
 * TIM_types.h
 *
 *  Created on: Feb 25, 2023
 *      Author: alish
 */

#ifndef TIM_TIM_TYPES_H_
#define TIM_TIM_TYPES_H_


//MODE SELECTION
typedef enum {
	TIMER0_NORMAL_MODE = 0,
	TIMER0_PHASECORRECT_PWM_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FAST_PWM_MODE,
	}TIMER0_mode_t;



/****************************************/
	//TIMER 1 : belongings
/****************************************/
typedef enum{
	TIMER1_NORMAL =0,
	TIMER1_PC_PWM_8bit_0x00FF,
	TIMER1_PC_PWM_9bit_0x01FF,
	TIMER1_PC_PWM_10bit_0x03FF,
	TIMER1_CTC_OCR1A,
	TIMER1_FAST_PWM_8bit_0x00FF,
	TIMER1_FAST_PWM_9bit_0x01FF,
	TIMER1_FAST_PWM_10bit_0x03FF,
	TIMER1_PFC_PWM_ICR1,
	TIMER1_PFC_PWM_OCR1A,
	TIMER1_PC_PWM_ICR1,
	TIMER1_PC_PWM_OCR1A,
	TIMER1_CTC_ICR1,
	NOT_RESRVED,
	TIMER1_FAST_PWM_ICR1,
	TIMER1_FAST_PWM_OCR1A,
	}TIMER1_mode_t;

typedef enum{
	TIMER1_ICU_FALLING = 0,
	TIMER1_ICU_RISING = 1,
	}TIMER1_ICU_trigger_edge_t;


/***************************************************/
		//APPLIES to Timer0 , Timer1 and Timer2

typedef enum {
	TIMER0_OVERFLOW,
	TIMER0_ON_COMP,
	TIMER1_OVERFLOW,
	TIMER1_ON_COMP_A,
	TIMER1_ON_COMP_B,
	TIMER1_CAPT,
	TIMER2_OVERFLOW,
	TIMER2_ON_COMP,
	}TIMER_INT_SOURCE_t;    //APPLIES for TIMER0, TIMER1, and TIMER2

//CLK SELECT
typedef enum {
	PRESCALER_STOP_TIMER = 0,
	PRESCALER_1,
	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024,
	EXTERNAL_FALLING_EDGE,
	EXTERNAL_RAISING_EDGE,
	}TIMER_clk_select_mode_t;      //APPLIES for TIMER0, TIMER1, and TIMER2

typedef enum{
	TIMER_DISABLE_INTERRUPT= 0,
	TIMER_ENABLE_INTERRUPT = 1
	}TIMER_interrupt_mask_t;         //APPLIES for TIMER0, TIMER1, and TIMER2


//OC0 output states for all timer modes (normal, CTC, Phase-correct PWM, Fast PWM)
typedef enum {
	DISCONNECTED = 0,
	TOGGLE_ON_COMPARE,
	CLEAR_ON_COMPARE,
	SET_ON_COMPARE,
	INVERTING_PWM,
	NON_INVERTING_PWM,
	}TIMER_output_compare_mode_t;         //APPLIES for TIMER0, TIMER1, and TIMER2

#endif /* TIM_TIM_TYPES_H_ */
