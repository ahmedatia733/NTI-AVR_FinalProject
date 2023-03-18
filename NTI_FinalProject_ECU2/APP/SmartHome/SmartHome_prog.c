/*
 * SmartHome_prog.c
 *
 *  Created on: ١٨‏/٠٣‏/٢٠٢٣
 *      Author: ahmed
 */

#include "SmartHome_init.h"



extern S_WIFI_Config_t WIFI_Config;


void APP_void_StartWIFIserver(void)
{
	H_WIFI_void_WIFIInit( WIFI_Config );
	H_WIFI_void_StartTCPServer();
}


APP_WIFI_UpdateStatus_t APP_UpdateStatus_t_WIFIUpdate(char *recevBuffer)
{
if(H_WIFI_ReceiveStatue_t_WIFIreceive(recevBuffer) == WIFI_Data_Receved)
{
	return APP_WIFI_Updated;
}
return APP_WIFI_NO_Update;

}
