#ifndef MCU_HW_H_
#define MCU_HW_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"

/**************************************/


#define MCU_FREQUENCY 16000000UL



//STATUS REG

#define STATUS_REG (*((volatile u8*)0x5F))
#define STATUS_I	7

/* Interrupt vectors */
/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define USART_RXC_vect			__vector_13
/* USART Data Register Empty */
#define USART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define USART_TXC_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20

#  define ISR_NOBLOCK    __attribute__((interrupt))
#  define ISR_NAKED      __attribute__((naked))


#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)







//-------------------DIO-------------------
#define PORTA_REG  (*((volatile u8*)0x3B))
#define DDRA_REG   (*((volatile u8*)0x3A))
#define PINA_REG   (*((volatile u8*)0x39))

#define PORTB_REG  (*((volatile u8*)0x38))
#define DDRB_REG   (*((volatile u8*)0x37))
#define PINB_REG   (*((volatile u8*)0x36))

#define PORTC_REG  (*((volatile u8*)0x35))
#define DDRC_REG   (*((volatile u8*)0x34))
#define PINC_REG   (*((volatile u8*)0x33))

#define PORTD_REG  (*((volatile u8*)0x32))
#define DDRD_REG   (*((volatile u8*)0x31))
#define PIND_REG   (*((volatile u8*)0x30))

//------------------ END of DIO------------




//-----------External Interrupts Registers--------------------------------
#define MCUCR_REG 	 (*((volatile u8*)0x55))  //MCU Control Register –MCUCR
#define MCUCR_ISC00_BIT    0
#define MCUCR_ISC01_BIT    1
#define MCUCR_ISC10_BIT    2
#define MCUCR_ISC11_BIT    3

#define MCUCSR_REG 	 (*((volatile u8*)0x54))  //MCU Control and Status Register – MCUCSR
#define MCUCSR_ISC2_BIT	   6

#define GICR_REG  	 (*((volatile u8*)0x5B))  //General Interrupt Control Register – GICR
#define GICR_INT2_BIT      5
#define GICR_INT0_BIT      6
#define GICR_INT1_BIT      7

#define GIFR_REG	 (*((volatile u8*)0x5A))  //General Interrupt Flag Register – GIFR
#define GIFR_INTF1_BIT	   7
#define GIFR_INTF2_BIT	   5
#define GIFR_INTF0_BIT	   6


//-----------External Interrupts Registers--------------------------------

//---------------------TIMERS Registers-----------------------------

//registers
/* Timer 0 */
#define TCNT0_REG   (*(volatile u8*)0x52)  //Timer counter register

#define TCCR0_REG   (*(volatile u8*)0x53) //Timer control register
#define TCCR0_FOC0_BIT    7		//force output compare
#define TCCR0_WGM00_BIT   6		//mode bit
#define TCCR0_COM01_BIT   5		//,,
#define TCCR0_COM00_BIT   4		//compare match mode: these bits compare the OC0 pin behavior
#define TCCR0_WGM01_BIT   3		//mode bit
#define TCCR0_CS02_BIT    2		//,,
#define TCCR0_CS01_BIT    1		//,,
#define TCCR0_CS00_BIT    0		//CLK select


#define TIFR_REG    (*(volatile u8*)0x58)
#define TIFR_TOV0_BIT	0
#define TIFR_OCF0_BIT	1
#define TIFR_TOV1_BIT	2
#define TIFR_OCF1B_BIT	3
#define TIFR_OCF1A_BIT	4
#define TIFR_ICF1_BIT	5
#define TIFR_TOV2_BIT	6
#define TIFR_OCF2_BIT	7

#define TIMSK_REG   (*(volatile u8*)0x59)   //Counter interrupt register
#define TIMSK_TOIE0_BIT  0
#define TIMSK_OCIE0_BIT  1
#define TIMSK_TOIE1_BIT  2
#define TIMSK_OCIE1B_BIT 3
#define TIMSK_OCIE1A_BIT 4
#define TIMSK_TICIE1_BIT 5
#define TIMSK_TOIE2_BIT  6
#define TIMSK_OCIE2_BIT  7

#define OCR0_REG    (*(volatile u8*)0x5C)  //Continuously compared with the timer counter, a match can generate an - interrupt     - Wave form on the OC0 pin

#define SFIOR_REG	(*(volatile u8*)0x50)
#define SFIOR_PSR2_BIT	1
/******************************************************************************/


/*TIMER 1*/

#define TCCR1A_REG        (*(volatile u8*)0x4F)
#define TCCR1A_WGM10_BIT	0
#define TCCR1A_WGM11_BIT	1
#define	TCCR1A_FOC1B_BIT	2
#define TCCR1A_FOC1A_BIT	3
#define	TCCR1A_COM1B0_BIT	4
#define	TCCR1A_COM1B1_BIT	5
#define	TCCR1A_COM1A0_BIT	6
#define TCCR1A_COM1A1_BIT	7

#define TCCR1B_REG       (*(volatile u8*)0x4E)
#define	TCCR1B_ICNC1_BIT	7
#define	TCCR1B_ICES1_BIT	6
#define	TCCR1B_RES			5
#define	TCCR1B_WGM13_BIT	4
#define TCCR1B_WGM12_BIT	3
#define TCCR1B_CS12_BIT		2
#define	TCCR1B_CS11_BIT		1
#define TCCR1B_CS10_BIT		0


#define TCNT1_REG       (*(volatile u16*)0x4C)
	#define TCNT1L_REG    	(*(volatile u8*)0x4C)
	#define TCNT1H_REG    	(*(volatile u8*)0x4D)

#define OCR1A_REG     	(*(volatile u16*)0x4A)
	#define OCR1AL_REG    	(*(volatile u8*)0x4A)
	#define OCR1AH_REG      (*(volatile u8*)0x4B)

#define OCR1B_REG     	(*(volatile u16*)0x48)
	#define OCR1BL_REG    	(*(volatile u8*)0x48)
	#define OCR1BH_REG       (*(volatile u8*)0x49)

#define ICR1_REG         (*(volatile u16*)0x46)
	#define ICR1L_REG    	 (*(volatile u8*)0x46)
	#define ICR1H_REG     	(*(volatile u8*)0x47)



/******************************************************************************/
/* Timer 2 */

/* TCCR2 */
#define TCCR2_REG    (*(volatile u8*)0x45)
#define TCCR2_FOC2_BIT    	7
#define TCCR2_WGM20_BIT     6
#define TCCR2_COM21_BIT	    5
#define TCCR2_COM20_BIT   	4
#define TCCR2_WGM21_BIT     3
#define TCCR2_CS22_BIT    	2
#define TCCR2_CS21_BIT    	1
#define TCCR2_CS20_BIT    	0

#define TCNT2_REG    (*(volatile u8*)0x44)

#define OCR2_REG     (*(volatile u8*)0x43)

#define ASSR_REG	 (*(volatile u8*)0x42)
/* bits 7-4 reserved */
#define ASSR_TCR2UB_BIT		0
#define	ASSR_OCR2UB_BIT		1
#define	ASSR_TCN2UB_BIT		2
#define	ASSR_AS2_BIT		3



/* WDTCR */
#define WDTCR_REG    (*(volatile u8*)0x41)
/* bits 7-5 reserved */
#define WDTOE_BIT   4
#define WDE_BIT	    3
#define WDP2_BIT    2
#define WDP1_BIT    1
#define WDP0_BIT    0
/************************************************************/
//---------------------ADC Registers-----------------------------
#define ADMUX_REG (*(volatile u8*)0x27)
	#define ADMUX_REFS1 7
	#define ADMUX_REFS0 6
	#define ADMUX_ADLAR 5
	#define ADMUX_MUX4	4
	#define ADMUX_MUX3	3
	#define ADMUX_MUX2	2
	#define ADMUX_MUX1	1
	#define ADMUX_MUX0	0


#define ADCSRA_REG (*(volatile u8*)0x26)
	#define ADCSRA_ADPS0 0
	#define ADCSRA_ADPS1 1
	#define ADCSRA_ADPS2 2
	#define ADCSRA_ADIE  3
	#define ADCSRA_ADIF  4
	#define ADCSRA_ADATE 5
	#define ADCSRA_ADSC  6
	#define ADCSRA_ADEN  7

#define ADC_REG (*(volatile u16*)0x24)
	#define ADCL_REG (*(volatile u8*)0x24)
	#define ADCH_REG (*(volatile u8*)0x25)

#define SFIOR_REG   (*(volatile u8*)0x50)
	#define SFIOR_PSR10			0
	#define SFIOR_PSR2			1
	#define SFIOR_PUD			2
	#define SFIOR_ACME			3
	/* Bit-4 is reserved */
	#define SFIOR_ADTS0			5
	#define SFIOR_ADTS1			6
	#define SFIOR_ADST2			7



/************************************************************/
//---------------------SPI Registers-----------------------------
#define SPCR_REG  (*((volatile u8*)0x2D))
#define SPCR_SPR0		0
#define SPCR_SPR1		1
#define	SPCR_CPHA		2
#define SPCR_CPOL		3
#define SPCR_MSTR		4
#define SPCR_DORD		5
#define	SPCR_SPE		6
#define	SPCR_SPIE		7

#define SPSR_REG  (*((volatile u8*)0x2E))
#define	SPSR_SPI2X		0
/*1:5 reserved*/
#define	SPSR_WCOL		6
#define	SPSR_SPIF		7


#define SPDR_REG (*((volatile u8*)0x2F))



/******************************************************************************/
//----------------------------UART Registers-------------------------------------
/******************************************************************************/
/* USART I/O Data Register */
#define UDR_REG       (*(volatile u8*)0x2C)

/* USART Control and Status Register A */
#define UCSRA_REG    (*(volatile u8*)0x2B)
	#define UCSRA_MPCM		0
	#define UCSRA_U2X		1
	#define UCSRA_PE		2
	#define UCSRA_DOR		3
	#define UCSRA_FE		4
	#define UCSRA_UDRE		5
	#define UCSRA_TXC		6
	#define UCSRA_RXC		7

/* USART Control and Status Register B */
#define UCSRB_REG   (*(volatile u8*)0x2A)
	#define UCSRB_TXB8		0
	#define UCSRB_RXB8		1
	#define UCSRB_UCSZ2		2
	#define UCSRB_TXEN		3
	#define UCSRB_RXEN		4
	#define UCSRB_UDRIE		5
	#define UCSRB_TXCIE		6
	#define UCSRB_RXCIE		7

/* USART Control and Status Register C */
#define UCSRC_REG     (*(volatile u8*)0x40)
	#define UCSRC_UCPOL		0
	#define UCSRC_UCSZ0		1
	#define UCSRC_UCSZ1		2
	#define UCSRC_USBS		3
	#define	UCSRC_UPM0		4
	#define	UCSRC_UPM1		5
	#define	UCSRC_UMSEL		6
	#define UCSRC_URSEL		7

/* USART Baud Rate Register High */
#define UBRRH_REG    (*(volatile u8*)0x40)
#define UBRRH_USEL		7

/* USART Baud Rate Register Low */
#define UBRRL_REG    (*(volatile u8*)0x29)



/******************************************************************************/
//----------------------------IIC Registers-------------------------------------
/******************************************************************************/
#define TWBR_REG		(*(volatile u8*)0x20)

#define TWSR_REG		(*(volatile u8*)0x21)
	 #define TWSR_TWPS0  0
	 #define TWSR_TWPS1  1

#define TWAR_REG		(*(volatile u8*)0x22)
	 #define TWAR_TWGCE 0

#define TWDR_REG		(*(volatile u8*)0x23)

#define TWCR_REG		(*(volatile u8*)0x56)
	#define TWCR_TWIE  0
	#define TWCR_TWEN  2
	#define TWCR_TWWC  3
	#define TWCR_TWSTO 4
	#define TWCR_TWSTA 5
	#define TWCR_TWEA  6
	#define TWCR_TWINT 7


#endif /* MCU_HW_H_ */
