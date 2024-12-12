/*
 * Button_Driver.h
 *
 *  Created on: Sep 26, 2024
 *      Author: kamya
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include <stm32f4xx_hal.h>
#include <stdbool.h>

#define BUTTON_PORT_VALUE GPIOA

#define BUTTON_PIN_NUMBER GPIO_PIN_0 // since pin 0 maps to pin 1 with hal

#define IS_PRESSED 1

#define IS_NOT_PRESSED 0

void ButtonInit();

void enableClock();

void disableClock(); // will not be used this lab

bool isPressed();

void buttonInterruptInit();

#endif /* BUTTON_DRIVER_H_ */
// port a pin 0 -> gpioa
