/*
 * DC_Motor_prg.c
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */

#include "DC_Motor_init.h"

void H_DC_Motor_void_MotorForward(u8 dutyCycle , u32 freq)
{
	M_DIO_voidSetPinValue(DIO_PB5 , DIO_HIGH);
	M_DIO_voidSetPinValue(DIO_PB6 , DIO_HIGH);
	M_Timer0_void_Init(Timer0_FastPWM_Mode ,Timer0_CLR_Mode , Timer0_prescaler_1024);
	M_Timer0_void_setFastPWM(dutyCycle , freq);
	M_Timer0_void_start();
}


void H_DC_Motor_void_MotorBackward(u8 dutyCycle , u32 freq)
{
	M_DIO_voidSetPinValue(DIO_PB5 , DIO_LOW);
	M_DIO_voidSetPinValue(DIO_PB6 , DIO_HIGH);
	M_Timer0_void_Init(Timer0_FastPWM_Mode ,Timer0_CLR_Mode , Timer0_prescaler_1024);
	M_Timer0_void_setFastPWM(dutyCycle , freq);
	M_Timer0_void_start();

}

void H_DC_Motor_void_MotorStop()
{
	M_DIO_voidSetPinValue(DIO_PB6 , DIO_LOW);

}

