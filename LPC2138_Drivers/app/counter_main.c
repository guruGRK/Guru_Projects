
#include "clk_config.h"

#include "gpio.h"

#include "timer.h"


int main(){

   clk_init(0x24, 0x01);
   
   GPIO_pin_init(GPIO0 , 2, FUNC2, INPUT);			     

   timer_init( TIMER_0, COUNTER_RISING, CAP_INPUT_0, 0);	 

   timer_start( TIMER_0);
   
   return 0;
}