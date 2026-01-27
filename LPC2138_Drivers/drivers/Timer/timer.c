
#include "timer.h"
#include "mcu.h"


 TIMER_RegDef* timer_get_base(timer_sel timer)
{
    if(timer == TIMER_0) 
	   return  TIMER0; 
	else
	   return  TIMER1;
}


void timer_init( timer_sel timer, timer_mode mode, cap_input cap, uint32_t freq_hz)
{
    TIMER_RegDef *TMR = timer_get_base(timer);
    uint32_t prescale;

    TMR->TCR = 0x00;

	if(timer == TIMER_0)
       T0_CTCR = ((cap & 0x03) << 2) | (mode & 0x03);
	else
	   T1_CTCR = ((cap & 0x03) << 2) | (mode & 0x03);

    if (mode == TIMER_MODE)
    {
        prescale = (60000000U / freq_hz) - 1;
        TMR->PR = prescale;
    }

    TMR->TCR = (1 << 1);
    TMR->TCR = 0x00;
}


void  timer_start( timer_sel timer)
{
    TIMER_RegDef *TMR = timer_get_base(timer);
	TMR->TC = 0;
	TMR->PC = 0;
    TMR->TCR = (1 << 0);
}


void  timer_stop( timer_sel timer)
{
    TIMER_RegDef *TMR = timer_get_base(timer);
    TMR->TCR = 0x00;
}


void  timer_reset( timer_sel timer)
{
    TIMER_RegDef *TMR = timer_get_base(timer);
    TMR->TCR = (1 << 1);
    TMR->TCR = 0x00;
}

uint32_t  timer_get_count( timer_sel timer)
{
    TIMER_RegDef *TMR = timer_get_base(timer);
    return TMR->TC;
}


void  timer_delay( timer_sel timer, uint32_t ms)
{
    TIMER_RegDef *TMR = timer_get_base(timer);
    uint32_t target = ms * 1;  

    timer_reset(timer);
    timer_start(timer);

    while (TMR->TC < target);

    timer_stop(timer);
}



