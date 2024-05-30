#include "s32k1_LPIT.h"
#include "stm32f144_gpio.h"
#define ADDRESS_LPIT_SIRCDIV (*((volatile uint32_t*)(0x40064000u+0x204u)))


void SettingClock(void){
	 NVIC_ISER_1 |= (1 << (48 % 32)); /* NVIC SPI */

   ADDRESS_LPIT_PCC |= (2<<24);/* */
   ADDRESS_LPIT_PCC |= (1<<30);/* */
	 // PCC->PCCn[LPIT0_BASE]|= (1 << 30); /* Enable clock for PORTB */
   //  PCC->PCCn[PCC_LPIT_INDEX ]|= (1 << 30); /* Enable clock for PORTB */
   ADDRESS_LPIT_SIRCDIV|= (1<<8);

}
 void LPIT_Init(void){
   //Module Clock Enable: MCR[M_CEN], kich hoat dong ho
   // ADDRESS_LPIT_MCR |= (1<<0);
	 ADDRESS_LPIT_MCR|=(1<<0);
	 ADDRESS_LPIT_MCR|=(1<<3);
   ADDRESS_LPIT_MIER |= (1<<0);
	 // Run in debug mode
   // ADDRESS_LPIT_MCR |= (1<<3);
	 ADDRESS_LPIT_TVAL0 = 8000000-1;

 }
void Config_channel(void){
  ADDRESS_LPIT_TCTRL0 = 0x00000001; 	
}
void TimeChannel(void){
	   ADDRESS_LPIT_TCTRL0 |=(1<<0);

}
