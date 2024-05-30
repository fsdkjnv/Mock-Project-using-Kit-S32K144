/******************************************************************************
*                       Name: VO THI THUY VI
*                       Class: EMB_09
*                       ----MINIPROJECT----
******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_gpio.h"
#include "Delay.h"
#include "stm32f144_uart.h"
#include <stdint.h>
#include <string.h>  
/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
#define PINRED 15
#define BUFFER_SIZE 100

static char Buffer[BUFFER_SIZE];
static volatile uint32_t bufferIndex = 0;
int a;
/******************************************************************************
 *                               MAIN PROGRAM                                 *
 *****************************************************************************/
int main(void) {
    configLed(PINRED);
    LPUART_PORT_init();
    LPUART1_init();

    while (1) {		       

    }
}
/******************************************************************************
 * Interrupt Uart                                                             *
 *****************************************************************************/
void LPUART1_RxTx_IRQHandler(void) {
    char receivedChar = LPUART1_receive_char_interrupt();
 
    if (bufferIndex < BUFFER_SIZE - 1) {
        Buffer[bufferIndex] = receivedChar;
        bufferIndex++;
        Buffer[bufferIndex] = '\0'; 
    }
 

	       
		

}
