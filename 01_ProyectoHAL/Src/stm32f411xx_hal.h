/*
 * stm32f411xx_hal.h
 *
 *  Created on: 2/03/2023
 *      Author: Samuel Huertas Rojas
 */

#ifndef INC_STM32F411XX_HAL_H_
#define INC_STM32F411XX_HAL_H_

#include <stdint.h>
#include <stddef.h>

#define HSI_CLOCK_SPEED    16000000    //Value for the main clock signal (HSI -> High Speed Internal)
#define HSE_CLOCK_SPEED    4000000     //Value for the main clock signal (HSE -> High Speed External)

#define NOP()    asm("NOP")
#define __weak   __attribute((weak))

/*
 * Base addresses of Flash and SRAM memories
 * Datasheet, Memory Map, Figure 14
 * (Remember, 1KByte = 1024 bytes)
 */
#define FLASH_BASE_ADDR    0x08000000U    //Esta es la memoria del programa, 512KB
#define SRAM_BASE_ADDR     0x20000000U    //Esta es la memoria RAM, 128KB

/*
 * Ahora agregamos la dirección de memoria base para cada uno de los periféricos que posee el micro
 * En el data sheet del micro, encontramos el mapa de los buses:
 * 	- APB1
 * 	- APB2
 * 	- AHB1
 * 	- AHB2
 *
 * 	AHBx y APBx dirección de los periféricos
 */
#define APB1_BASE_ADDR    0x40000000U
#define APB2_BASE_ADDR    0x40010000U
#define AHB1_BASE_ADDR    0x40020000U
#define AHB2_BASE_ADDR    0x50000000U

/*
 * Ahora se debe de hacer lo mismo pero para cada una de las posiciones de memoria de cada uno de los
 * periféricos descritos en la tabla.
 */

/*
 * Posiciones de memoria para periféricos del AHB2
 */
#define USB_OTG_FS_BASE_ADDR    (AHB2_BASE_ADDR + 0x0000U)

/*
 * Posiciones de memoria para periféricos del AHB1
 * Observar que NO esta completa
 */
#define RCC_BASE_ADDR		(AHB1_BASE_ADDR + 0x3800U)
#define GPIOH_BASE_ADDR  	(AHB1_BASE_ADDR + 0x1C00U)
#define GPIOE_BASE_ADDR  	(AHB1_BASE_ADDR + 0x1000U)
#define GPIOD_BASE_ADDR  	(AHB1_BASE_ADDR + 0x0C00U)
#define GPIOC_BASE_ADDR		(AHB1_BASE_ADDR + 0x0800U)
#define GPIOB_BASE_ADDR		(AHB1_BASE_ADDR + 0x0400U)
#define GPIOA_BASE_ADDR		(AHB1_BASE_ADDR + 0x0000U)

/*
 * Marcos Genéricos
 */
#define ENABLE				1
#define DISABLE				0
#define SET					ENABLE
#define CLEAR				DISABLE
#define RESET				DISABLE
#define GPIO_PIN_SET		SET
#define GPIO_PIN_RESET		RESET
#define FLAG_SET			SET
#define FLAG_RESET			RESET
#define I2C_WRITE			0
#define I2C_READ			1

/*
 * Definición de la estructura de datos que representa a cada uno de los registros que componen el
 * periférico RCC
 */
typedef struct
{
	volatile uint32_t CR;		//Clock Control Register 		ADDR_OFFSET:	0x00
	volatile uint32_t PLLCFGR;	//PLL Configuration				ADDR_OFFSET:	0x04
	volatile uint32_t CFGR;		//Clock Configuration register	ADDR_OFFSET:	0x08
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t reserved0;
	volatile uint32_t reserved1;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t reserved2;
	volatile uint32_t reserved3;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t reserved4;
	volatile uint32_t reserved5;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t reserved6;
	volatile uint32_t reserved7;
	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t reserved8;
	volatile uint32_t reserved9;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t reserved10;
	volatile uint32_t reserved11;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t reserved12;
	volatile uint32_t reserved13;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
	volatile uint32_t reserved14;
	volatile uint32_t DCKCFGR;
}RCC_RegDef_t;

/*
 * Puntero a RCC_RegDef_t queapunta a la posición excata del periférico RCC, de forma que cada uno de los SFR en
 * la memoria del MCU.
 */
#define RCC				((RCC_RegDef_t *) RCC_BASE_ADDR)

/*
 * 6.3.9 RCC_AHB1ENR
 */
#define RCC_AHB1ENR_GPIOA_EN		0
#define RCC_AHB1ENR_GPIOB_EN		1
#define RCC_AHB1ENR_GPIOC_EN		2
#define RCC_AHB1ENR_GPIOD_EN		3
#define RCC_AHB1ENR_GPIOE_EN		4
#define RCC_AHB1ENR_GPIOH_EN		7
#define RCC_AHB1ENR_CRCEN			12
#define RCC_AHB1ENR_DMA1_EN			21
#define RCC_AHB1ENR_DMA2_EN			22

/* ===== Fin de la descripción de los elementos que componen el periférico RCC =====*/.

/*==== Inicio de la descripción de los elementos que componen el periférico GPIOx ====*/
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
} GPIOx_RegDef_t;

/*
 * Al igual que con el RCC, creamos un puntero a la estructura que define GPIOx y debemos hacer
 * que cada GPIOx quede ubicado exactamentesobre la posición de memoria correcta.
 */
#define GPIOA				((GPIOx_RegDef_t *) GPIOA_BASE_ADDR)
#define GPIOB				((GPIOx_RegDef_t *) GPIOB_BASE_ADDR)
#define GPIOC				((GPIOx_RegDef_t *) GPIOC_BASE_ADDR)
#define GPIOD				((GPIOx_RegDef_t *) GPIOD_BASE_ADDR)
#define GPIOE				((GPIOx_RegDef_t *) GPIOE_BASE_ADDR)
#define GPIOH				((GPIOx_RegDef_t *) GPIOH_BASE_ADDR)

/*
 * Valores estándar para las configuraciones
 * 8.4.1 GPIOx_MODER (dos bit por cada PIN)
 */
#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3

/*
 * 8.4.2 GPIOx_OTYPER (un bit por PIN)
 */
#define GPIO_OTYPER_PUSHPULL	0
#define GPIO_OTYPER_OPENDRAIN	1

/*
 * GPIOx_OSPEEDR (dos bit por PIN)
 */
#define GPIO_OSPEED_LOW		0
#define GPIO_OSPEED_MEDIUM	1
#define GPIO_OSPEED_FAST	2
#define GPIO_OSPEED_HIGH	3

/*
 * GPIOx_PUPDR (dos bit por PIN)
 */
#define GPIO_PUPDR_NOTHING		0
#define GPIO_PUPDR_PULLUP		1
#define GPIO_PUPDR_PULLDOWN		2
#define GPIO_PUPDR_RESERVED		3












