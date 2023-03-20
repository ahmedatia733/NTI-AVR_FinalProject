/*****************************************************************
* FILE DESCRIPTION:
----------------------------------------------------------------
*  file    : Port_cfg.h
*  details : Header file for configuration PORT Driver.
******************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
/* please Configure number of pins to configure */
#define PORT_PINS_CONFIG_ARR_SIZE    27
#define SmallOS_PortConfig_ARR_SIZE 20
#define Configurable_Duty_freq_PortConfig_ARR_SIZE 23
#define LoginSystem_PortConfig_ARR_SIZE 23


/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
typedef struct
{
	Port_PinType             PinNumber;
	Port_PinLevelType        InitialValue;
	Port_PinDirectionType    PinDirection;
	Port_InternalAttachType  InternalAttach;
}Port_Configtype;

#endif /* PORT_CFG_H_ */
