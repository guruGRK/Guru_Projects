
#ifndef  GPIO_H
#define  GPIO_H

#include "mcu.h"

#include <stdint.h>

#define GPIO_FUNC   0
#define FUNC1       1
#define FUNC2       2
#define FUNC3       3

#define INPUT   0
#define OUTPUT  1 

void  GPIO_pin_init(GPIO_RegDef* Port ,uint8_t PinNumber, uint8_t FuncSel,uint8_t InOutMode);

void  GPIO_writeto_pin(GPIO_RegDef* Port ,uint8_t PinNumber, uint8_t value);

uint8_t  GPIO_readfrom_pin(GPIO_RegDef* Port ,uint8_t PinNumber);



void GPIO_port_init(GPIO_RegDef* Port, uint32_t dir_value);

void GPIO_writeto_port(GPIO_RegDef* Port ,uint32_t value );

uint32_t  GPIO_readfrom_port(GPIO_RegDef* Port);

#endif
