/******************************************************************************
*                       Name: VO THI THUY VI
*                       Class: EMB_09
*                       Mock Project
******************************************************************************/

/******************************************************************************
 *  INCLUDES
 *****************************************************************************/
#include "stm32f144_gpio.h"
#include "Delay.h"
#include <stdint.h>
#include <string.h>  
#include "s32k_LPSPI.h"
#include "s32k1_LPIT.h"
#include "stm32f144_uart.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>  
/******************************************************************************
 *  DEFINES & MACROS
 *****************************************************************************/
#define PINRED   15
#define PINRED   15
#define PINGREEN 16       
#define PINBLUE  0
#define SW2_PIN  12 
#define SW3_PIN  13 
#define PTA3     3  
#define PTB8     8  
#define BUFFER_SIZE 11
/******************************************************************************
 *  VARIABLES
 *****************************************************************************/
static uint8_t count_seconds = 1; // for seconds
static uint8_t count_minutes = 0; // for minutes
static uint8_t count_hours = 0;   // for hours
static uint8_t count_days = 1;     // for days
static uint8_t count_months = 1;  // for months
static uint32_t count_years = 1971; // for years

static int mode =0; /*to select mode, mode=0: ; mode=1; mode=3 */
static int sw3State =1; /*state sw3*/
static int sw2State=1; /*state sw2*/

static char Buffer_uart[BUFFER_SIZE];
static volatile uint32_t bufferIndex = 0;
/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
void config (void);
void LPSPI1_IRQHandler(void);
void cofig_lpit(void);
void MAX7219_SendData(uint16_t address, uint16_t data);
void MAX7219_EnableSegment(uint8_t digit, uint8_t segment);
void MAX7219_Init(void);
void MAX7219_DisplayNumber(uint8_t digit, uint8_t number);
void toggleDecimalPointAndDisplay(uint8_t digit, uint8_t value, uint8_t state);
void displayTime(void);
void displayDay(void) ;
void displayturnoff(void);
void LPIT0_Ch0_IRQHandler(void);
/******************************************************************************
 *                               MAIN PROGRAM                                 *
 *****************************************************************************/


int main(void) {

	 config();
	
   MAX7219_Init(); 	
   MAX7219_DisplayNumber(0, 0); // Display "0" on the fourth digit
   MAX7219_DisplayNumber(1, 0); // Display "0" on the first digit
   MAX7219_DisplayNumber(2, 10); // Display "-" on the second digit
   MAX7219_DisplayNumber(3, 0); // Display "0" on the third digit
   MAX7219_DisplayNumber(4, 0); // Display "0" on the fourth digit
   MAX7219_DisplayNumber(5, 10); // Display "-" on the fourth digit
   MAX7219_DisplayNumber(6, 0); // Display "0" on the fourth digit
   MAX7219_DisplayNumber(7, 0); // Display "0" on the fourth digit
    while (1) {		       

    }
}
 /******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/
 /*
  *****************************************************************************
	Function name   : MAX7219_SendData							
  Appears to be designed for sending data to a MAX7219 LED display driver
 ****************************************************************************
*/

void MAX7219_SendData(uint16_t address, uint16_t data) {
  ADDRESS_GPIOB_PDOR  &= ~ (1U << 5); // Set CS low
  LPSPI0_transmit((address<<8)| data); // Transmit address and adrress
  ADDRESS_GPIOB_PDOR |= (1U << 5); // Set CS high

}
 /*
  *****************************************************************************
	Function name   : MAX7219_EnableSegment							
  Appears to be designed for sending data to a MAX7219 LED display driver
	****************************************************************************
*/
void MAX7219_EnableSegment(uint8_t digit, uint8_t segment) {
    // Enable a specific segment on a digit
    MAX7219_SendData(digit + 1, 1 << segment);
}
 /*
  *****************************************************************************
	Function name   : MAX7219_Init							
  Designed to initialize the MAX7219 LED display driver with specific configuration commands
  ****************************************************************************
*/
void MAX7219_Init(void) {
    // MAX7219 initialization commands
    MAX7219_SendData(0x0C, 0x01); // Normal operation mode
    MAX7219_SendData(0x0B, 0x07); // Scan limit: 8 digits
    MAX7219_SendData(0x09, 0xFF); // Decode mode: BCD for all digits
    MAX7219_SendData(0x0A, 0x0F); // Intensity: maximum brightness
}
 /*
  *****************************************************************************
	Function name   : MAX7219_DisplayNumber							
  Appears to be designed for sending data to a MAX7219 LED display driver
	****************************************************************************
*/
void MAX7219_DisplayNumber(uint8_t digit, uint8_t number) {
        MAX7219_SendData(digit+1, number); // Digit address starts from 1

}
 /*
  *****************************************************************************
	Function name   : toggleDecimalPointAndDisplay							
  Designed to toggle the decimal point on a specific digit of a MAX7219-driven LED display and simultaneously display a numeric value. 
****************************************************************************
*/
void toggleDecimalPointAndDisplay(uint8_t digit, uint8_t value, uint8_t state) {
    // Toggle the decimal point on a specific digit and display a number
    // digit: Digit number (0 to 7)
    // value: Number to display (0 to 15 for hexadecimal display)
    // state: 0 to turn off decimal point, 1 to turn on decimal point
    // Check if the digit number is within a valid range (0 to 7)
    if (digit < 8) {
        // Determine the segment associated with the decimal point
        uint8_t dpSegment = 7;
        // Calculate the value to send to MAX7219 based on the state
        uint8_t dpValue = (state != 0) ? (1 << dpSegment) : 0;
       // Send the data to MAX7219 to toggle the decimal point
        MAX7219_SendData(digit+1, dpValue+value); 
    }
}

 /*
  *****************************************************************************
	Function name   : cofig_lpit							
  This function is used to configure modules LPIT
	****************************************************************************
*/
void cofig_lpit(void) {
    // Set up clock settings required for LPIT
    SettingClock();

    // Initialize LPIT module
    LPIT_Init();

    // Configure LPIT channel settings
    Config_channel();

    // Set up timing for LPIT channel
    TimeChannel();
}

 /*
  *****************************************************************************
	Function name   : config							
  This function is used to configure modules such as LPUART, LPIT ,LPSPI and port GPIO.
	****************************************************************************
*/

void config(void) {
    // Initialize master settings for PORT
    PORT_init_master();

    // Initialize master settings for LPSPI0
    LPSPI0_int_master();

    // Configure LPIT module
    cofig_lpit();

    // Configure SW3 and SW2 buttons
    configButton(SW3_PIN); // Assuming SW3_PIN is defined elsewhere
    configButton(SW2_PIN); // Assuming SW2_PIN is defined elsewhere

    // Initialize settings for LPUART0 port
    LPUART_PORT0_init();

    // Initialize settings for LPUART0 module
    LPUART0_init();
}

 /*
  *****************************************************************************
	Function name   : displayTime							
  Display the current time  
	****************************************************************************
*/
void displayTime(void) {
    MAX7219_SendData(0x0C, 0x01); // Normal operation mode

    MAX7219_DisplayNumber(7, count_hours / 10);    // Display tens of hours
    MAX7219_DisplayNumber(6, count_hours % 10);    // Display units of hours
    MAX7219_DisplayNumber(5, 10); // Display "2" on the second digit

    MAX7219_DisplayNumber(4, count_minutes / 10);  // Display tens of minutes
    MAX7219_DisplayNumber(3, count_minutes % 10);  // Display units of minutes
    MAX7219_DisplayNumber(2, 10); // Display "2" on the second digit

    MAX7219_DisplayNumber(1, count_seconds / 10);  // Display tens of seconds
    MAX7219_DisplayNumber(0, count_seconds % 10);  // Display units of seconds
}
 /*
  *****************************************************************************
	Function name   : displayDay							
  Display the current day
	****************************************************************************
*/
void displayDay(void) {
    MAX7219_SendData(0x0C, 0x01); // Normal operation mode
	// To turn on the decimal point on digit 3 and display the number 5
   	MAX7219_DisplayNumber(7, count_days/10);
  	toggleDecimalPointAndDisplay(6,  count_days%10,1);    // Display units of hours
    MAX7219_DisplayNumber(5, count_months / 10);
	  toggleDecimalPointAndDisplay(4, count_months % 10, 1);
    // Display thousands of years (e.g., 2022 -> 2)
    MAX7219_DisplayNumber(3, (count_years / 1000) % 10);
     // Display hundreds of years (e.g., 2022 -> 0)
    MAX7219_DisplayNumber(2, (count_years / 100) % 10);
     // Display tens of years (e.g., 2022 -> 2)
    MAX7219_DisplayNumber(1, (count_years / 10) % 10);
     // Display units of years (e.g., 2022 -> 2)
    MAX7219_DisplayNumber(0, count_years % 10);



}
 /*
  *****************************************************************************
	Function name   : displayturnoff							
  Display turn  off
	****************************************************************************
*/
void displayturnoff(void) {
    MAX7219_SendData(0x0C, 0x00); // Normal operation mode
}
 /*
  *****************************************************************************
	Function name   : LPIT0_Ch0_IRQHandler						

	+ Timekeeping Logic
	+ Display Mode Logic
	+ Increment Seconds and Clear Interrupt Flag
	****************************************************************************
*/
void LPIT0_Ch0_IRQHandler(void){

        if (count_seconds % 60 == 0) {
            count_seconds = 0;
            count_minutes++;

            // Reset minutes and increment hours
            if (count_minutes % 60 == 0 ) {
                count_minutes = 0;
                count_hours++;

                // Reset hours and increment days
                if (count_hours % 24 == 0) {
   									count_hours = 0;
                    count_days++;
										if(count_months==4|count_months==6|count_months==9|count_months==11){
													// Reset days and increment months
													if (count_days > 30) { // Assuming 30 days in a month for simplicity
															count_days = 1;
															count_months++;

															// Reset months and increment years
															if (count_months > 12) {
																	count_months = 1;
																	count_years++;
															}
													}

											}else if(count_months==1|count_months==3|count_months==5|count_months==7|count_months==10) {					
																				
														if (count_days > 31) { // Assuming 31 days in a month for simplicity
																count_days = 1;
																count_months++;

																// Reset months and increment years
																if (count_months > 12) {
																		count_months = 1;
																		count_years++;
																}
														}
											
											}else {
											      if((count_years % 4 == 0 && count_years % 100 != 0) || (count_years % 400 == 0)){
												  			if (count_days > 20) { // Assuming 31 days in a month for simplicity
																count_days = 1;
																count_months++;

																// Reset months and increment years
																if (count_months > 12) {
																		count_months = 1;
																		count_years++;
																}
														}													
														
														}else{													
												   			if (count_days > 28) { // Assuming 31 days in a month for simplicity
																count_days = 1;
																count_months++;

																// Reset months and increment years
																if (count_months > 12) {
																		count_months = 1;
																		count_years++;
																}
														  }
														}									
											}

                }
            }
        }

        switch (mode) {
            case 0:
                displayTime();
                break;
            case 1:
                displayDay();
                break;
            case 3:
            	displayturnoff();
                break;
            // Add more cases if needed
            default:
                // Handle the default case (optional)
                break;
        }

        count_seconds++;
        ADDRESS_LPIT_MSR |=(1<<0) ;

}
 /*
  *****************************************************************************
	Function name   : PORTC_IRQHandler							
Interrupt Handling for PORTC Pin 13
Interrupt Handling for PORTC Pin 12

	****************************************************************************
*/
void PORTC_IRQHandler(void) {
    // Check if interrupt is triggered by PORTC pin 13
    if (ADDRESS_PORTC_PCR13 & (1 << 24)) {
        ADDRESS_PORTC_PCR13 |= (1 << 24); // Acknowledge the interrupt

        // Toggle the state of sw3State based on its current value
        if (sw3State == 0) {
            sw3State = 1;		

            // Update mode based on the value of sw3State and the current mode
            if (mode == 3) {
                mode = 3; // Mode remains 3
            } else {
                mode = 0; // Mode switches to 0
            }
        } else {
            sw3State = 0;

            // Update mode based on the value of sw3State and the current mode
            if (mode == 3) {
                mode = 3; // Mode remains 3
            } else {
                mode = 1; // Mode switches to 1
            }
        }
    }

    // Check if interrupt is triggered by PORTC pin 12
    if (ADDRESS_PORTC_PCR12 & (1 << 24)) {
        ADDRESS_PORTC_PCR12 |= (1 << 24); // Acknowledge the interrupt

        // Toggle the state of sw2State based on its current value
        if (sw2State == 0) {
            sw2State = 1;

            // Update mode based on the value of sw3State and sw2State
            if (sw3State == 1) {
                mode = 0; // Mode switches to 0 if sw3State is 1
            } else {
                mode = 1; // Mode switches to 1 if sw3State is not 1
            }
        } else {
            sw2State = 0;

            // Set mode to 3 when sw2State is 0
            mode = 3;
        }
    }
}

 /*
  *****************************************************************************
	Function name   : config							
  This function is used to configure modules such as LPUART, LPSPI and port GPIO.
	****************************************************************************
*/
void LPUART0_RxTx_IRQHandler(void) {
    char receivedChar = LPUART0_receive_char_interrupt();    // Receive a character from the LPUART0 module


    if (bufferIndex < BUFFER_SIZE - 1) {    // Check if there is space in the buffer to store the received character

        Buffer_uart[bufferIndex] = receivedChar;        // Store the received character in the buffer

        bufferIndex++;
        Buffer_uart[bufferIndex] = '\0'; 
    }
		
		if(bufferIndex==10){    // Check if the buffer is full (assuming a message length of 10 characters)

		if(Buffer_uart[2]=='-'){       // Check the message format based on the third character in the buffer

		    count_hours =(Buffer_uart[1]-'0') +		(Buffer_uart[0]-'0')*10; // Extract hours
		    count_minutes =(Buffer_uart[5]-'0') +		(Buffer_uart[4]-'0')*10; // Extract minutes
		    count_seconds =(Buffer_uart[9]-'0') +		(Buffer_uart[8]-'0')*10;// Extract seconds	

		
		} else {		
		    count_days =(Buffer_uart[1]-'0') +		(Buffer_uart[0]-'0')*10; // Extract days
		    count_months =(Buffer_uart[4]-'0') +		(Buffer_uart[3]-'0')*10; // Extract months
		    count_years =(Buffer_uart[9]-'0') +		(Buffer_uart[8]-'0')*10+(Buffer_uart[7]-'0')*100+(Buffer_uart[6]-'0')*1000; // Extract years
		}	
	 	bufferIndex=0;		
		}

}

