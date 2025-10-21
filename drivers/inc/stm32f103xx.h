/*
 * stm32f103xx.h
 *
 *  Created on: Oct 21, 2025
 *      Author: Rana Samir
 */

#ifndef DRIVERS_INC_STM32F103XX_H_
#define DRIVERS_INC_STM32F103XX_H_


#include <stdint.h>
/* base addresses of FLASH and SRAM memories */

#define FLASH_BASEADDR         0x08000000U
#define SRAM1_BASEADDR         0x20000000U
#define ROM_BASEADDR           0x1FFFF000U
#define SRAM                   SRAM1_BASEADDR

/* AHBx and APBx Bus Peripheral base addresses */

#define PERIPH_BASE            0x40000000U
#define APB1PERIPH_BASE        PERIPH_BASE
#define APB2PERIPH_BASE        0x40010000U
#define AHBPERIPH_BASE         0x40018000U

/* base addresses of GPIOx Peripherals */

#define GPIOA_BASEADDR        (APB2PERIPH_BASE+0x0800)
#define GPIOB_BASEADDR        (APB2PERIPH_BASE+0x0C00)
#define GPIOC_BASEADDR        (APB2PERIPH_BASE+0x1000)
#define GPIOD_BASEADDR        (APB2PERIPH_BASE+0x1400)

/* base addresses of RCC Peripheral */

#define RCC_BASEADDR          (AHBPERIPH_BASE+0x1000)

/* peripheral register definitions structure  */

typedef struct
{
  volatile uint32_t CRL;    // offset 0x00
  volatile uint32_t CRH;    // offset 0x04
  volatile uint32_t IDR;    // offset 0x08
  volatile uint32_t ODR;    // offset 0x0C
  volatile uint32_t BSRR;   // offset 0x10
  volatile uint32_t BRR;    // offset 0x14
  volatile uint32_t LCKR;   // offset 0x18
} GPIO_TypeDef;

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;

} RCC_TypeDef;

/* Peripheral definitions  */

#define GPIOA ((GPIO_TypeDef *) GPIOA_BASEADDR)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASEADDR)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASEADDR)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASEADDR)

#define RCC   ((RCC_TypeDef *) RCC_BASEADDR)

/* clock enable Macros for GPIOx peripherals */

#define GPIOA_PCLK_EN()            ( RCC->APB2ENR |=(1<<2))
#define GPIOB_PCLK_EN()            ( RCC->APB2ENR |=(1<<3))
#define GPIOC_PCLK_EN()            ( RCC->APB2ENR |=(1<<4))
#define GPIOD_PCLK_EN()            ( RCC->APB2ENR |=(1<<5))

/* clock disable Macros for GPIOx peripherals */

#define GPIOA_PCLK_DI()            ( RCC->APB2ENR &=~(1<<2))
#define GPIOB_PCLK_DI()            ( RCC->APB2ENR &=~(1<<3))
#define GPIOC_PCLK_DI()            ( RCC->APB2ENR &=~(1<<4))
#define GPIOD_PCLK_DI()            ( RCC->APB2ENR &=~(1<<5))





#endif /* DRIVERS_INC_STM32F103XX_H_ */
