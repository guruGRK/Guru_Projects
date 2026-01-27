
#include "gpio.h"
#include "mcu.h"

void  GPIO_pin_init(GPIO_RegDef* Port ,uint8_t PinNumber, uint8_t FuncSel,uint8_t InOutMode)
{

	//PINSEL

	if(Port == GPIO0)
	{
	    if(PinNumber < 16)
		{
	        PINSEL0 &= ~(3 << (2 * PinNumber));
		    PINSEL0 |= (FuncSel << (2 * PinNumber));
	    }
	    if(PinNumber >= 16)
		{
	        PINSEL1 &= ~(3 << (2 * (PinNumber-16)));
		    PINSEL1 |= (FuncSel << (2 * (PinNumber-16)));
	    }
	}

	//DIR

	if(FuncSel == GPIO_FUNC)
	{
	    Port->DIR &= ~(1 << PinNumber);
		Port->DIR |= (InOutMode << PinNumber); 
	}


}


void  GPIO_writeto_pin(GPIO_RegDef* Port ,uint8_t PinNumber ,uint8_t value )
{
   if(value == 0)
   {
	  Port->CLR = (1 << PinNumber);
   }
   if(value == 1)
   {
	  Port->SET = (1 << PinNumber);
   }
}


uint8_t  GPIO_readfrom_pin(GPIO_RegDef* Port ,uint8_t PinNumber)
{
   uint8_t value;
   value = ((Port->PIN >> PinNumber) & 0x00000001U);									
   return value;
}


void GPIO_port_init(GPIO_RegDef* Port, uint32_t dir_value)
{
    if (Port == GPIO0)
    {
        PINSEL0 = 0x00000000U;
        PINSEL1 = 0x00000000U;
    }

    Port->DIR = dir_value;   
}


void GPIO_writeto_port(GPIO_RegDef* Port ,uint32_t value )
{
   Port->CLR = 0xFFFFFFFFU;
   Port->SET = value;
}


uint32_t  GPIO_readfrom_port(GPIO_RegDef* Port)
{
   uint32_t value;
   value = Port->PIN;
   return value;
}
