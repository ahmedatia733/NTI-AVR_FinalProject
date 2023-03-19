/*
 * APP_type.h
 *
 *  Created on: Mar 18, 2023
 *      Author: alish
 */

#ifndef APP_TYPES_H_
#define APP_TYPES_H_

#include "STD_TYPES.h"

/*Defines*/

/*FOR COMMAND TRANSLATION*/
#define TOKEN_DELIMETER		","

//Command Header
#define COMMAND_HEADER "HEAD"
//Device Name
#define DEVICES_COUNT	2
	#define	APP_LED	"LED"
	#define	APP_FAN	"FAN"
//Device Mode
#define DEVICES_MODES_COUNT	2
	#define	APP_MANUAL	"M"
	#define	APP_AUTO	"A"

//Device state
#define DEVICES_STATES_COUNT	2
	#define	APP_STATE_ON	"ON"
	#define	APP_STATE_OFF	"OFF"

//Commands types
#define DEVICES_COMMANDS_COUNT	3
	#define	APP_AV_COMMAND		"AV"
	#define	APP_DV_COMMAND		"DV"
	#define	APP_M_COMMAND		"M"

//Devices ID/index
#define LED_ID	0
#define FAN_ID	1

/*Enums*/
typedef enum{
	BAD_HEADER = 0,
	NON_EXISTING_HEADER,
	BAD_DEVICE_NAME,
	NON_EXISTING_DEVICE_NAME,
	BAD_MODE,
	NON_EXISTING_MODE,
	BAD_VALUE,
	NON_EXISTING_VALUE,
	BAD_COMMAND_TYPE,
	NON_EXISTING_COMMAND_TYPE,
	SUCCEEDED,
}APP_COMMAND_ERROR_t;

typedef enum{
	APP_PA0 = 10,
	APP_PA1 ,
	APP_PA2 ,
	APP_PA3 ,
	APP_PA4 ,
	APP_PA5 ,
	APP_PA6 ,
	APP_PA7 ,
	APP_PB0 = 20,
	APP_PB1 ,
	APP_PB2 ,
	APP_PB3 ,
	APP_PB4 ,
	APP_PB5 ,
	APP_PB6 ,
	APP_PB7 ,
	APP_PC0 = 30,
	APP_PC1 ,
	APP_PC2 ,
	APP_PC3 ,
	APP_PC4 ,
	APP_PC5 ,
	APP_PC6 ,
	APP_PC7 ,
	APP_PD0 = 40,
	APP_PD1 ,
	APP_PD2 ,
	APP_PD3 ,
	APP_PD4 ,
	APP_PD5 ,
	APP_PD6 ,
	APP_PD7
}APP_Channel_t;

typedef enum
{
	APP_WIFI_Updated ,
	APP_WIFI_NO_Update
}APP_WIFI_UpdateStatus_t;

/*Structs*/
typedef struct{

	char device_name[4];
	char device_mode[2];
	char device_state[4];
	char value[3];
	char update_flag;

}APP_Device_t;

typedef struct{
	char device_name[4]; //LED , FAN
	char command_type[3];   //AV  , DV  , M
	char value[3];	   //"0" : "100"
}APP_Command_t;

typedef struct{

	u8 temperature;
	u8 illumin;
	u8 speed;
	u8 intensity;

}APP_SensorsHub_t;




#endif /* APP_TYPES_H_ */
