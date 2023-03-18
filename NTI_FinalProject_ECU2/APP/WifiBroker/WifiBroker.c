/*
 * WifiBroker.c
 *
 *  Created on: Mar 18, 2023
 *      Author: alish
 */

#include <string.h>
#include "WifiBroker.h"

/*Globals*/
u8** DEVICE_NAME [DEVICES_COUNT] = { APP_LED, APP_FAN};
u8** DEVICE_MODE [DEVICES_MODES_COUNT] = { APP_MANUAL, APP_AUTO };

APP_Device_t DEVICES_STATE_LIST[DEVICES_COUNT] = {
		{APP_LED,	APP_AUTO,	50},
		{APP_FAN,	APP_AUTO,	50},
};

APP_COMMAND_ERROR_t APP_en_GetCommand(u8* msgArray, APP_Device_t* command){

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
					if(strcmp(token,DEVICE_NAME[loopVar]) == 0){
						//there's correct Device Name
						strcpy(command->device_name, token);
						error_status = SUCCEEDED;
						break;
					}
				}
			}else{
				error_status = NON_EXISTING_DEVICE_NAME;
			}

			//Get next token [Device Mode]
			token = strtok(0, TOKEN_DELIMETER);
			if(token != 0){
				//check if any Modes exists
				for(int loopVar = 0; loopVar < DEVICES_MODES_COUNT; loopVar++){
					error_status = BAD_MODE;
					if(strcmp(token,DEVICE_MODE[loopVar]) == 0){
						//there's correct Mode
						strcpy(command->device_mode, token);
						error_status = SUCCEEDED;
						break;
					}
				}
			}else{
				error_status = NON_EXISTING_MODE;
			}

			//Get next token [value]
			token = strtok(0, TOKEN_DELIMETER);
			if(token != 0){
				//There's a value exits
				command->value = atoi(token);
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

