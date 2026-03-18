#  LPC2138 GPIO & Timer Driver Development

This project demonstrates **bare-metal driver development** for GPIO and Timer peripherals on the **LPC2138 (ARM7)** microcontroller.  
It follows a **layered architecture** similar to real embedded systems used in industry.

---

##  Project Objective

- Develop reusable GPIO and Timer drivers  
- Understand register-level programming  
- Build structured embedded firmware with separation of:
  - Application logic  
  - Drivers  
  - Low-level hardware access  

---

## 📁 Project Structure

LPC2138_Drivers/
│
├── app/
│ ├── gpio_main.c
│ ├── timer_main.c
│ └── counter_main.c
│
├── drivers/
│ ├── GPIO/
│ │ ├── gpio.c
│ │ └── gpio.h
│ │
│ └── Timer/
│ ├── timer.c
│ └── timer.h
│
├── lowlayer/
│ ├── clk_config.c
│ ├── clk_config.h
│ └── mcu.h
│
└── keil/
├── LPC2138_Drivers.uvproj
├── LPC2138_Drivers.uvopt
└── startup.s

---

##  Architecture Overview

###  1. Application Layer (`app/`)

Contains user-level programs demonstrating driver usage:

**gpio_main.c**
- Initialize GPIO pin  
- Write and read pin values  

**timer_main.c**
- Configure timer in timer mode  
- Generate delay  

**counter_main.c**
- Configure timer in counter mode  
- Count external events  

---

###  2. Driver Layer (`drivers/`)

####  GPIO Driver

- Pin configuration (PINSEL + DIR)  
- Read/Write operations  
- Port-level operations  

**Functions:**
- `GPIO_pin_init()`  
- `GPIO_writeto_pin()`  
- `GPIO_readfrom_pin()`  
- `GPIO_port_init()`  
- `GPIO_writeto_port()`  
- `GPIO_readfrom_port()`  

---

####  Timer Driver

**Supports:**
- Timer mode  
- Counter mode (Rising, Falling, Both edges)  

**Functions:**
- `timer_init()`  
- `timer_start()`  
- `timer_stop()`  
- `timer_reset()`  
- `timer_delay()`  

---

###  3. Low-Level Layer (`lowlayer/`)

Direct register access definitions.

**Files:**

**mcu.h**
- Base addresses  
- Register structures (GPIO, TIMER, PLL)  

**clk_config.c / clk_config.h**
- PLL and clock initialization  

---

###  4. Keil Project (`keil/`)

Contains:
- `.uvproj` → Project file  
- `.uvopt` → Debug settings  
- `startup.s` → Startup assembly file  

---

##  Key Features

✔ Register-level programming (No HAL)  
✔ GPIO pin & port operations  
✔ Timer delay implementation  
✔ Counter mode using capture inputs  
✔ PLL-based clock configuration  

---

##  Tools & Environment

- **IDE**: Keil µVision  
- **Language**: Embedded C  
- **Target MCU**: LPC2138 (ARM7)  
