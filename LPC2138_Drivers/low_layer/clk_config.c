
#include "mcu.h"
#include "clk_config.h"

void clk_init(uint32_t pll_config, uint32_t apb_div){
   PLL->PLLCON=0x00;
   PLL->PLLFEED=0xAA;
   PLL->PLLFEED=0x55;

   PLL->PLLCFG=pll_config;
   PLL->PLLFEED=0xAA;
   PLL->PLLFEED=0x55;

   PLL->PLLCON=0x01;
   PLL->PLLFEED=0xAA;
   PLL->PLLFEED=0x55;

   while(!(PLL->PLLSTAT&(1<<10)));

   PLL->PLLCON=0x03;
   PLL->PLLFEED=0xAA;
   PLL->PLLFEED=0x55;

   APBDIV=apb_div;
}



