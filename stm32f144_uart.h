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

#define LPUART0_BASE 0x4006A000 /*page 1696*/
#define LPUART1_BASE 0x4006B000
#define LPUART2_BASE 0x4006C000

#define INPUT 0
#define OUTPUT 1

#define LPUART_TRANS_FLAG 23
#define LPUART_RECIEVER_FLAG 21
#define LPUART_ACTIVE_FLAG 24
// Dia chi cua thanh ghi PCC_PORTn
//PCC register descriptions - (page 624)
#define PCC_LPUART0_OFFSET 0x1A8
#define PCC_LPUART1_OFFSET 0x1AC
#define PCC_LPUART2_OFFSET 0x1B0

#define BAUD_OFFSET 0x10
#define STAT_OFFSET 0x14
#define CTRL_OFFSET 0x18
#define DATA_OFFSET 0x1C

 
#define ADDRESS_LPUART1_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_LPUART1_OFFSET )))
#define ADDRESS_LPUART1_BAUD (*((volatile uint32_t*)(LPUART1_BASE + BAUD_OFFSET )))
#define ADDRESS_LPUART1_STAT (*((volatile uint32_t*)(LPUART1_BASE + STAT_OFFSET )))
#define ADDRESS_LPUART1_CTRL (*((volatile uint32_t*)(LPUART1_BASE + CTRL_OFFSET )))
#define ADDRESS_LPUART1_DATA (*((volatile uint32_t*)(LPUART1_BASE + DATA_OFFSET )))
	

#define ADDRESS_LPUART0_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_LPUART0_OFFSET )))
#define ADDRESS_LPUART0_BAUD (*((volatile uint32_t*)(LPUART0_BASE + BAUD_OFFSET )))
#define ADDRESS_LPUART0_STAT (*((volatile uint32_t*)(LPUART0_BASE + STAT_OFFSET )))
#define ADDRESS_LPUART0_CTRL (*((volatile uint32_t*)(LPUART0_BASE + CTRL_OFFSET )))
#define ADDRESS_LPUART0_DATA (*((volatile uint32_t*)(LPUART0_BASE + DATA_OFFSET )))
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
 }LPUART_Type;
/******************************************************************************
 *  VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
void LPUART_TransReceiver_Pin(void);
void LPUART_BaudRate(unsigned int p_Baud);
void LPUART1_init(void);
void LPUART1_transmit_char(unsigned char send);
void LPUART1_transmit_string(const char data_string[]);
char LPUART1_receive_char(void);
void LPUART1_receive_and_echo_char(void); 
void LPUART_PORT_init (void);
void LPUART_init_IRQs (void);
void LPUART_Frame(unsigned int p_DataNumber,unsigned int p_ParityBit);
void LPUART_Enable_RxTx(void);
void LPUART1_RxTx_IRQHandler (void);
void LPUART_EnableTransmit_Interrupt(void);
char LPUART1_receive_char_interrupt(void);
void LPUART1_transmit_char_interrupt(unsigned char send);


void LPUART0_TransReceiver_Pin(void);
void LPUART0_BaudRate(unsigned int p_Baud);
void LPUART0_init(void);
void LPUART0_transmit_char(unsigned char send);
void LPUART0_transmit_string(const char data_string[]);
char LPUART0_receive_char(void);
void LPUART0_receive_and_echo_char(void); 
void LPUART_PORT0_init (void);
void LPUART0_Frame(unsigned int p_DataNumber,unsigned int p_ParityBit);
void LPUART0_Enable_RxTx(void);
void LPUART0_RxTx_IRQHandler (void);
void LPUART0_EnableTransmit_Interrupt(void);
char LPUART0_receive_char_interrupt(void);
void LPUART0_transmit_char_interrupt(unsigned char send);
