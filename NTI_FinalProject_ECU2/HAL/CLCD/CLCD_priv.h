

#ifndef CLCD_PRIV_H_
#define CLCD_PRIV_H_


#define REUTURN_HOME                      0x02
#define FUNCTION_SET                      0x32
#define DISPLAY_SETUP                     0x28
#define DISPLAY_ClEAR                     0x01
#define DISPLAY_ON                        0x0E
#define CURSOR_LEFT                       0x10
#define CURSOR_RIGHT                      0x06
#define DISPALY_LEFT                      0x18
#define DISPLAY_RIGHT                     0x1C

#define BLOCK_SIAZE      8


static void H_CLCD_voidlatchByte(u8 copy_u8Byte);

#endif /* CLCD_PRIV_H_ */
