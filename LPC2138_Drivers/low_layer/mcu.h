
#ifndef  LOWLAYER_H
#define  LOWLAYER_H

#include <stdint.h>


//PLL 

#define  PLL_BASE_ADDR  0xE01FC080U  					   //PLL Base address

typedef struct
{											   //PLL Register definitions
   volatile  uint32_t  PLLCON;
   volatile  uint32_t  PLLCFG;
   volatile  uint32_t  PLLSTAT; 
   volatile  uint32_t  PLLFEED;
}PLL_RegDef;
																																						
#define  PLL  ((PLL_RegDef*)PLL_BASE_ADDR)				 	//PLL Base address pointer


//APBDIV 

#define   APBDIV_BASE_ADDR  0xE01FC100U		                 //APBDIV Base address

#define  APBDIV  (*(volatile uint32_t*)APBDIV_BASE_ADDR)		 //APBDIV Base address pointer


//GPIO 

#define  GPIO0_BASE_ADDR  0xE0028000U						  //GPIO Base addresses
#define  GPIO1_BASE_ADDR  0xE0028010U

typedef struct
{												  //GPIO Registers definitions
   volatile  uint32_t  PIN;
   volatile  uint32_t  SET;
   volatile  uint32_t  DIR; 
   volatile  uint32_t  CLR;
}GPIO_RegDef;


#define GPIO0 ((GPIO_RegDef*)GPIO0_BASE_ADDR)					   //GPIO Base address pointers
#define GPIO1 ((GPIO_RegDef*)GPIO1_BASE_ADDR)	

//PIN Connect

#define  PINSEL0_BASE_ADDR  0xE002C000U						   //PIN Connect Base addresses
#define  PINSEL1_BASE_ADDR  0xE002C004U
#define  PINSEL2_BASE_ADDR  0xE002C014U

#define  PINSEL0  (*(volatile uint32_t* )PINSEL0_BASE_ADDR)		//PINSEL Base address pointers
#define  PINSEL1  (*(volatile uint32_t* )PINSEL1_BASE_ADDR)
#define  PINSEL2  (*(volatile uint32_t* )PINSEL2_BASE_ADDR)

//TIMER0

#define TIMER0_BASE_ADDR  0xE0004000U
#define TIMER1_BASE_ADDR  0xE0008000U

typedef struct
{
    volatile  uint32_t  IR;     
    volatile  uint32_t  TCR;    
    volatile  uint32_t  TC;     
    volatile  uint32_t  PR;     
    volatile  uint32_t  PC;    
    volatile  uint32_t  MCR;   
    volatile  uint32_t  MR0;    
    volatile  uint32_t  MR1;
    volatile  uint32_t  MR2;
    volatile  uint32_t  MR3;
    volatile  uint32_t  CCR;
    volatile  uint32_t  CR0;
    volatile  uint32_t  CR1;
    volatile  uint32_t  CR2;
    volatile  uint32_t  CR3;
    volatile  uint32_t  EMR;
} TIMER_RegDef;

#define T0_CTCR (*(volatile uint32_t *)(TIMER0_BASE_ADDR + 0x70))
#define T1_CTCR (*(volatile uint32_t *)(TIMER1_BASE_ADDR + 0x70))

#define TIMER0   ((TIMER_RegDef*)TIMER0_BASE_ADDR)
#define TIMER1   ((TIMER_RegDef*)TIMER1_BASE_ADDR)


#endif


				  