/*
 * main.c
 *
 *  Created on: Mar 17, 2023
 *      Author: alish
 */
#define F_CPU 16000000UL
#include <util/delay.h>


/*LIB*/
#include "STD_TYPES.h"
/*MCAL*/
#include "Port_int.h"
//#include "TIM_interface.h"
//#include "LDR_interface.h"
//#include "ADC_interface.h"
#include "GIE_interface.h"
#include "CLCD_int.h"

/*Application Includes*/
#include "LedIntensity.h"


/*WIFI includes*/
#include "WifiBroker.h"i"


/* Global Externs */
extern const Port_Configtype Port_ConfigArr[PORT_PINS_CONFIG_ARR_SIZE];




int main(){


	/* Module Initialization */

M_GIE_void_EnableGlobalInterrupt();
M_PORT_voidInit(Port_ConfigArr);
H_CLCD_voidInit();

/*
//timer
TIMER0_config_t timer0;
*/


/*
M_TIMER0_void_StartFastPWM(50, 10);
APP_void_LedIntensity_LDR_init();
*/

H_LM35_void_Init();

u16 res;
u16 resOVER40;
M_TIMER0_void_StartFastPWM(100, 100);


while(1){

	//LDR app
	/*H_CLCD_voidClearDisplay();

	res = APP_void_LedIntensity_GetLevelFromLDR();
	M_TIMER0_void_StartFastPWM(100, res);

	H_CLCD_void_Send_u32Num(res);

	_delay_ms(10);*/


	//LM35 app


}



return 0;
}
