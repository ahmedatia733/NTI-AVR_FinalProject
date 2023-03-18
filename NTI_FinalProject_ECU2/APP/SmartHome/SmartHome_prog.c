/*
 * SmartHome_prog.c
 *
 *  Created on: ١٨‏/٠٣‏/٢٠٢٣
 *      Author: ahmed
 */

#include "SmartHome_init.h"
#include "LDR_interface.h"
#include "LDR_config.h"
#include "string.h"

/*Globals*/
u8* devices_names [DEVICES_COUNT] = { APP_LED, APP_FAN};
u8* devices_modes [DEVICES_MODES_COUNT] = { APP_MANUAL, APP_AUTO };
u8* devices_states [DEVICES_STATES_COUNT] = { APP_STATE_ON, APP_STATE_OFF };
u8* devices_commands [DEVICES_COMMANDS_COUNT] = { APP_AV_COMMAND, APP_DV_COMMAND, APP_M_COMMAND};

extern APP_Device_t DEVICES_STATE_LIST[DEVICES_COUNT];

void APP_SmartHome_void_LightIntensity_init(){

	H_LDR_void_Init();

}


u8 APP_SmartHome_u8_GetIntensityLevel(){
	 u8 intensityLVL = 0;
	 u16 LDRreading = H_LDR_u16_Read(LDR_ADC_CHANNEL);

	 /*Mapping LDR_MIN_READING:LDR_MAX_READING to ---> (0:100)*/
     /*intensityLVL =
    	((LDRreading - LDR_MIN_READING) / (LDR_MAX_READING - LDR_MIN_READING))*
		(LED_MAX_INTENSITY - LED_MIN_INTENSITY) + LED_MIN_INTENSITY;*/

	 //DOES SOME KIND OF MAPPING
	 intensityLVL = LDRreading /(u16)50;
     return intensityLVL;

}



APP_COMMAND_ERROR_t APP_SmartHome_ERROR_t_GetAppliancesState(APP_Command_t command){

	u8 device_id ;

	if(strcmp(command.device_name,APP_LED) == 0 ){

		device_id = LED_ID;
	}else if(strcmp(command.device_name, APP_FAN)){

				device_id = FAN_ID;
	}else{
		return BAD_DEVICE_NAME;
	}


	DEVICES_STATE_LIST[device_id].update_flag = 1;

	if(strcmp(command.command_type, APP_AV_COMMAND) == 0){
		strcpy(DEVICES_STATE_LIST[device_id].value, command.value);
	}else if(strcmp(command.command_type, APP_DV_COMMAND) == 0){
		strcpy(DEVICES_STATE_LIST[device_id].device_state, command.value);
	}else if(strcmp(command.command_type, APP_M_COMMAND) == 0){
		strcpy(DEVICES_STATE_LIST[device_id].device_mode, command.value);
	}else{
		return BAD_COMMAND_TYPE;
	}


	DEVICES_STATE_LIST[LED_ID].update_flag = 1;


	return SUCCEEDED;
}


APP_COMMAND_ERROR_t APP_SmartHome_ERROR_t_GetCommand(u8* msgArray, APP_Command_t* command){

	APP_COMMAND_ERROR_t error_status = SUCCEEDED;
	char *token;
	/* get the first token */
	token = strtok(msgArray, TOKEN_DELIMETER);

	if(token != 0){

	/* walk through other tokens */
		if(strcmp(token,COMMAND_HEADER) == 0){
			//it's Correct Header
			//Get next token [Device Name]
			token = strtok(0, TOKEN_DELIMETER);

			if(token != 0){
				//check if any device name exists
				for(int loopVar = 0; loopVar < DEVICES_COUNT; loopVar++){
					error_status = BAD_DEVICE_NAME;
					if(strcmp(token,devices_names[loopVar]) == 0){
						//there's correct Device Name
						strcpy(command->device_name, token);
						error_status = SUCCEEDED;
						break;
					}
				}
			}else{
				error_status = NON_EXISTING_DEVICE_NAME;
			}

			//Get next token [Command Type]
			token = strtok(0, TOKEN_DELIMETER);
			if(token != 0){
				//check if any Modes exists
				for(int loopVar = 0; loopVar < DEVICES_COMMANDS_COUNT; loopVar++){
					error_status = BAD_COMMAND_TYPE;
					if(strcmp(token,devices_commands[loopVar]) == 0){
						//there's correct Mode
						strcpy(command->command_type, token);
						error_status = SUCCEEDED;
						break;
					}
				}
			}else{
				error_status = NON_EXISTING_COMMAND_TYPE;
			}

			//Get next token [value]
			token = strtok(0, TOKEN_DELIMETER);
			if(token != 0){
				//There's a value exits
				strcpy(command->value, token);
				error_status = SUCCEEDED;
			}else{
				error_status = NON_EXISTING_VALUE;
			}

		}else{
			error_status =  BAD_HEADER;
		}

	}else{
		error_status =  NON_EXISTING_HEADER;
	}

	return error_status;


}

