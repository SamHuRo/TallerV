/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f411xx_hal.h"


int main(void)
{
	//Configuración inicial del MCU
	RCC->AHB1ENR &= ~(1 << 0); //Limpiando la posición 0
	RCC->AHB1ENR |= (1 << 0); //Activando la señal de reloj del GPIO

	//Confiuracion MODE
	GPIOA->MODER &= ~(0b01 << 10); //Limpiando la posición 11 y 10 del GPIOA-MODER
	GPIOA->MODER |= (0b01 << 10); //Configurando el pinC5 como salida general

	//Configurando el OTYPE
	GPIOA->OTYPER &= ~(0b1 << 5); //pinA5 configurando como salida Push-pull

	//Configurando el OSPEED
	GPIOA->OSPEEDR &= ~(0b11 << 10); //Limpiando las posiciones correspondientes al pinA5
	GPIOA->OSPEEDR |= (0b01 << 10); //Configurando la velocidad como Fast

	//Configurando el ODR
	GPIOA->ODR &= ~(0b1 << 5); //Limpiando posicion 5 -LED apagado
	GPIOA->ODR |= (0b1 << 5); //Escribiendo 1 en la posicion 5 - LED Enciende

    /* Loop forever */
	while(1){

	}

	return 0;

}