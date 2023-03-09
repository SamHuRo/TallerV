/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Samuel Huertas Rojas
 * @brief          : Main program body
 ******************************************************************************
 * Con este programa
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f411xx_hal.h"
#include "GPIOxDriver.h"

// Funcion principal del programa. Acá es donde se ejecuta todo
int main(void)
{
	//Definimos el handler para el Pin que deseamos configurar
	GPIO_Handler_t handlerUserLedPin = {0};

	//Deseamos trabajar con el puerto GPIOA
	handlerUserLedPin.pGPIOx = GPIOA;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinNumber			= PIN_5;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinMode			= GPIO_MODE_OUT;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinOPType			= GPIO_OTYPER_PUSHPULL;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinPuPdControl	= GPIO_PUPDR_NOTHING;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinSpeed			= GPIO_OSPEED_MEDIUM;
	handlerUserLedPin.GPIO_PinConfig.GPIO_PinAltFunMode		= AF0; 						//Ninguna Función

	//Cargamos la configuración del Pin especifico
	GPIO_Config(&handlerUserLedPin);

	//Hacmos que el Pin_A% quede encendido
	GPIO_WritePin(&handlerUserLedPin, SET);

    /* Loop forever */
	while(1){
		NOP();
	}

	return 0;

}
