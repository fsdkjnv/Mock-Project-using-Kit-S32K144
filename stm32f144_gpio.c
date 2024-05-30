/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_gpio.h"
#include "math.h"
/******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/
/*
  *****************************************************************************
	Function name   :   configLed
	Description     :   - Enable clock for Port D
											- Set pin as GPIO
											- Set pin as output
											- Toggle pin

	*****************************************************************************
*/

void configLed(uint32_t pinNumber ){
   ADDRESS_PORTD_PCC |= (1 << 30);
    switch(pinNumber) {
        case 0:
            ADDRESS_PORTD_PCR0 |= (1 << 8);
            break;
        case 15:
            ADDRESS_PORTD_PCR15 |= (1 << 8);
            break;
        case 16:
            ADDRESS_PORTD_PCR16 |= (1 << 8);
            break;
        default:
            // Handle invalid pinNumber or add additional cases as needed
            break;
    }
   ADDRESS_GPIOD_PDDR |= (1U << pinNumber);
   ADDRESS_GPIOD_PDOR |=(1U << pinNumber);
}
/*
  *****************************************************************************
	Function name   :  setOutputPin
	Description     :   - Led status: 
														if led = 1, then turn off the led
														equal to 0 turns on the led

	*****************************************************************************
*/
void setOutputPin(uint32_t pinNumber, uint8_t state) {
    if (state) {
        // Set the corresponding bit in the GPIO port data output register
        ADDRESS_GPIOD_PDOR |= (1U << pinNumber); // off led
    } else {
        // Clear the corresponding bit in the GPIO port data output register
        ADDRESS_GPIOD_PDOR &= ~(1U << pinNumber); // On led
    }
}
/*
  *****************************************************************************
	Function name   :  configButton
	Description     :     - Enable clock for Port C (PCC_PORTx)
												- Set pin as GPIO
											  - Set pin as input
                        - set rising-edge interrupt 
                        - Enable a specific interrupt
					

	*****************************************************************************
*/
void configButton(uint32_t pinNumber ){
  ADDRESS_PORTC_PCC |= (1 << 30);
	    switch(pinNumber) {
        case 13:
            ADDRESS_PORTC_PCR13 |= (1 << 8); 
				    ADDRESS_PORTC_PCR13 |= (9<<16); 

            break;
        case 12:
            ADDRESS_PORTC_PCR12 |= (1 << 8); 
				    ADDRESS_PORTC_PCR12 |= (9<<16); 

            break;
        default:
            // Handle invalid pinNumber or add additional cases as needed
            break;
    }
 		
  ADDRESS_GPIOC_PDDR &= ~(1U << pinNumber);
	NVIC_ISER_1 |= (1 << 29);

}

/*
  *****************************************************************************
	Function name   :  configButton_portA
	Description     :     - Enable clock for Port A (PCC_PORTx)
												- Set pin as GPIO
											  - Set pin as input
                        - Enable pull up/pull down
                        - Setting pull-down resistor
                        - Set falling-edge interrupt 
                        - Enable a specific interrupt

	*****************************************************************************
*/

void configButton_portA(uint32_t pinNumber ){
  ADDRESS_PORTA_PCC |= (1 << 30);
	    switch(pinNumber) {
        case 3:
            ADDRESS_PORTA_PCR3 |= (1 << 8); 
						ADDRESS_PORTA_PCR3 |= (1<<1); 
						ADDRESS_PORTA_PCR3 &= ~(1U<<0); 
				    ADDRESS_PORTA_PCR3 |= (10<<16); 
            break;
        default:
            // Handle invalid pinNumber or add additional cases as needed
            break;
    }
  ADDRESS_GPIOA_PDDR &= ~(1U << pinNumber);
	NVIC_ISER_1 |= (1 << 27);
} 
/*
  *****************************************************************************
	Function name   :  configButton_portB
	Description     :     - Enable clock for Port B (PCC_PORTx)
												- Set pin as GPIO
											  - Set pin as input
                        - Enable pull up/pull down
                        - Setting pull-down resistor
                        - Set falling-edge interrupt 
                        - Enable a specific interrupt

	*****************************************************************************
*/
void configButton_portB(uint32_t pinNumber ){
  ADDRESS_PORTB_PCC |= (1 << 30);
	    switch(pinNumber) {
        case 8:
            ADDRESS_PORTB_PCR8 |= (1 << 8); 
						ADDRESS_PORTB_PCR8 |= (1<<1); 
						ADDRESS_PORTB_PCR8 &= ~(1U<<0); 
				    ADDRESS_PORTB_PCR8 |= (10<<16); 
            break;
        default:
            break;
    }
 		
  ADDRESS_GPIOB_PDDR &= ~(1U << pinNumber);
	NVIC_ISER_1 |= (1 << 28);
} 
/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
