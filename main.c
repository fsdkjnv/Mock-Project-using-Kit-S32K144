/******************************************************************************
*                       Name:VO THI THUY VI                                   *
*                       Class:EMB_09    																			*
*                       ----MINIPROJECT----																		*
 *****************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_gpio.h"
#include "Delay.h"
/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
#define PINRED   15
#define PINGREEN 16       
#define PINBLUE  0
#define SW2_PIN  12 /*Stop, Start led*/
#define SW3_PIN  13 /*invert the light order of LEDs.*/
#define PTA3     3  /*Stop, Start led*/
#define PTB8     8  /*invert the light order of LEDs.*/

/******************************************************************************
 *  VARIABLES
Description
- forwardDirection: Control the direction of color change.
- sw3State: Status of push button 3
   
- sw2State: Status of push button 2
           
- mode:
						+ mode=0: Start Leds light up periodically
						+ mode=1: Led current is bright
						

- currentColor: current color

- currentColorStop:   current color so that the current Led is lit



 *****************************************************************************/
static int forwardDirection=1;
static int sw3State =1; 
static int mode =0;  
static int sw2State=1;
static int currentColor = 0; 
static int currentColorStop ; 
/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
 void config(void);
 void toggleLEDs(void);
 void stopLED(void);
/******************************************************************************
 *                               MAIN PROGRAM                                 *
 *****************************************************************************/
int main(void) {
    config(); 

    while (1) {
        switch (mode) {
            case 0:
                stopLED();
                break;
            case 1:
                toggleLEDs();
                break;
        }
    }
} 
 
 /******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/
/****************************************************************/
/*
  *****************************************************************************
	Function name   :     config
	Description     :   - Config led, button

	*****************************************************************************
*/
void config(void) {
  configLed(PINRED);
  configLed(PINGREEN);
  configLed(PINBLUE);
	configButton(SW3_PIN); 
  configButton(SW2_PIN);
	configButton_portA(PTA3);
	configButton_portB(PTB8);

}
/*
  *****************************************************************************
Function name   :  toggleLEDs
Description     :
-  Invert the light order of LEDs:
											sw2State = 0: reverse direction
											sw2State =1: forward direction

	*****************************************************************************
*/
void toggleLEDs(void) {
		if (sw2State == 0) { 
			forwardDirection = -1; /*Change direction to reverse*/
			currentColor = (currentColor + forwardDirection + 3) % 3; /*Ensure positive result*/
	} else {  
			forwardDirection = 1; /*Change direction to forward*/
			currentColor = (currentColor + forwardDirection) % 3;
	}
  switch (currentColor) {
    case 0:
      setOutputPin(PINGREEN, 0);
      setOutputPin(PINRED, 1);
      setOutputPin(PINBLUE, 1);
		  currentColorStop =0;
      delay(15000); // Delay 
      break;
    case 1:
      setOutputPin(PINGREEN, 1);
      setOutputPin(PINRED, 0);
      setOutputPin(PINBLUE, 1);
	  	currentColorStop=1;
      delay(15000); // Delay 
      break;
    case 2:
      setOutputPin(PINGREEN, 1);
      setOutputPin(PINRED, 1);
      setOutputPin(PINBLUE, 0);
	   	currentColorStop=2;
      delay(15000); // Delay 
      break;
  }    
}
/*
  *****************************************************************************
	Function name   :  stopLED
	Description     :  - Stop Leds light up periodically(Led current is bright).

	*****************************************************************************
*/
void stopLED(void) {
  switch (currentColorStop) {
    case 0:
      setOutputPin(PINGREEN, 0);
      setOutputPin(PINRED, 1);
      setOutputPin(PINBLUE, 1);
      break;
    case 1:
      setOutputPin(PINGREEN, 1);
      setOutputPin(PINRED, 0);
      setOutputPin(PINBLUE, 1);
      break;
    case 2:
      setOutputPin(PINGREEN, 1);
      setOutputPin(PINRED, 1);
      setOutputPin(PINBLUE, 0);
      break;
  }	 	
}
/*
  *****************************************************************************
	Function name   :  PORTC_IRQHandler
	Description     :  - Code for handling button connected to PORTC pin 13,14
										 - Button State Handling 


	*****************************************************************************
*/

void PORTC_IRQHandler(void) {
    if (ADDRESS_PORTC_PCR13 & (1 << 24)) {
        ADDRESS_PORTC_PCR13 |= (1 << 24);

        if (sw3State == 0) {
            sw3State = 1;
            mode = 0;
        } else {
            sw3State = 0;
            mode = 1;
        }
    }

    if (ADDRESS_PORTC_PCR12 & (1 << 24)) {
        ADDRESS_PORTC_PCR12 |= (1 << 24);
        if (sw2State == 0) {
            sw2State = 1;
            mode = 1;
            sw3State = 0;
        } else {
            sw2State = 0;
            mode = 1;
            sw3State = 0;
        }
    }
}
/*
  *****************************************************************************
	Function name   :  PORTA_IRQHandler
	Description     :  - Code for handling button connected to PORTC pin 3
										 - Button State Handling 

	*****************************************************************************
*/
void PORTA_IRQHandler(void){
    if (ADDRESS_PORTA_PCR3 & (1 << 24)) {
        ADDRESS_PORTA_PCR3 |= (1 << 24);
        if (sw3State == 0) {
            sw3State = 1;
            mode = 0;
        } else {
            sw3State = 0;
            mode = 1;
        }
    }

}
/*
  *****************************************************************************
	Function name   :  PORTB_IRQHandler
	Description     :  - Code for handling button connected to PORTC pin 8
										 - Button State Handling 

	*****************************************************************************
*/
void PORTB_IRQHandler(void){
    if (ADDRESS_PORTB_PCR8 & (1 << 24)) {
        ADDRESS_PORTB_PCR8 |= (1 << 24);
        if (sw2State == 0) {
            sw2State = 1;
            mode = 1;
            sw3State = 0;
        } else {
            sw2State = 0;
            mode = 1;
            sw3State = 0;
        }
    }

}
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
