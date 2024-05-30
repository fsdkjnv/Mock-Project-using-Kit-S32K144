///******************************************************************************
// *  INCLUDES
// *****************************************************************************/
//#include "stm32f144_uart.h"
//#include <stdint.h>
//#define ADDRESS_LPUART1_PCC_PCS (*((volatile uint32_t*)(0x40064000u+0x304u)))
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//void LPUART_PORT_init (void) {
//	
//  ADDRESS_PORTC_PCC  |= (1 << 30);	/* Enable clock for PORTC */
//  ADDRESS_PORTC_PCR6 |= (1 << 9); /* Port C6: MUX = ALT2,UART1 TX */
//  ADDRESS_PORTC_PCR7 |= (1 << 9); /* Port C7: MUX = ALT2,UART1 RX */
//  NVIC_ISER_1 |= (1 << (33 % 32)); /* NVIC UART */
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//void LPUART_TransReceiver_Pin(void) {
//	
//	  ADDRESS_LPUART1_PCC &= ~(1U << 30); /* Ensure clk disabled for config */
//  	ADDRESS_LPUART1_PCC |=  (3<<24); // /* Clock Src= 1 (SOSCDIV2_CLK) */
//  //  ADDRESS_LPUART1_PCC_PCS |= (1<<8); // /* Clock Src= 1 (SOSCDIV2_CLK) */
//    ADDRESS_LPUART1_PCC |= (1U << 30);   /* Enable clock for LPUART1 regs */
//	

//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//void LPUART_BaudRate(unsigned int p_Baud)
//{
//	  ADDRESS_LPUART1_BAUD |= (0x0f <<24); /*set oversamping ratio =16 */
//		ADDRESS_LPUART1_BAUD &= ~ (0x1FFF <<0);  /*clear bit 0-12*/
//		ADDRESS_LPUART1_BAUD |= ((48000000/(p_Baud*16)) <<0); /*set oversamping ratio =16 */

//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//void LPUART_Frame(unsigned int p_DataNumber,unsigned int p_ParityBit)
//{
//	unsigned int f_tmp=0;
//	if(p_DataNumber==8)
//	{
//		f_tmp=0;// 8bit
//	}
//	else if(p_DataNumber==9)
//	{
//		f_tmp=1;// 9bit
//	}
//	else
//	{
//		/*do nothing*/
//	}
//	ADDRESS_LPUART1_BAUD &= ~(1U <<13); /*set 1 bit stop bit*/
//																											
//	ADDRESS_LPUART1_CTRL |= (f_tmp <<4);		/*9-Bit or 8-Bit Mode Select*/
//	ADDRESS_LPUART1_CTRL |= (p_ParityBit <<1); // set ParityBit

//   
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//void LPUART_Enable_RxTx(void){
//  ADDRESS_LPUART1_CTRL |= (1 <<21);// Receiver Interrupt Enable
////ADDRESS_LPUART1_CTRL |= (1 <<23); // Transmit Interrupt Enable
//	ADDRESS_LPUART1_CTRL |= (1 <<18);// Rx Enable
//	ADDRESS_LPUART1_CTRL |= (1 <<19); // Tx Enable
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//void LPUART1_init(void)
//{	
//	  LPUART_TransReceiver_Pin();
//	  LPUART_BaudRate(9600);
//	  LPUART_Frame(8,0);
//	  LPUART_Enable_RxTx();
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//// poling
//void LPUART1_transmit_char(unsigned char send) { /* Function to Transmit single Char */

//  while( (ADDRESS_LPUART1_STAT & (1 << 23) ) == 0);/* Wait for received buffer to be empty */
//    ADDRESS_LPUART1_DATA = (send & 0xFF );
//    
//}

// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//// poling
//void LPUART1_transmit_string(const char data_string[]) {
//    /* Transmit chars one at a time until null terminator is encountered */
//    for (uint32_t i = 0; data_string[i] != '\0'; ++i) {
//        LPUART1_transmit_char(data_string[i]);
//    }
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//// poling
//char LPUART1_receive_char(void){
//    char receive;

//	  while( (ADDRESS_LPUART1_STAT & (1 << 21) )== 0);/* Wait for received buffer to be empty */
//    receive = (unsigned char)(ADDRESS_LPUART1_DATA);
//    return receive;
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//// interrupt
//void LPUART1_transmit_char_interrupt(unsigned char send) { /* Function to Transmit single Char */

//  if ( (ADDRESS_LPUART1_STAT & (1 << 23) ) != 0){
//		
//	    ADDRESS_LPUART1_DATA = (send & 0xFF );
//	
//	}/* Wait for received buffer to be empty */
//    
//}
// /*
//  *****************************************************************************
//	Function name   : LPUART_TransReceiver_Pin
//	Description     : + Enable clock for PORT: PCC[CGC]
//                    + Set alternate function pin: PORT_PCR[MUX]
//										+ TXD : I/O
//										+ RXD : I

//	*****************************************************************************
//*/
//char LPUART1_receive_char_interrupt(void) { /* Function to Transmit single Char */

//    char receive;

//	  if ( (ADDRESS_LPUART1_STAT & (1 << 21) )== 0){
//				
//		}
//		else{
//		    receive = (unsigned char)(ADDRESS_LPUART1_DATA);

//		}/* Wait for received buffer to be empty */
//    return receive;
//	
//    
//}


/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_uart.h"
#include <stdint.h>
#define ADDRESS_LPUART1_PCC_PCS (*((volatile uint32_t*)(0x40064000u+0x304u)))
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
void LPUART_PORT0_init (void) {
	
  ADDRESS_PORTB_PCC  |= (1 << 30);	/* Enable clock for PORTC */
  ADDRESS_PORTB_PCR0 |= (1 << 9); /* Port C6: MUX = ALT2,UART1 TX */
  ADDRESS_PORTB_PCR1 |= (1 << 9); /* Port C7: MUX = ALT2,UART1 RX */
  NVIC_ISER_0 |= (1 << (31 % 32)); /* NVIC UART */
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
void LPUART0_TransReceiver_Pin(void) {
	
	  ADDRESS_LPUART0_PCC &= ~(1U << 30); /* Ensure clk disabled for config */
  	ADDRESS_LPUART0_PCC |=  (3<<24); // /* Clock Src= 1 (SOSCDIV2_CLK) */
  //  ADDRESS_LPUART1_PCC_PCS |= (1<<8); // /* Clock Src= 1 (SOSCDIV2_CLK) */
    ADDRESS_LPUART0_PCC |= (1U << 30);   /* Enable clock for LPUART1 regs */
	

}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
void LPUART0_BaudRate(unsigned int p_Baud)
{
	  ADDRESS_LPUART0_BAUD |= (0x0f <<24); /*set oversamping ratio =16 */
		ADDRESS_LPUART0_BAUD &= ~ (0x1FFF <<0);  /*clear bit 0-12*/
		ADDRESS_LPUART0_BAUD |= ((48000000/(p_Baud*16)) <<0); /*set oversamping ratio =16 */

}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
void LPUART0_Frame(unsigned int p_DataNumber,unsigned int p_ParityBit)
{
	unsigned int f_tmp=0;
	if(p_DataNumber==8)
	{
		f_tmp=0;// 8bit
	}
	else if(p_DataNumber==9)
	{
		f_tmp=1;// 9bit
	}
	else
	{
		/*do nothing*/
	}
	ADDRESS_LPUART0_BAUD &= ~(1U <<13); /*set 1 bit stop bit*/
																											
	ADDRESS_LPUART0_CTRL |= (f_tmp <<4);		/*9-Bit or 8-Bit Mode Select*/
	ADDRESS_LPUART0_CTRL |= (p_ParityBit <<1); // set ParityBit

   
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
void LPUART0_Enable_RxTx(void){
  ADDRESS_LPUART0_CTRL |= (1 <<21);// Receiver Interrupt Enable
//ADDRESS_LPUART1_CTRL |= (1 <<23); // Transmit Interrupt Enable
	ADDRESS_LPUART0_CTRL |= (1 <<18);// Rx Enable
	ADDRESS_LPUART0_CTRL |= (1 <<19); // Tx Enable
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
void LPUART0_init(void)
{	
	  LPUART0_TransReceiver_Pin();
	  LPUART0_BaudRate(9600);
	  LPUART0_Frame(8,0);
	  LPUART0_Enable_RxTx();
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
// poling
void LPUART0_transmit_char(unsigned char send) { /* Function to Transmit single Char */

  while( (ADDRESS_LPUART0_STAT & (1 << 23) ) == 0);/* Wait for received buffer to be empty */
    ADDRESS_LPUART0_DATA = (send & 0xFF );
    
}

 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
// poling
void LPUART0_transmit_string(const char data_string[]) {
    /* Transmit chars one at a time until null terminator is encountered */
    for (uint32_t i = 0; data_string[i] != '\0'; ++i) {
        LPUART0_transmit_char(data_string[i]);
    }
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
// poling
char LPUART0_receive_char(void){
    char receive;

	  while( (ADDRESS_LPUART0_STAT & (1 << 21) )== 0);/* Wait for received buffer to be empty */
    receive = (unsigned char)(ADDRESS_LPUART0_DATA);
    return receive;
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
// interrupt
void LPUART0_transmit_char_interrupt(unsigned char send) { /* Function to Transmit single Char */

  if ( (ADDRESS_LPUART0_STAT & (1 << 23) ) != 0){
		
	    ADDRESS_LPUART0_DATA = (send & 0xFF );
	
	}/* Wait for received buffer to be empty */
    
}
 /*
  *****************************************************************************
	Function name   : LPUART_TransReceiver_Pin
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
										+ TXD : I/O
										+ RXD : I

	*****************************************************************************
*/
char LPUART0_receive_char_interrupt(void) { /* Function to Transmit single Char */

    char receive;

	  if ( (ADDRESS_LPUART0_STAT & (1 << 21) )== 0){
				
		}
		else{
		    receive = (unsigned char)(ADDRESS_LPUART0_DATA);

		}/* Wait for received buffer to be empty */
    return receive;
	
    
}




