/******************************************************************************
 *  FUNCTION PROTOTYPES
 *****************************************************************************/
void delay(unsigned int ms);
/******************************************************************************
 *  FUNCTION DECLARATION
 *****************************************************************************/
/*
  *****************************************************************************
	Function name   :  delay
	Description     :   - pause program

	*****************************************************************************
*/
void delay(unsigned int ms) {
    unsigned char i;
    while (ms) {
        i = 200;
        while (i--);
        ms--;
    }
}
