#include "stm32f144_uart.h"
/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_gpio.h"
 #include "math.h"
/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
 #define BASE_PCC 0x40065000
 #define BASE_PCR 0x40049000
 #define BASE_PDDR 0x400FF000+0x14
 #define BASE_PDOR 0x400FF000
 #define BASE_PDIR 0x400FF000+0x10
 #define TIMER_CTRL 0xE000E010
 #define TIMER_VAL 0xE000E018
 #define TIMER_LOAD 0xE000E014
 
/******************************************************************************
 *  EXTERN
 *****************************************************************************/

/******************************************************************************
 *  VARIABLES
 *****************************************************************************/

/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/

/******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/



/*******************************************************************************
	Function name   :   LPUART_BaudRate	
	Description     :  	- Enable and setting UART
											- Set Baud rate
											- setting Oversamping	Ratio
											- Baud rate Modulo Divisor

	******************************************************************************
	*/
void LPUART_BaudRate(unsigned int p_Baud)
{
	
	Func_SetClearMultiBit((volatile unsigned int*)(0x40065000u+0x1ACu),24U,SETBIT,0x03);/*setting clock for uart 1*/
	Func_SetClearMultiBit((volatile unsigned int*)(0x40064000u+0x304u),8U,SETBIT,0x01);/*setting Div1 for clock source */
	Func_SetClearBit((volatile unsigned int*)(0x40065000u+0x1ACu),30U,SETBIT); /*enable clock for uart 1*/
	Func_SetClearMultiBit(&(((LPUART_Type*)LPUART1_BASE)->BAUD),24u,SETBIT,0x0f); /*set oversamping ratio =16 */
	Func_SetClearMultiBit(&(((LPUART_Type*)LPUART1_BASE)->BAUD),0,CLEARBIT,0x1FFF); /*clear bit 0-12*/
	Func_SetClearMultiBit(&(((LPUART_Type*)LPUART1_BASE)->BAUD),0,SETBIT,48000000/(p_Baud*16)); /*set baud rate modulo divisor*/
//	(int)48000000/(p_Baud*16)
}
/*	
	******************************************************************************
	Function name   :   LPUART_Frame	
	Description     :   - Setting stop bit
											- Setting data characters number
											- Setting parity bit

	******************************************************************************
	*/
void LPUART_Frame(unsigned char p_DataNumber,unsigned char p_ParityBit)
{
	char f_tmp=0;
	if(p_DataNumber==8)
	{
		f_tmp=0;
	}
	else if(p_DataNumber==9)
	{
		f_tmp=1;
	}
	else
	{
		/*do nothing*/
	}
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->BAUD),13u,CLEARBIT); /*set 1 bit stop bit*/
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->CTRL),4u,f_tmp); /*set data nummbers*/
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->CTRL),1u,p_ParityBit);/*set parity*/
}
/*
	******************************************************************************
	Function name   :   LPUART_Enable_TransReceiver
	Description     :   - set enable transmitter & receiver.
									

	******************************************************************************
	*/
void LPUART_Enable_TransReceiver(unsigned char p_Transmitter, unsigned char p_Receiver,unsigned char p_Transmitter_ISF,unsigned char p_Receiver_ISF)
{
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->CTRL),22u,p_Transmitter_ISF); /*set transmitter interrupt*/
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->CTRL),21u,p_Receiver_ISF); /*set Receiver interrupt*/
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->CTRL),18u,p_Receiver); /*set transmitter bit*/
	Func_SetClearBit(&(((LPUART_Type*)LPUART1_BASE)->CTRL),19u,p_Transmitter);/*set Receiver bit*/
}

/*
	******************************************************************************
	Function name   :   LPUART_Enable_TransReceiver
	Description     :   - set enable transmitter & receiver.
									

	******************************************************************************
	*/
int LPUART_Satus(unsigned char p_Pin)
{
	int f_tmp = ((((LPUART_Type*)LPUART1_BASE)->STAT)>>p_Pin)&0x01; /*read data at pin 23 of STAT register*/
		if((f_tmp==0)||(f_tmp==1))
	{
	 return f_tmp;
	}
	else
	{
		return 0x3e; /*error code*/
	}
}

/*
	******************************************************************************
	Function name   :   LPUART_Data
	Description     :   - set data.
									

	******************************************************************************
	*/
void LPUART_Data(unsigned char p_Data)
{
	Func_SetClearMultiBit(&(((LPUART_Type*)LPUART1_BASE)->DATA),0u,SETBIT,p_Data); /*write data*/
}

/*
	******************************************************************************
	Function name   :   LPUART_Data
	Description     :   - set data.
									

	******************************************************************************
	*/
unsigned char LPUART_ReadData(void)
{
	unsigned char f_tmp2=0;

		f_tmp2=(unsigned char)(((LPUART_Type*)LPUART1_BASE)->DATA);
	
	return f_tmp2;
}


/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/



