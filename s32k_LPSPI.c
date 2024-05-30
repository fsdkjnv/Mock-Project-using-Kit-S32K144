/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "s32k_LPSPI.h"
 /*
  *****************************************************************************
	Function name   : PORT_init_master
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
								

	****************************************************************************
*/
#include "s32k144.h"

void PORT_init_master (void) {
  ADDRESS_PORTB_PCC  |= (1 << 30);	
	
//Connect LPSPI0_SCK to LPSPI1_SCK.(B2-B14)
//Connect LPSPI0_SIN to LPSPI1_SIN.(B3-B16)
//Connect LPSPI0_SOUT to LPSPI1_SOUT.(B4-B15)
//Connect LPSPI0_PS1 to LPSPI1_PCS3.(B5-B17)
	
	
	ADDRESS_PORTB_PCR2 |= (3 << 8); /* Port B2: MUX = ALT3, LPSPI0_SCK */
  ADDRESS_PORTB_PCR3 |= (3 << 8); /* Port E1: MUX = ALT3, LPSPI0_SIN */
  ADDRESS_PORTB_PCR4 |= (3 << 8); /* Port E2: MUX = ALT3, LPSPI0_SOUT */
  ADDRESS_PORTB_PCR5 |= (3 << 8); /* Port B0: MUX = ALT3, LPSPI0_PS1 */
	}
 /*
  *****************************************************************************
	Function name   : LPSPI0_int_master
								

	****************************************************************************
*/
void LPSPI0_int_master(void){
  ADDRESS_LPSPI_SCG |=(1<<8);	
		/*Select source LPSPI*/
	ADDRESS_LPSPI0_PCC |= (3<< 24); /* Enable PCS=SPLL_DIV2 (40 MHz func'l clock) */
	

  ADDRESS_LPSPI0_PCC |= (1 << 30);   /* + Enable clock for LPSPI: PCC[CGC]*/
	
	//LPSPI0->CFGR1 |= (1 << 2)|(1 << 3)|(1 << 0);
	
	ADDRESS_LPSPI0_CFGR1|= (1 << 2);/*Automatic PCS generation is enabled: CFGR1[NOSTALL]]*/

	ADDRESS_LPSPI0_CFGR1|= (1 << 3);/*Set FIFO underrun: CFGR1[AUTOPCS]]*/
	
	ADDRESS_LPSPI0_CFGR1|= (1 << 0);/*Set mode: CFGR1[MASTER]*/
//	
	
	LPSPI0->TCR  = (1<<24)|(3<<27)|(15<<0);	/*Setting Clock*/
//	ADDRESS_LPSPI0_TCR = 0X19000007;/*Set : TCR */
																	/* CPOL=0: SCK inactive state is low */
																	/* CPHA=0: */
																	/* PRESCALE=8 */
																	/* PCS=1: Transfer using PCS1 */
																	/* LSBF=0: Data is transferred MSB first */
																	/* BYSW=0: Byte swap disabled */
																	/* CONT, CONTC=0: Continuous transfer disabled */
															  	/* RXMSK=0: Normal transfer: rx data stored in rx FIFO */
																	/* TXMSK=0: Normal transfer: data loaded from tx FIFO */
																	/* WIDTH=0: Single bit transfer */
																	/* FRAMESZ=15: # bits in frame = 15+1=16 */
	
	
	
	
//  ADDRESS_LPSPI0_CCR |= (4 << 0);/* SCKDIV=4: SCK divider =4+2 = 6 (1 usec: 1 MHz baud rate) */
	LPSPI0->CCR |= (4<< 0);

  LPSPI0->FCR |= (0 << 16)|(0 << 17)|(0 << 18) ;
	
  LPSPI0->FCR |= (0 << 0)|(0 << 1)|(0 << 2);/* TXWATER=0 : Tx flags   */

	
	LPSPI0->CR  |= (1 << 3);/*LPSPI module is enabled in debug mode: CR[DBGEN]*/

	LPSPI0->CR  |= (1 << 0);/*Module Enable: CR[MEN]*/

	
}
 /*
  *****************************************************************************
	Function name   : LPSPI0_transmit
  ****************************************************************************
*/
void LPSPI0_transmit(uint16_t send){
	  while( (ADDRESS_LPSPI0_SR & 0x1u) >> 0u == 0);   /* Wait for Tx FIFO available 	*/
    ADDRESS_LPSPI0_TDR = send; /* Transmit data 	*/
}
 /*
  *****************************************************************************
	Function name   : LPSPI0_transmit_string
	Description     : 
								

	****************************************************************************
*/
void LPSPI0_transmit_string(const char data_string[]) {
    /* Transmit chars one at a time until null terminator is encountered */
    for (uint32_t i = 0; data_string[i] != '\0'; ++i) {
        LPSPI0_transmit(data_string[i]);
    }
}
 /*
  *****************************************************************************
	Function name   : LPSPI0_receive
	Description     : 							

	****************************************************************************
*/
char LPSPI0_receive (void){
	  char receive;
	  while( (ADDRESS_LPSPI0_SR & 0x2u) << 1u == 0);/* Wait at least one RxFIFO entry 	*/
    receive = (char)(ADDRESS_LPSPI0_RDR);/* Read received data 				*/
    return receive;
	}
 /*
  *****************************************************************************
	Function name   : PORT_init_slave
	Description     : + Enable clock for PORT: PCC[CGC]
                    + Set alternate function pin: PORT_PCR[MUX]
	                  + NVIC SPI 
								

	****************************************************************************
*/


void PORT_init_slave (void) {
  ADDRESS_PORTB_PCC  |= (1 << 30);	
  ADDRESS_PORTB_PCR14 |= (3 << 8); /* Port B14: MUX = ALT3, LPSPI1_SCK */
  ADDRESS_PORTB_PCR15 |= (3 << 8); /* Port B15: MUX = ALT3, LPSPI1_SIN */
  ADDRESS_PORTB_PCR16 |= (3 << 8); /* Port B16: MUX = ALT3, LPSPI1_SOUT */
  ADDRESS_PORTB_PCR17 |= (3 << 8); /* Port B17: MUX = ALT3, LPSPI1_PCS3 */
	NVIC_ISER_0 |= (1 << (27 % 32)); /* NVIC SPI */

	}
 /*
  *****************************************************************************
	Function name   : LPSPI1_int_slave							

	****************************************************************************
*/
void LPSPI1_int_slave(void){
  ADDRESS_LPSPI_SCG |=(1<<8);

	/*Select source LPSPI*/
	ADDRESS_LPSPI1_PCC |= (3 << 24);  /* + Enable clock for LPSPI: PCC[CGC]*/

  ADDRESS_LPSPI1_PCC |= (1 << 30);  /* Enable PCS=SPLL_DIV2 (40 MHz func'l clock) */
	/*Setting Clock*/
	ADDRESS_LPSPI1_TCR = 0X1B000007;/*Set : TCR */
																	/* CPOL=0: SCK inactive state is low */
																	/* CPHA=0: */
																	/* PRESCALE=8 */
																	/* PCS=3: Transfer using PCS3 */
																	/* LSBF=0: Data is transferred MSB first */
																	/* BYSW=0: Byte swap disabled */
																	/* CONT, CONTC=0: Continuous transfer disabled */
																	/* RXMSK=0: Normal transfer: rx data stored in rx FIFO */
																	/* TXMSK=0: Normal transfer: data loaded from tx FIFO */
																	/* WIDTH=0: Single bit transfer */
																	/* FRAMESZ=7: # bits in frame = 7+1=8 */
  ADDRESS_LPSPI1_CCR|= (4 << 0);/*Module Enable: CR[MEN]*/

	
  ADDRESS_LPSPI1_FCR|= (0 << 16)|(0 << 17)|(0 << 18) ;/*+ Set Receive FIFO Watermark: FCR[RXWATER]*/
  ADDRESS_LPSPI1_FCR|= (0 << 0)|(0 << 1)|(0 << 2);/*Set Transmit FIFO Watermark: FCR[TXWATER]*/
	
	ADDRESS_LPSPI1_CFGR1|= (1 << 2);/*Set FIFO underrun: CFGR1[NOSTALL]]*/
	ADDRESS_LPSPI1_CFGR1|= (1 << 3);/*Set FIFO underrun: CFGR1[NOSTALL]]*/
	ADDRESS_LPSPI1_CFGR1|= (0 << 0);/*Set mode: CFGR1[Slave]*/
	
	ADDRESS_LPSPI1_IER|= (1 << 1);/*Set mode:Enable interrupt*/

	ADDRESS_LPSPI1_CR|= (1 << 0);/*Module Enable: CR[MEN]*/

}
 /*
  *****************************************************************************
	Function name   : LPSPI1_transmit							

	****************************************************************************
*/
void LPSPI1_transmit(uint8_t send){
	  while( (ADDRESS_LPSPI1_SR & 0x1u) >> 0u == 0);   /* Wait for Tx FIFO available 	*/
    ADDRESS_LPSPI1_TDR = send ;
}
 /*
  *****************************************************************************
	Function name   : LPSPI1_receive							

	****************************************************************************
*/
char LPSPI1_receive (void){
    char receive = 0;
	  while( (ADDRESS_LPSPI1_SR & 0x2u) << 1u == 0);/* Wait at least one RxFIFO entry 	*/
    receive = (char)(ADDRESS_LPSPI1_RDR);
    return receive;
}
 /*
  *****************************************************************************
	Function name   : LPSPI1_receive_interrupt

	****************************************************************************
*/
char LPSPI1_receive_interrupt (void){
    char receive = 0;
	  if( (ADDRESS_LPSPI1_SR & 0x2u) << 1u == 0);/* Wait at least one RxFIFO entry 	*/
    receive = (char)(ADDRESS_LPSPI1_RDR);
    return receive;
  
}

