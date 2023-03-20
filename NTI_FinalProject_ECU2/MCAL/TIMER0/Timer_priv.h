/*
 * Timer_priv.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ahmed
 */

#ifndef TIMER0_TIMER_PRIV_H_
#define TIMER0_TIMER_PRIV_H_

//For timer mode select
#define CLEAR_TIMER_MODE_REG         0xD7


//for wave generation mode
#define CLEAR_WAVEG_MASK            0xCF
#define NORMAL_PORT_MASK            0x00
#define TOGGLE_PORT_MASK            0x10
#define CLEAR_PORT_MASK             0x20
#define SET_PORT_MASK               0x30
#define NON_INVERTING_FAST_MASK     0x20
#define INVERTING_FAST_MASK         0x30
#define NON_INVERTING_PHASE_MASK    0x20
#define INVERTING_PHASE_MASK        0x30

//pre-scaller select
#define CLEAR_PRESCALLER_MASK       0xF8


//Interrupt flags
#define NORMAL_MODE_INTERRUPT_CLEAR 0xFE
#define NORMAL_MODE_INTERRUPT_SET   0x01
#define CTC_MODE_INTERRUPT_CLEAR    0xFD
#define CTC_MODE_INTERRUPT_SET      0x02
#define NORMAL_MODE_INTERRUPT_RESET 0x00
#define CTC_MODE_INTERRUPT_RESET    0x00

#endif /* TIMER0_TIMER_PRIV_H_ */
