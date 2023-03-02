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
 * Comentario
 */
#define APB1_BASE_ADDR    0x40000000U
#define APB2_BASE_ADDR    0x40010000U
#define AHB1_BASE_ADDR    0x40020000U
#define AHB2_BASE_ADDR    0x50000000U

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

};
















