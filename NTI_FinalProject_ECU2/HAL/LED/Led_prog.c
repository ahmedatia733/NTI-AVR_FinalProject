#include "Led_cfg.h"

#if LED_SWITCH

#include "STD_TYPES.h"


#include "Dio_int.h"

#include "Led_priv.h"
#include "Led_int.h"





void H_LED_voidTurnOn(Led_IDtype LedId)
{
	switch(LedId)
	{
	case LED_RED :
#if LED_RED_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_RED_PIN, DIO_HIGH);
#elif LED_RED_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_RED_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_GREEN  :
#if LED_GREEN_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_GREEN_PIN, DIO_HIGH);
#elif LED_GREEN_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_GREEN_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_BLUE   :
#if LED_BLUE_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_BLUE_PIN, DIO_HIGH);
#elif LED_BLUE_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_BLUE_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_YELLOW :
#if LED_YELLOW_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_YELLOW_PIN, DIO_HIGH);
#elif LED_YELLOW_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_YELLOW_PIN, DIO_LOW);
#else
#error "Wrong led direction configurations"
#endif
		break;
	}
}

void H_LED_voidTurnOff(Led_IDtype LedId)
{
	switch(LedId)
	{
	case LED_RED :
#if LED_RED_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_RED_PIN, DIO_LOW);
#elif LED_RED_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_RED_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_GREEN  :
#if LED_GREEN_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_GREEN_PIN, DIO_LOW);
#elif LED_GREEN_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_GREEN_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_BLUE   :
#if LED_BLUE_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_BLUE_PIN, DIO_LOW);
#elif LED_BLUE_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_BLUE_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	case LED_YELLOW :
#if LED_YELLOW_DIRECTION == LED_ACTIVE_HIGH
		M_DIO_voidSetPinValue(LED_YELLOW_PIN, DIO_LOW);
#elif LED_YELLOW_DIRECTION == LED_ACYIVE_LOW
		M_DIO_voidSetPinValue(LED_YELLOW_PIN, DIO_HIGH);
#else
#error "Wrong led direction configurations"
#endif
		break;
	}
}


void H_LED_voidToggle(Led_IDtype LedId)
{
	switch(LedId)
	{
	case LED_RED :
		M_DIO_voidTogglePin(LED_RED_PIN);
		break;
	case LED_GREEN  :
		M_DIO_voidTogglePin(LED_GREEN_PIN);
		break;
	case LED_BLUE   :
		M_DIO_voidTogglePin(LED_BLUE_PIN);
		break;
	case LED_YELLOW :
		M_DIO_voidTogglePin(LED_YELLOW_PIN);

		break;
	}
}


#endif
