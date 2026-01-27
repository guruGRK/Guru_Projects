
#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#include "mcu.h"


typedef enum					 //Timer selection
{
    TIMER_0 = 0,
    TIMER_1
} timer_sel;


typedef enum					//CTCR Mode
{
    TIMER_MODE        = 0,   
    COUNTER_RISING    = 1,   
    COUNTER_FALLING   = 2,   
    COUNTER_BOTH      = 3   
} timer_mode;


typedef enum					//CAP input selection
{
    CAP_INPUT_0 = 0,
    CAP_INPUT_1 = 1,
    CAP_INPUT_2 = 2,
    CAP_INPUT_3 = 3
} cap_input;


TIMER_RegDef* timer_get_base(timer_sel timer);

void timer_init( timer_sel timer, timer_mode mode, cap_input cap, uint32_t freq_hz);

void timer_start(timer_sel timer);

void timer_stop(timer_sel timer);

void timer_reset(timer_sel timer);

void timer_delay( timer_sel timer, uint32_t ms);

#endif


  