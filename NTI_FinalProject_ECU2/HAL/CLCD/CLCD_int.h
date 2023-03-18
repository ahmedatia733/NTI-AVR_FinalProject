#ifndef CLCD_INT_H_
#define CLCD_INT_H_

#include "CLCD_types.h"
#include "CLCD_cfg.h"

#define _4_BIT_MODE   1
#define _8_BIT_MODE   2


#define FONT1    1
#define FONT2    2

#define ENABLE   1
#define DISABLE  2


void H_CLCD_voidInit(void);

void H_CLCD_voidSendData(u8 Copy_u8Data);

void H_CLCD_voidSendCommand(u8 Copy_u8Command);

void H_CLCD_voidSendString(const u8 * Copy_ps8Str);

void H_CLCD_voidGotoXY(u8 Copy_u8Row,u8 Copy_u8Colum);

void H_CLCD_voidCreatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode);

void H_CLCD_voidDisplayCustomChar(u8 Copy_u8charCode);

void H_CLCD_void_Send_u32Num(s32 n);


void H_CLCD_voidClearDisplay();

void H_CLCD_Send_f64(f64 f);

#endif /* CLCD_INT_H_ */
