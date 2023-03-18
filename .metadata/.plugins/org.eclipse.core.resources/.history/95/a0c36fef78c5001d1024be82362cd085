/*
 * SmartHome_types.h
 *
 *  Created on: ١٨‏/٠٣‏/٢٠٢٣
 *      Author: ahmed
 */

#ifndef SMARTHOME_SMARTHOME_TYPES_H_
#define SMARTHOME_SMARTHOME_TYPES_H_


#include "STD_TYPES.h"

/*Defines*/

/*FOR COMMAND TRANSLATION*/
#define TOKEN_DELIMETER		","

//Command Header
#define COMMAND_HEADER "HEAD"
//Device Name
#define DEVICES_COUNT	2
	#define	APP_LED	"light"
	#define	APP_FAN	"fan"
//Device Mode
#define DEVICES_MODES_COUNT	2
	#define	APP_MANUAL	"m"
	#define	APP_AUTO	"a"

//Device state
#define DEVICES_STATE_COUNT	2
	#define	APP_STATE_ON	"on"
	#define	APP_STATE_OFF	"off"


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
	SUCCEEDED,
}APP_COMMAND_ERROR_t;


/*Structs*/
typedef struct{

	u8 device_name[4];
	u8 device_mode[2];
	u8 device_state[4];
	u8 value;

}APP_Device_t;



#endif /* SMARTHOME_SMARTHOME_TYPES_H_ */
