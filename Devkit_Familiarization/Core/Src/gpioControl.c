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
// Return  : true if there are no errors in the code else false
// Notes   : None
//******************************************************************************
bool gpioControlLed()
{
	bool blCheck = false;
	uint16 unValue = 0;
	uint16 unFlag = 0;

	unValue = (rand() % (MAX_LIMIT)) + 1;
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
			unFlag = 1;

			break;
	}

	if (0 == unFlag)
	{
		blCheck = true;
	}

	HAL_Delay(MAX_DELAY);

	return blCheck;
}

//******************************.gpioControlSet.********************************
// Purpose : Function to set data in board
// Inputs  : None
// Outputs : None
// Return  : true if there are no errors in the code else false
// Notes   : None
//******************************************************************************
bool gpioControlSet(UART_HandleTypeDef *huart3)
{
	bool blCheck = false;
	int8 cData[] = "LIONEL MESSI\n";

	if (NULL != huart3)
	{
		HAL_UART_Transmit(huart3, (uint8_t *)cData, strlen(cData), MAX_TIME);
		blCheck = true;
	}

	return blCheck;
}

//EOF
