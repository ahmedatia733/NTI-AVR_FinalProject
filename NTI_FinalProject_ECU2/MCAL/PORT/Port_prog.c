#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Port_int.h"
#include "Port_cfg.h"
#include "Mcu_HW.h"
void M_PORT_voidInit(const Port_Configtype * ConfigPtr)
{
	/* Check the pointer is not equal NULL */
	if(ConfigPtr != NULL )
	{
		u8 Local_u8Pin;
		u8 Local_u8Port;
		u8 Local_u8Counter;
		for(Local_u8Counter = 0;Local_u8Counter<PORT_PINS_CONFIG_ARR_SIZE;Local_u8Counter++)
		{
			Local_u8Pin  = ((ConfigPtr[Local_u8Counter].PinNumber)%10);
			Local_u8Port = ((ConfigPtr[Local_u8Counter].PinNumber)/10);
			switch(Local_u8Port)
			{
			case PORTA :
				/* Set the direction of pin */
				if(ConfigPtr[Local_u8Counter].PinDirection == PORT_OUTPUT)
				{
					/* Set the output direction by set the bits in DDRA register */
					SET_BIT(DDRA_REG,Local_u8Pin);
					/* Set the Initial Value in PORTA register */
					if(ConfigPtr[Local_u8Counter].InitialValue == PORT_HIGH)
					{
						SET_BIT(PORTA_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InitialValue == PORT_LOW)
					{
						CLR_BIT(PORTA_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else if(ConfigPtr[Local_u8Counter].PinDirection == PORT_INPUT)
				{
					/* Set the input direction by clear the bits in DDRA register */
					CLR_BIT(DDRA_REG,Local_u8Pin);
					/* Set the internal attach in PORTA register */
					if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_FLOATING)
					{
						CLR_BIT(PORTA_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_PULLUP)
					{
						SET_BIT(PORTA_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else
				{
					/* Error */
				}
				break;
			case PORTB :
				/* Set the direction of the pin */
				if(ConfigPtr[Local_u8Counter].PinDirection == PORT_OUTPUT)
				{
					/* Set the output direction by set the bits in DDRB register */
					SET_BIT(DDRB_REG,Local_u8Pin);
					/* Set the Initial Value in PORTB register */
					if(ConfigPtr[Local_u8Counter].InitialValue == PORT_HIGH)
					{
						SET_BIT(PORTB_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InitialValue == PORT_LOW)
					{
						CLR_BIT(PORTB_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else if(ConfigPtr[Local_u8Counter].PinDirection == PORT_INPUT)
				{
					/* Set the input direction by clear the bits in DDRB register */
					CLR_BIT(DDRB_REG,Local_u8Pin);
					/* Set the internal attach in PORTB register */
					if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_FLOATING)
					{
						CLR_BIT(PORTB_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_PULLUP)
					{
						SET_BIT(PORTB_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else
				{
					/* Error */
				}
				break;
			case PORTC :
				/* Set the direction of the pin */
				if(ConfigPtr[Local_u8Counter].PinDirection == PORT_OUTPUT)
				{
					/* Set the output direction by set the bits in DDRC register */
					SET_BIT(DDRC_REG,Local_u8Pin);
					/* Set the Initial Value in PORTC register */
					if(ConfigPtr[Local_u8Counter].InitialValue == PORT_HIGH)
					{
						SET_BIT(PORTC_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InitialValue == PORT_LOW)
					{
						CLR_BIT(PORTC_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else if(ConfigPtr[Local_u8Counter].PinDirection == PORT_INPUT)
				{
					/* Set the input direction by clear the bits in DDRC register */
					CLR_BIT(DDRC_REG,Local_u8Pin);
					/* Set the internal attach in PORTB register */
					if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_FLOATING)
					{
						CLR_BIT(PORTC_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_PULLUP)
					{
						SET_BIT(PORTC_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else
				{
					/* Error */
				}
				break;
			case PORTD :
				/* Set the direction of the pin */
				if(ConfigPtr[Local_u8Counter].PinDirection == PORT_OUTPUT)
				{
					/* Set the output direction by set the bits in DDRD register */
					SET_BIT(DDRD_REG,Local_u8Pin);
					/* Set the Initial Value in PORTD register */
					if(ConfigPtr[Local_u8Counter].InitialValue == PORT_HIGH)
					{
						SET_BIT(PORTD_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InitialValue == PORT_LOW)
					{
						CLR_BIT(PORTD_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else if(ConfigPtr[Local_u8Counter].PinDirection == PORT_INPUT)
				{
					/* Set the input direction by clear the bits in DDRD register */
					CLR_BIT(DDRD_REG,Local_u8Pin);
					/* Set the internal attach in PORTD register */
					if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_FLOATING)
					{
						CLR_BIT(PORTD_REG,Local_u8Pin);
					}
					else if(ConfigPtr[Local_u8Counter].InternalAttach == PORT_PULLUP)
					{
						SET_BIT(PORTD_REG,Local_u8Pin);
					}
					else
					{
						/* Error */
					}
				}
				else
				{
					/* Error */
				}
				break;
			}

		}
	}
	else
	{
		/* Error */
	}
}
