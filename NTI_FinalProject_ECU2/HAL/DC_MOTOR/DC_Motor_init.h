/*
 * DC_Motor_init.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef DC_MOTOR_DC_MOTOR_INIT_H_
#define DC_MOTOR_DC_MOTOR_INIT_H_

#include "Dio_int.h"
#include "TIMER0/Timer_init.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor_types.h"
#include "DC_MOTOR/DC_Motor_priv.h"


void H_DC_Motor_void_MotorForward(u8 dutyCycle , u32 freq);
void H_DC_Motor_void_MotorBackward(u8 dutyCycle , u32 freq);
void H_DC_Motor_void_MotorStop();

#endif /* DC_MOTOR_DC_MOTOR_INIT_H_ */
