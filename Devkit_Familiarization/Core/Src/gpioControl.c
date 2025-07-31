//*********************************** GPIO *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : GpioControl.c
// Summary : Does Basic devkit operations involving GPIO pins like LED blinking
//			 and printing data using UART
// Note    : None
// Author  : Bimesh Raj K R
// Date    : 31/Jul/2025
//******************************************************************************

//****************************** Include Files *********************************
#include "gpioControl.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//******************************.gpioControlLed.********************************
// Purpose : Function to Blink LED
// Inputs  : None
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool gpioControlLed()
{
	uint16 unValue = (rand() % (MAX_LIMIT)) + 1;

	switch (unValue)
	{
		case FIRST_CASE:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
			break;

		case SECOND_CASE:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
			break;

		case THIRD_CASE:
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
			break;

		default:
			printf("Invalid case\n");
			break;
	}

	HAL_Delay(MAX_DELAY);

	return true;
}

//******************************.gpioControlSet.********************************
// Purpose : Function to set data in board
// Inputs  : None
// Outputs : None
// Return  : true
// Notes   : None
//******************************************************************************
bool gpioControlSet(UART_HandleTypeDef *huart3)
{
	int8 cData[] = "LIONEL MESSI\n";
	HAL_UART_Transmit(huart3, (uint8_t *)cData, strlen(cData), MAX_TIME);

	return true;
}

//EOF
