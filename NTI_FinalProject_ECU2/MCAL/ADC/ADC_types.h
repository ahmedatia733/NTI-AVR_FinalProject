/*
 * ADC_types.h
 *
 *  Created on: Mar 16, 2023
 *      Author: alish
 */

#ifndef ADC_ADC_TYPES_H_
#define ADC_ADC_TYPES_H_


typedef enum {
	ADC_AUTO_TRIGGER_DISABLE = 0,
	ADC_AUTO_TRIGGER_ENABLE
	}ADC_auto_trigger_t;

typedef enum{
	ADC_INTERRUPT_DISABLE = 0,
	ADC_INTERRUPT_ENABLE
	}ADC_interrupt_t;

typedef enum{
	ADC_PRESCALER_2 = 0,
	ADC_PRESCALER_2_ = 1,
	ADC_PRESCALER_4 = 2,
	ADC_PRESCALER_8 = 3,
	ADC_PRESCALER_16 = 4,
	ADC_PRESCALER_32 = 5,
	ADC_PRESCALER_64 = 6,
	ADC_PRESCALER_128 = 7
	}ADC_prescaler_t;

typedef enum{
	ADC_FREE_RUNNING = 0,
	ADC_ANALOG_COMP  = 1,
	ADC_EX_INT_REQ0	 = 2,
	ADC_TIMER0_COMP  = 3,
	ADC_TIMER0_OVF	 = 4,
	ADC_TIMER1B_COMP = 5,
	ADC_TIMER1_OVF   = 6,
	ADC_TIMER1_CAP   = 7
	}ADC_auto_trigger_source_t;

typedef enum
{
	ADC_0 = 0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7
}ADC_channel_t;

typedef enum {
	ADC_EXTERNAL_AREF = 0,
	ADC_AVCC          = 1,
	xXxXxXxXxXxXx = 2,
	ADC_INTERNAL	  = 3

	}ADC_voltage_ref_t;

typedef enum {
	ADC_RIGHT_ADJUST = 0,
	ADC_LEFT_ADJUST  = 1
	}ADC_adjust_result_t;

typedef enum{
	ADC_POLL =0,
	ADC_INTERRUPT
	}ADC_read_method_t;

typedef enum{
	ADC_FAILED = 0,
	ADC_SUCCEED
}ADC_state_code_t;

#endif /* ADC_ADC_TYPES_H_ */
