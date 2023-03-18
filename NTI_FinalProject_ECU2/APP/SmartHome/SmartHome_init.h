/*
 * SmartHome_init.h
 *
 *  Created on: ١٨‏/٠٣‏/٢٠٢٣
 *      Author: ahmed
 */

#ifndef SMARTHOME_SMARTHOME_INIT_H_
#define SMARTHOME_SMARTHOME_INIT_H_

#include "STD_TYPES.h"
#include "SmartHome_priv.h"
#include "SmartHome_types.h"


/*Functions Prototypes*/

 /*Light Intensity functions prototypes*/
void APP_SmartHome_void_LightIntensity_init();
u8  APP_SmartHome_u8_GetIntensityLevel();

/*Appliances functions prototypes*/
void APP_SmartHome_void_UpdateAppliance();
APP_COMMAND_ERROR_t APP_SmartHome_ERROR_t_GetAppliancesState(APP_Command_t command);

/*TCP functions prototypes*/
APP_COMMAND_ERROR_t APP_SmartHome_ERROR_t_GetCommand(u8* msgArray, APP_Command_t* command);

#endif /* SMARTHOME_SMARTHOME_INIT_H_ */
