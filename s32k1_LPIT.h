/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <stdint.h>
#include "stm32f144_gpio.h"

/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define LPIT_BASE 0x40037000 /*page 1696*/
#define PCC_LPIT_OFFSET 0xDC


#define LPIT_TVAL0_OFFSET  0x20
#define LPIT_CVAL0_OFFSET  0x24
#define LPIT_TCTRL0_OFFSET 0x28
#define LPIT_MCR_OFFSET    0x8
#define LPIT_MIER_OFFSET    0x10
#define LPIT_MSR_OFFSET    0xC

 
#define ADDRESS_LPIT_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_LPIT_OFFSET )))
#define ADDRESS_LPIT_TVAL0 (*((volatile uint32_t*)(LPIT_BASE + LPIT_TVAL0_OFFSET )))
#define ADDRESS_LPIT_CVAL0 (*((volatile uint32_t*)(LPIT_BASE + LPIT_CVAL0_OFFSET )))
#define ADDRESS_LPIT_TCTRL0 (*((volatile uint32_t*)(LPIT_BASE + LPIT_TCTRL0_OFFSET )))
#define ADDRESS_LPIT_MCR (*((volatile uint32_t*)(LPIT_BASE + LPIT_MCR_OFFSET )))
#define ADDRESS_LPIT_MIER (*((volatile uint32_t*)(LPIT_BASE + LPIT_MIER_OFFSET )))
#define ADDRESS_LPIT_MSR (*((volatile uint32_t*)(LPIT_BASE + LPIT_MSR_OFFSET )))


/******************************************************************************
 *  EXTERN
 *****************************************************************************/
 typedef struct
 {
	volatile unsigned int  VERID; /*Version ID Register (VERID) *Module Version Information:**/
	volatile unsigned int  PARAM; /*FIFO Size*/
	volatile unsigned int  GLOBAL; /*Software Reset*/
	volatile unsigned int  PINCFG;	/*LPUART Pin Configuration Register (PINCFG) This field should only be changed when the transmitter and receiverare both disabled.*/
	volatile unsigned int  BAUD;
	volatile unsigned int  STAT;
	volatile unsigned int  CTRL;
	volatile unsigned int  DATA;
	volatile unsigned int  MATCH;
	volatile unsigned int  MODIR;
	volatile unsigned int  FIFO;
	volatile unsigned int  WATER;
 }LPIT_Type;
/******************************************************************************
 *  VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/

 void SettingClock(void);
 void LPIT_Init(void);
 void Config_channel(void);
 void TimeChannel(void);
