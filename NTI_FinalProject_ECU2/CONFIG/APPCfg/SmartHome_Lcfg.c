/*
 * SmartHome_Lcfg.c
 *
 *  Created on: ١٨‏/٠٣‏/٢٠٢٣
 *      Author: ahmed
 */

#include "SmartHome_types.h"


APP_Device_t DEVICES_STATE_LIST[DEVICES_COUNT] = {
		{APP_LED, APP_MANUAL, APP_STATE_OFF, 50, 0},
		{APP_FAN, APP_MANUAL, APP_STATE_ON, 50, 0},
};


APP_SensorsHub_t SensorsHUB;
