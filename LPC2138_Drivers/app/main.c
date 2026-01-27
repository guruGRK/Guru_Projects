
#include "clk_config.h"

#include "gpio.h"

#include "timer.h"


int main(){

   clk_init(0x24, 0x01);

   GPIO_pin_init(GPIO0 , 2, GPIO_FUNC, OUTPUT);

   GPIO_writeto_pin(GPIO0 , 2, 1);

   GPIO_readfrom_pin(GPIO0 , 2);
   /*
   GPIO_port_init(GPIO0, 0x00FF00F0);

   GPIO_writeto_port(GPIO0 ,0x00FF00F0 );

   GPIO_readfrom_port(GPIO0);
   */
   return 0;
}

