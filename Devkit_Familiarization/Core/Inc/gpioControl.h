//********************************** GPIO **************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
//
// Summary : Contains all type definitions, global constants and forward
//		 	 declarations required for gpioControl.c operations
// Note    : None
//
//******************************************************************************
#ifndef GPIOCONTROL_H
#define GPIOCONTROL_H

//******************************* Include Files *******************************
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"

//******************************* Global Types ********************************
// Defines the variable declaration
typedef unsigned short uint16;
typedef char int8;

// Defines switch cases
typedef enum {
	FIRST_CASE = 1,
	SECOND_CASE,
	THIRD_CASE
}SWITCH_CASES;

//***************************** Global Constants ******************************
#define MAX_LIMIT		(3)
#define MAX_TIME		(100)
#define MAX_DELAY		(400)

//***************************** Global Variables ******************************

//**************************** Forward Declarations ***************************
bool gpioControlLed();
bool gpioControlSet(UART_HandleTypeDef *huart3);

//*********************** Inline Method Implementations ***********************

#endif // GPIOCONTROL_H
// EOF
