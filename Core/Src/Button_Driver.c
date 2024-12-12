/*
 * Button_Driver.c
 *
 *  Created on: Sep 26, 2024
 *      Author: kamya
 */

#include <Button_Driver.h>

void ButtonInit()
{
	//GPIO_PinConfig_t buttonConfig = {0}; // clear everything to 0 , you need a struct to change variables
	GPIO_InitTypeDef buttonConfig = {0};

	buttonConfig.Pin = BUTTON_PIN_NUMBER;
	buttonConfig.Mode = GPIO_MODE_INPUT;
	buttonConfig.Speed = GPIO_SPEED_FREQ_HIGH;
	buttonConfig.Pull = GPIO_NOPULL;

	enableClock();

	HAL_GPIO_Init(GPIOA, &buttonConfig);

//	buttonConfig.PinNumber = BUTTON_PIN_NUMBER;
//	buttonConfig.PinMode = GPIO_PIN_MODE_INPUT;
//	buttonConfig.OPType = GPIO_OPTYPE_PUSH_PULL;
//	buttonConfig.PinSpeed = GPIO_PIN_SPEED_MEDIUM;
//	buttonConfig.PinPuPdControl = GPIO_PUPDR_NONE;
//
//	enableClock();
//
//	GPIO_Init(GPIOA, buttonConfig);
}

void enableClock()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

//	GPIO_ClockControl(BUTTON_PORT_VALUE, ENABLE);
}

bool isPressed()
{
//	return true;
	if (HAL_GPIO_ReadPin(BUTTON_PORT_VALUE, BUTTON_PIN_NUMBER)==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void buttonInterruptInit()
{
	GPIO_InitTypeDef button = {0};

	button.Pin = BUTTON_PIN_NUMBER;
    button.Mode = GPIO_MODE_IT_RISING;
    button.Speed = GPIO_SPEED_FREQ_HIGH;
    button.Pull = GPIO_NOPULL;

    enableClock();

    HAL_GPIO_Init(GPIOA, &button);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);

//	GPIO_PinConfig_t button = {0};
//
//	button.PinNumber = BUTTON_PIN_NUMBER;
//	button.PinMode = GPIO_PIN_MODE_INPUT;
//	button.OPType = GPIO_OPTYPE_PUSH_PULL;
//	button.PinSpeed = GPIO_PIN_SPEED_HIGH;
//	button.PinPuPdControl = GPIO_PUPDR_NONE;
//	button.PinInterrupt = FALLING_AND_RISING_INTERRUPT;
//
//	enableClock();
//	GPIO_Init(GPIOA, button);
//	NVIC_EnableOrDisable(6, ENABLE); // pg 376
}
