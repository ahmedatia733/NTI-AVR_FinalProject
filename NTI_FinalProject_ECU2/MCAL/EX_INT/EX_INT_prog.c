/*
 * EX_INT_prog.c
 *
 *  Created on: Feb 24, 2023
 *      Author: alish
 *
 */
#include "EX_INT_config.h"
#if EX_INT_SWITCH


#include "EX_INT_interface.h"
#include "EX_INT_types.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "EX_INT_config.h"



void (*localPTR_INT0)(void) = NULL;
void (*localPTR_INT1)(void) = NULL;
void (*localPTR_INT2)(void) = NULL;

void M_EX_INT_void_Enable(EX_INT_config_t int_config){
	switch(int_config.int_src){
		case EX_INT_INT0:
			SET_BIT(GICR_REG,GICR_INT0_BIT);
		break;
		case EX_INT_INT1:
			SET_BIT(GICR_REG,GICR_INT1_BIT);
		break;
		case EX_INT_INT2:
			SET_BIT(GICR_REG,GICR_INT2_BIT);
		break;
	}
}

void M_EX_INT_void_Disable(EX_INT_config_t int_config){
	switch(int_config.int_src){
		case EX_INT_INT0:
			CLR_BIT(GICR_REG,GICR_INT0_BIT);
		break;
		case EX_INT_INT1:
			CLR_BIT(GICR_REG,GICR_INT1_BIT);
		break;
		case EX_INT_INT2:
			CLR_BIT(GICR_REG,GICR_INT2_BIT);
		break;
	}
}
void M_EX_INT_void_SetTriggering(EX_INT_config_t int_config){
	//trigger
	switch(int_config.int_src){
	case EX_INT_INT0:
		switch(int_config.int_trigger){
		case EX_INT_low_level:
			CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;
		case EX_INT_both_edges:
			SET_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			CLR_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;
		case EX_INT_falling:
			CLR_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;
		case EX_INT_rising:
			SET_BIT(MCUCR_REG,MCUCR_ISC00_BIT);
			SET_BIT(MCUCR_REG,MCUCR_ISC01_BIT);
			break;
		}
		break;
		case EX_INT_INT1:
			switch(int_config.int_trigger){
			case EX_INT_low_level:
				CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
				CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
				break;
			case EX_INT_both_edges:
				SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
				CLR_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
				break;
			case EX_INT_falling:
				CLR_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
				SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
				break;
			case EX_INT_rising:
				SET_BIT(MCUCR_REG,MCUCR_ISC10_BIT);
				SET_BIT(MCUCR_REG,MCUCR_ISC11_BIT);
				break;
			}
			break;
			case EX_INT_INT2:
				switch(int_config.int_trigger){
				case EX_INT_falling:
					CLR_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
					break;
				case EX_INT_rising:
					SET_BIT(MCUCSR_REG,MCUCSR_ISC2_BIT);
					break;
					break;
				}
	}
}


void M_EX_INT_void_SetCallBack (EX_INT_config_t int_config , void (*call_back_func)(void)){

		switch(int_config.int_src){

		case EX_INT_INT0:
			localPTR_INT0 = call_back_func;
			break;
		case EX_INT_INT1:
			localPTR_INT1 = call_back_func;
			break;
		case EX_INT_INT2:
			localPTR_INT2 = call_back_func;
			break;
		}
}

ISR(INT0_vect){

	if(localPTR_INT0 != NULL)
		localPTR_INT0();



}

ISR(INT1_vect){
	if(localPTR_INT1 != NULL)
 		localPTR_INT1();
}

ISR(INT2_vect){

	if(localPTR_INT2 != NULL)
		localPTR_INT2();

}

#endif
