#ifndef DIO_INT_H_
#define DIO_INT_H_


#include "STD_TYPES.h"
#include "Dio_types.h"
#include "Dio_cfg.h"

Dio_PinLevelType M_DIO_enGetPinValue(Dio_ChannelType ChannelId);

void M_DIO_voidSetPinValue(Dio_ChannelType ChannelId,Dio_PinLevelType Level);

Dio_PortLevelType M_DIO_enGetPortValue(Dio_PortType PortId);

void M_DIO_voidSetPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

void M_DIO_voidTogglePin(Dio_ChannelType channelId);

#endif /* DIO_DIO_INT_H_ */
