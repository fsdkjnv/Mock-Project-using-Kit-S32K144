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

#define LPSPI0_BASE 0x4002C000u /*page 1696*/
#define LPSPI1_BASE 0x4002D000u
#define LPSPI2_BASE 0x4002E000u

// Dia chi cua thanh ghi PCC_PORTn
//PCC register descriptions - (page 624)
#define PCC_LPSPI0_OFFSET 0xB0u
#define PCC_LPSPI1_OFFSET 0xB4u
#define PCC_LPSPI2_OFFSET 0xB8u

#define VEIR_OFFSET 0x0u
#define PARAM_OFFSET 0x4u
#define CR_OFFSET 0x10u
#define SR_OFFSET 0x14u
#define IER_OFFSET 0x18u
#define DER_OFFSET 0x1Cu
#define CFGR0_OFFSET 0x20u
#define CFGR1_OFFSET 0x24u
#define DMR0_OFFSET 0x30u
#define DMR1_OFFSET 0x34u
#define CCR_OFFSET 0x40u
#define FCR_OFFSET 0x58u
#define FSR_OFFSET 0x5Cu
#define TCR_OFFSET 0x60u
#define TDR_OFFSET 0x64u
#define RSR_OFFSET 0x70u
#define RDR_OFFSET 0x74u



		



#define ADDRESS_LPSPI0_PCC   (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_LPSPI0_OFFSET )))
#define ADDRESS_LPSPI0_VEIR  (*((volatile uint32_t*)(LPSPI0_BASE + VEIR_OFFSET )))
#define ADDRESS_LPSPI0_PARAM (*((volatile uint32_t*)(LPSPI0_BASE + PARAM_OFFSET )))
#define ADDRESS_LPSPI0_CR    (*((volatile uint32_t*)(LPSPI0_BASE + CR_OFFSET )))
#define ADDRESS_LPSPI0_SR    (*((volatile uint32_t*)(LPSPI0_BASE + SR_OFFSET )))
#define ADDRESS_LPSPI0_IER   (*((volatile uint32_t*)(LPSPI0_BASE + IER_OFFSET )))
#define ADDRESS_LPSPI0_DER   (*((volatile uint32_t*)(LPSPI0_BASE + DER_OFFSET )))
#define ADDRESS_LPSPI0_CFGR0 (*((volatile uint32_t*)(LPSPI0_BASE + CFGR0_OFFSET )))
#define ADDRESS_LPSPI0_CFGR1 (*((volatile uint32_t*)(LPSPI0_BASE + CFGR1_OFFSET )))
#define ADDRESS_LPSPI0_DMR0 (*((volatile uint32_t*)(LPSPI0_BASE + DMR0_OFFSET )))
#define ADDRESS_LPSPI0_DMR1 (*((volatile uint32_t*)(LPSPI0_BASE + DMR1_OFFSET )))
#define ADDRESS_LPSPI0_CCR  (*((volatile uint32_t*)(LPSPI0_BASE + CCR_OFFSET )))
#define ADDRESS_LPSPI0_FCR  (*((volatile uint32_t*)(LPSPI0_BASE + FCR_OFFSET )))
#define ADDRESS_LPSPI0_FSR  (*((volatile uint32_t*)(LPSPI0_BASE + FSR_OFFSET )))
//#define ADDRESS_LPSPI0_TCR  (*((volatile uint32_t*)(LPSPI0_BASE + TCR_OFFSET )))
	#define ADDRESS_LPSPI0_TCR  (*((volatile uint32_t*)(0x4002C060u  )))

#define ADDRESS_LPSPI0_TDR  (*((volatile uint32_t*)(LPSPI0_BASE + TDR_OFFSET )))
#define ADDRESS_LPSPI0_RSR  (*((volatile uint32_t*)(LPSPI0_BASE + SRS_OFFSET )))
#define ADDRESS_LPSPI0_RDR  (*((volatile uint32_t*)(LPSPI0_BASE + RDR_OFFSET )))
	

#define ADDRESS_LPSPI1_PCC   (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_LPSPI1_OFFSET )))
#define ADDRESS_LPSPI1_VEIR  (*((volatile uint32_t*)(LPSPI1_BASE + VEIR_OFFSET )))
#define ADDRESS_LPSPI1_PARAM (*((volatile uint32_t*)(LPSPI1_BASE + PARAM_OFFSET )))
#define ADDRESS_LPSPI1_CR    (*((volatile uint32_t*)(LPSPI1_BASE + CR_OFFSET )))
#define ADDRESS_LPSPI1_SR    (*((volatile uint32_t*)(LPSPI1_BASE + SR_OFFSET )))
#define ADDRESS_LPSPI1_IER   (*((volatile uint32_t*)(LPSPI1_BASE + IER_OFFSET )))
#define ADDRESS_LPSPI1_DER   (*((volatile uint32_t*)(LPSPI1_BASE + DER_OFFSET )))
#define ADDRESS_LPSPI1_CFGR0 (*((volatile uint32_t*)(LPSPI1_BASE + CFGR0_OFFSET )))
#define ADDRESS_LPSPI1_CFGR1 (*((volatile uint32_t*)(LPSPI1_BASE + CFGR1_OFFSET )))
#define ADDRESS_LPSPI1_DMR0 (*((volatile uint32_t*)(LPSPI1_BASE + DMR0_OFFSET )))
#define ADDRESS_LPSPI1_DMR1 (*((volatile uint32_t*)(LPSPI1_BASE + DMR1_OFFSET )))
#define ADDRESS_LPSPI1_CCR  (*((volatile uint32_t*)(LPSPI1_BASE + CCR_OFFSET )))
#define ADDRESS_LPSPI1_FCR  (*((volatile uint32_t*)(LPSPI1_BASE + FCR_OFFSET )))
#define ADDRESS_LPSPI1_FSR  (*((volatile uint32_t*)(LPSPI1_BASE + FSR_OFFSET )))
#define ADDRESS_LPSPI1_TCR  (*((volatile uint32_t*)(LPSPI1_BASE + TCR_OFFSET )))
#define ADDRESS_LPSPI1_TDR  (*((volatile uint32_t*)(LPSPI1_BASE + TDR_OFFSET )))
#define ADDRESS_LPSPI1_RSR  (*((volatile uint32_t*)(LPSPI1_BASE + SRS_OFFSET )))
#define ADDRESS_LPSPI1_RDR  (*((volatile uint32_t*)(LPSPI1_BASE + RDR_OFFSET )))
	

#define ADDRESS_LPSPI_SCG (*((volatile uint32_t*)(0x40064000u+0x304u)))

/******************************************************************************
 *  EXTERN
 *****************************************************************************/

/******************************************************************************
 *  VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
void LPSPI0_int_master(void);
void LPSPI0_transmit(uint16_t send);
char LPSPI0_receive (void);
void LPSPI1_int_slave(void);
void LPSPI1_transmit(uint8_t send);
char LPSPI1_receive (void);
void PORT_init_master (void);
void PORT_init_slave (void);
void LPSPI0_transmit_string(const char data_string[]);
char LPSPI1_receive_interrupt (void);
 /******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/
