
#include "clk_config.h"

#include "timer.h"


int main(){

   clk_init(0x24, 0x01);
   
   timer_init( TIMER_0, TIMER_MODE, CAP_INPUT_0, 1000);		

   timer_delay( TIMER_0, 1000);
   
   return 0;
}