/*
 * TIM_config.h
 *
 *  Created on: Feb 25, 2023
 *      Author: alish
 */

#ifndef TIM_CONFIG_H_
#define TIM_CONFIG_H_

#include "TIM_types.h"

#define TIMER_SWITCH 1

/********************************************************/
			//TIMER 0 : belongings
typedef struct{
	TIMER0_mode_t timer_mode;
	TIMER_output_compare_mode_t output_compare_mode;
	TIMER_clk_select_mode_t clk_mode;
	TIMER_interrupt_mask_t overflow_int_mask ;
	TIMER_interrupt_mask_t oc_int_mask ;
	}TIMER0_config_t;


/******************************/
		//TIMER 1 : belongings

typedef struct{
	TIMER1_mode_t timer_mode;
	TIMER_output_compare_mode_t output_compare_modeA;
	TIMER_output_compare_mode_t output_compare_modeB;
	TIMER_clk_select_mode_t clk_mode;
	TIMER_interrupt_mask_t overflow_interrupt_mask;
	TIMER_interrupt_mask_t comp_a_interrupt_mask;
	TIMER_interrupt_mask_t comp_b_interrupt_mask;
	TIMER_interrupt_mask_t capt_interrupt_mask;

	}TIMER1_config_t;


#endif /* TIM_CONFIG_H_ */
