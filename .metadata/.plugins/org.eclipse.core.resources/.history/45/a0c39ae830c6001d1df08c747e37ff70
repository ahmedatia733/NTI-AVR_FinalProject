/*
 * DC_MOTOR_prog.c
 *
 *  Created on: Mar 6, 2023
 *      Author: alish
 */
#include "DC_MOTOR_config.h"

#if DC_MOTOR_SWITCH

#include "TIM_interface.h"
#include "BIT_MATH.h"
#include "Dio_int.h"

#include "DC_MOTOR_interface.h"
#include "DC_MOTOR_config.h"
#include "DC_MOTOR_types.h"

void H_DC_MOTOR_void_SetSpeed(u32 freq ,u8 duty){

	M_TIMER0_void_StartPhaseCorrectPWM(freq,duty);
}

void H_DC_MOTOR_void_SetDirection(DC_MOTOR_direction_t dir){
	switch(dir){
	case DC_MOTOR_FORWARD:
		M_DIO_voidSetPinValue(DC_MOTOR_DIR_PIN, DC_MOTOR_FORWARD);
		break;
	case DC_MOTOR_BACKWARD:
		M_DIO_voidSetPinValue(DC_MOTOR_DIR_PIN, DC_MOTOR_BACKWARD);
		break;
	}
}

#endif
