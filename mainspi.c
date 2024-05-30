/******************************************************************************
*                       Name: VO THI THUY VI
*                       Class: EMB_09
******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_gpio.h"
#include "Delay.h"
#include "stm32f144_uart.h"
#include <stdint.h>
#include <string.h>  
#include "s32k_LPSPI.h"
/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
#define BUFFER_SIZE 100
#define PINRED   15
void config (void);
void LPSPI1_IRQHandler(void);
static char Buffer[BUFFER_SIZE];
static volatile uint32_t bufferIndex = 0;
/******************************************************************************
 *                               MAIN PROGRAM                                 *
 *****************************************************************************/
int main(void) {

	config();
  configLed(PINRED);
	LPSPI0_transmit('h');
    while (1) {		       

    }
		
}
 /*
  *****************************************************************************
	Function name   : config							
  This function is used to configure modules such as LPUART, LPSPI and port GPIO.
	****************************************************************************
*/
void config(void){
    LPUART_PORT_init();
    LPUART1_init();
    PORT_init_master();
    LPSPI0_int_master();
    PORT_init_slave();
    LPSPI1_int_slave();

}
/******************************************************************************
 * LPSPI1_IRQHandler Uart                                                             *
 *****************************************************************************/
void LPSPI1_IRQHandler(void)
{
    char receivedChar ;
	    receivedChar=0;
			receivedChar = LPSPI1_receive_interrupt();
 
    if (bufferIndex < BUFFER_SIZE - 1) {
        Buffer[bufferIndex] = receivedChar;
        bufferIndex++;
        Buffer[bufferIndex] = '\0'; 
    }
 
   if (strcmp(Buffer, "Hello World!") == 0) {
		 			  memset(Buffer, 0, sizeof(Buffer));
            bufferIndex = 0;
				    setOutputPin(PINRED, 1); // Turn on the LED
       } 
	       
}