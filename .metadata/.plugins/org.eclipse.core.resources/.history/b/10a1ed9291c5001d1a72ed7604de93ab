
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_int.h"

#include "CLCD_priv.h"
#include "CLCD_cfg.h"
#include "CLCD_types.h"
#include "CLCD_int.h"
#include <stdlib.h>
#include <stdio.h>


static void H_CLCD_voidlatchByte(u8 copy_u8Byte)
{
#if CLCD_MODE == _8_BIT_MODE
	M_DIO_voidSetPortValue(CLCD_PORT, copy_u8Byte);

#elif CLCD_MODE == _4_BIT_MODE

	M_DIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW);

	M_DIO_voidSetPinValue(CLCD_D4_PIN, GET_BIT(copy_u8Byte,4));
	M_DIO_voidSetPinValue(CLCD_D5_PIN, GET_BIT(copy_u8Byte,5));
	M_DIO_voidSetPinValue(CLCD_D6_PIN, GET_BIT(copy_u8Byte,6));
	M_DIO_voidSetPinValue(CLCD_D7_PIN, GET_BIT(copy_u8Byte,7));

	M_DIO_voidSetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(1);
	M_DIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW);
	_delay_ms(3);

	M_DIO_voidSetPinValue(CLCD_D4_PIN, GET_BIT(copy_u8Byte,0));
	M_DIO_voidSetPinValue(CLCD_D5_PIN, GET_BIT(copy_u8Byte,1));
	M_DIO_voidSetPinValue(CLCD_D6_PIN, GET_BIT(copy_u8Byte,2));
	M_DIO_voidSetPinValue(CLCD_D7_PIN, GET_BIT(copy_u8Byte,3));

	M_DIO_voidSetPinValue(CLCD_E_PIN, DIO_HIGH);
	_delay_ms(1);
	M_DIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW);
	_delay_ms(3);

#else
#error "Wrong mode configuration"
#endif
}


void H_CLCD_voidInit(void)
{
#if CLCD_MODE == _8_BIT_MODE


#elif CLCD_MODE == _4_BIT_MODE

	M_DIO_voidSetPinValue(CLCD_E_PIN, DIO_LOW); // set EN to LOW
	M_DIO_voidSetPinValue(CLCD_RS_PIN, DIO_LOW); // set RS to LOW for command mode
	_delay_ms(35);
/*

	_delay_ms(1);

	*/
	/* LCD Power ON delay  */
		_delay_ms(40);

		/* Send for 4 bit initialization of LCD  */
		H_CLCD_voidSendCommand(0x33);
		H_CLCD_voidSendCommand(0x32);
		_delay_ms(2);

		/* 2 line, 5*7 matrix in 4-bit mode */
		H_CLCD_voidSendCommand(0x28);
		_delay_ms(2);

		/* Display on cursor ON */
		H_CLCD_voidSendCommand(0x0E);
		_delay_ms(2);

		/* Increment cursor (shift cursor to right) */
		H_CLCD_voidSendCommand(0x14);
		_delay_ms(2);

		/* Clear display screen */
		H_CLCD_voidSendCommand(0x01);

		_delay_ms(2);

		H_CLCD_voidSendCommand(0x06);









#else
#error "Wrong Mode Configuration"
#endif
}


void H_CLCD_voidSendData(u8 Copy_u8Data)
{
	/* Set RS pin to high for data */
	M_DIO_voidSetPinValue(CLCD_RS_PIN, DIO_HIGH);

	/* Set Data to data pins */
	H_CLCD_voidlatchByte(Copy_u8Data);
}


void H_CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/* Set RS pin to low for Command */
	M_DIO_voidSetPinValue(CLCD_RS_PIN, DIO_LOW);


	/* Set command to data pins */
	H_CLCD_voidlatchByte(Copy_u8Command);

}


void H_CLCD_voidSendString(const u8 * Copy_ps8Str)
{
	u8 Local_u8Counter = 0;

	while(Copy_ps8Str[Local_u8Counter] != '\0')
	{
		H_CLCD_voidSendData(Copy_ps8Str[Local_u8Counter]);
		_delay_ms(20);
		Local_u8Counter++;
	}
}


void H_CLCD_voidGotoXY(u8 Copy_u8Row,u8 Copy_u8Colum)
{
	u8 Local_u8Address;

	if(Copy_u8Row == 0)
	{
		/* Location is at first line */
		Local_u8Address=Copy_u8Colum;
	}
	else if(Copy_u8Row == 1)
	{
		/* Location is at second line */
		Local_u8Address=0x40+Copy_u8Colum;
	}
	else if(Copy_u8Row == 2)
	{
		/* Location is at Third line */
		Local_u8Address=0x14+Copy_u8Colum;
	}
	else if(Copy_u8Row == 3)
	{
		/* Location is at fourth line */
		Local_u8Address=0x54+Copy_u8Colum;
	}

	/* Set bit number 7 for set DDRAM address command then send the command */
	Local_u8Address = SET_BIT(Local_u8Address,7);

	H_CLCD_voidSendCommand(Local_u8Address);
}


void H_CLCD_voidCreatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{
	u8 Local_u8CGRAMAddress=0;
	u8 Local_u8Iterator;
	/* Calculate the CGRAM address whose each block is 8 bytes */
	Local_u8CGRAMAddress=(copy_u8charCode*BLOCK_SIAZE);

	/* Send CGRAM address command to LCD with setting bit 6 , clearing bit 7 */
	Local_u8CGRAMAddress = SET_BIT(Local_u8CGRAMAddress,6);

	H_CLCD_voidSendCommand(Local_u8CGRAMAddress);

	/* Write the pattern into CGRAM */
	for(Local_u8Iterator=0;Local_u8Iterator<8;Local_u8Iterator++)
	{
		H_CLCD_voidSendData(ArrPattern[Local_u8Iterator]);
	}
}


void H_CLCD_voidDisplayCustomChar(u8 Copy_u8charCode)
{
	H_CLCD_voidSendData(Copy_u8charCode);
}

void H_CLCD_void_Send_u32Num(s32 n)
{

	u8 buffer[20];

	if(n > 0)
	{
		itoa(n, buffer, 10);
		H_CLCD_voidSendString(buffer);
	}else if(n == 0){
		H_CLCD_voidSendString("0");

	}else{
		//negative

			s32 int_eq = int_eq * -1 ;
			H_CLCD_voidSendString("-");
			H_CLCD_void_Send_u32Num(int_eq);

	}


}


void H_CLCD_Send_f64(f64 f){

	/*u8 buffer[20] ;

	sprintf(buffer,"%.2f",f);

	H_CLCD_voidSendString(buffer);*/

	//I'm targeting a precision of 2 numbers after the point (100);
	s32 int_eq= f * 100;
	if(int_eq < 0 ){
		int_eq = int_eq * -1 ;
		H_CLCD_voidSendString("-");
	}
	H_CLCD_void_Send_u32Num(int_eq/100);
	H_CLCD_voidSendString(".");
	H_CLCD_void_Send_u32Num(int_eq%100);

}

void H_CLCD_voidClearDisplay(){

	H_CLCD_voidSendCommand(0x01);
	H_CLCD_voidSendCommand(0x02);



}
