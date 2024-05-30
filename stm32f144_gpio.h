/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include <stdint.h>

/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
#define SETBIT 1
#define CLEARBIT 0

#define LOW 0
#define HIGH 1 

#define PCC_BASE_ADDRESS 0x40065000u 

//PCC register descriptions - (page 624)
#define PCC_PORTA_OFFSET 0x124
#define PCC_PORTB_OFFSET 0x128
#define PCC_PORTC_OFFSET 0x12C
#define PCC_PORTD_OFFSET 0x130
#define PCC_PORTE_OFFSET 0x134

//Base address of PORT - Peripheral Memory Map (File Excel)
#define PORTA_BASE_ADDRESS 0x40049000u
#define PORTB_BASE_ADDRESS 0x4004A000u
#define PORTC_BASE_ADDRESS 0x4004B000u
#define PORTD_BASE_ADDRESS 0x4004C000u
#define PORTE_BASE_ADDRESS 0x4004D000u

//GPIO Base address - (page 229)
#define GPIOA_BASE_ADDRESS 0x400FF000u
#define GPIOB_BASE_ADDRESS 0x400FF040u
#define GPIOC_BASE_ADDRESS 0x400FF080u
#define GPIOD_BASE_ADDRESS 0x400FF0C0u
#define GPIOE_BASE_ADDRESS 0x400FF100u

// GPIO Memory Map - page 229
#define PDOR_OFFSET 0x00 		//Port Data Output Register (PDOR)
#define PSOR_OFFSET 0x04		//Port Set Output Register (PSOR)
#define PCOR_OFFSET 0x08		//Port Clear Output Register (PCOR)
#define PTOR_OFFSET 0x0C		//Port Toggle Output Register (PTOR)
#define PDIR_OFFSET 0x10		//Port Data Input Register (PDIR)
#define PDDR_OFFSET 0x14		//Port Data Direction Register (PDDR)
#define PIDR_OFFSET 0x18		//Port Input Disable Register (PIDR)


// Pin Control Register - page 211
#define PCR0_OFFSET 0X00
#define PCR1_OFFSET 0X04
#define PCR2_OFFSET 0X08
#define PCR3_OFFSET 0X0C
#define PCR4_OFFSET 0X10
#define PCR5_OFFSET 0X14
#define PCR6_OFFSET 0X18
#define PCR7_OFFSET 0X1C
#define PCR8_OFFSET 0X20
#define PCR9_OFFSET 0X24
#define PCR10_OFFSET 0X28
#define PCR11_OFFSET 0X2C
#define PCR12_OFFSET 0X30
#define PCR13_OFFSET 0X34
#define PCR14_OFFSET 0X38
#define PCR15_OFFSET 0X3C
#define PCR16_OFFSET 0X40
#define PCR17_OFFSET 0X44
#define PCR18_OFFSET 0X48
#define PCR19_OFFSET 0X4C
#define PCR20_OFFSET 0X50
#define PCR21_OFFSET 0X54
#define PCR22_OFFSET 0X58
#define PCR23_OFFSET 0X5C
#define PCR24_OFFSET 0X60
#define PCR25_OFFSET 0X64
#define PCR26_OFFSET 0X68
#define PCR27_OFFSET 0X6C
#define PCR28_OFFSET 0X70
#define PCR29_OFFSET 0X74
#define PCR30_OFFSET 0X78
#define PCR31_OFFSET 0X7C


// Dia chi cua thanh ghi PCC_PORTn
#define ADDRESS_PORTA_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_PORTA_OFFSET)))
#define ADDRESS_PORTB_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_PORTB_OFFSET)))
#define ADDRESS_PORTC_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_PORTC_OFFSET)))
#define ADDRESS_PORTD_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_PORTD_OFFSET)))
#define ADDRESS_PORTE_PCC (*((volatile uint32_t*)(PCC_BASE_ADDRESS + PCC_PORTE_OFFSET)))
// Dia chi cua thanh ghi PCC_PORTn Uart;




// Dia chi cua Led RGB thanh ghi PCR (Port Control Register)
#define ADDRESS_PORTD_PCR15 (*((volatile uint32_t*)(PORTD_BASE_ADDRESS + PCR15_OFFSET)))		// PortD -  RGB_Red Led
#define ADDRESS_PORTD_PCR0  (*((volatile uint32_t*)(PORTD_BASE_ADDRESS + PCR0_OFFSET)))		// PortD -  RGB_Green Led
#define ADDRESS_PORTD_PCR16 (*((volatile uint32_t*)(PORTD_BASE_ADDRESS + PCR16_OFFSET)))		// PortD -  RGB_Blue Led 

//Dia chi cua Button thanh ghi PCR
#define ADDRESS_PORTC_PCR12 (*((volatile uint32_t*)(PORTC_BASE_ADDRESS + PCR12_OFFSET)))		
#define ADDRESS_PORTC_PCR13 (*((volatile uint32_t*)(PORTC_BASE_ADDRESS + PCR13_OFFSET)))	
#define ADDRESS_PORTC_PCR6 (*((volatile uint32_t*)(PORTC_BASE_ADDRESS + PCR6_OFFSET)))	
#define ADDRESS_PORTC_PCR7 (*((volatile uint32_t*)(PORTC_BASE_ADDRESS + PCR7_OFFSET)))
	
#define ADDRESS_PORTB_PCR0 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR0_OFFSET)))		
#define ADDRESS_PORTB_PCR2 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR2_OFFSET)))	
	#define ADDRESS_PORTB_PCR1 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR1_OFFSET)))		

#define ADDRESS_PORTB_PCR3 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR3_OFFSET)))	
#define ADDRESS_PORTB_PCR4 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR4_OFFSET)))	
#define ADDRESS_PORTB_PCR5 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR5_OFFSET)))	
#define ADDRESS_PORTB_PCR6 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR6_OFFSET)))	
#define ADDRESS_PORTB_PCR7 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR7_OFFSET)))	
	
#define ADDRESS_PORTB_PCR12 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR12_OFFSET)))		
#define ADDRESS_PORTB_PCR13 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR13_OFFSET)))	
#define ADDRESS_PORTB_PCR14 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR14_OFFSET)))	
#define ADDRESS_PORTB_PCR15 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR15_OFFSET)))	
#define ADDRESS_PORTB_PCR16 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR16_OFFSET)))	
#define ADDRESS_PORTB_PCR17 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR17_OFFSET)))	
	
//Dia chi cua Button thanh ghi PCR
#define ADDRESS_PORTA_PCR3 (*((volatile uint32_t*)(PORTA_BASE_ADDRESS + PCR3_OFFSET)))		
#define ADDRESS_PORTB_PCR8 (*((volatile uint32_t*)(PORTB_BASE_ADDRESS + PCR8_OFFSET)))	
	
#define ADDRESS_PORTE_PCR1 (*((volatile uint32_t*)(PORTE_BASE_ADDRESS + PCR1_OFFSET)))		
#define ADDRESS_PORTE_PCR2 (*((volatile uint32_t*)(PORTE_BASE_ADDRESS + PCR2_OFFSET)))	

#define ADDRESS_PORTE_PCR0 (*((volatile uint32_t*)(PORTE_BASE_ADDRESS + PCR0_OFFSET)))		
#define ADDRESS_PORTE_PCR4 (*((volatile uint32_t*)(PORTE_BASE_ADDRESS + PCR4_OFFSET)))	
#define ADDRESS_PORTE_PCR6 (*((volatile uint32_t*)(PORTE_BASE_ADDRESS + PCR6_OFFSET)))		
	
// Dia chi cua thanh ghi GPIOx_PDDR (Data Direction Register) cua GPIOD
#define ADDRESS_GPIOA_PDDR (*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + PDDR_OFFSET)))
#define ADDRESS_GPIOB_PDDR (*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + PDDR_OFFSET)))
#define ADDRESS_GPIOC_PDDR (*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + PDDR_OFFSET)))
#define ADDRESS_GPIOD_PDDR (*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + PDDR_OFFSET)))
#define ADDRESS_GPIOE_PDDR (*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + PDDR_OFFSET)))

/* 
PDDR - Port Data Direction
0b - Pin is configured as general-purpose input, for the GPIO function. 
1b - Pin is configured as general-purpose output, for the GPIO function. 
*/

#define ADDRESS_GPIOC_PDIR      (*((volatile uint32_t*)(0x400FF080u + 0x10)))

// Dia chi cua thanh ghi GPIOD_PDOR (Data Output Register) cua GPIOD
#define ADDRESS_GPIOA_PDOR (*((volatile uint32_t*)(GPIOA_BASE_ADDRESS + PDOR_OFFSET )))
#define ADDRESS_GPIOB_PDOR (*((volatile uint32_t*)(GPIOB_BASE_ADDRESS + PDOR_OFFSET )))
#define ADDRESS_GPIOC_PDOR (*((volatile uint32_t*)(GPIOC_BASE_ADDRESS + PDOR_OFFSET )))
#define ADDRESS_GPIOD_PDOR (*((volatile uint32_t*)(GPIOD_BASE_ADDRESS + PDOR_OFFSET )))
#define ADDRESS_GPIOE_PDOR (*((volatile uint32_t*)(GPIOE_BASE_ADDRESS + PDOR_OFFSET )))
	
#define NVIC_ISER_1     (*((volatile uint32_t*)(0xE000E100u + 4*1)))	
#define NVIC_ISER_0     (*((volatile uint32_t*)(0xE000E100u)))	

// NVIC
#define NVIC_ISER0    ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1    ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2    ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3    ((volatile uint32_t*)0xE000E10C)
#define NVIC_ISER4    ((volatile uint32_t*)0xE000E110)
#define NVIC_ISER5    ((volatile uint32_t*)0xE000E114)
#define NVIC_ISER6    ((volatile uint32_t*)0xE000E118)
#define NVIC_ISER7    ((volatile uint32_t*)0xE000E11C)

/*
NVIC Interrupt ID :
PORTA Interrupt			59
PORTB Interrupt			60
PORTC Interrupt			61
PORTD Interrupt			62
PORTE Interrupt			63
*/

/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
void configLed(uint32_t pinNumber);
void setOutputPin(uint32_t pinNumber, uint8_t state);
void configButton(uint32_t pinNumber);
void PORTC_IRQHandler(void);
void PORTA_IRQHandler(void);
void PORTB_IRQHandler(void);
void GREEN_RED_BLUDE(void);
void configButton_portA(uint32_t pinNumber );
void configButton_portB(uint32_t pinNumber );
/******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/
/****************************************************************/


/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
