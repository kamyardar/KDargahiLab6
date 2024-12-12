/*
 * Timer_Driver.h
 *
 *  Created on: Dec 11, 2024
 *      Author: kamya
 */

#ifndef INC_TIMER_DRIVER_H_
#define INC_TIMER_DRIVER_H_

#include "stm32f4xx_hal.h"

uint32_t StartTimer();
uint32_t EndTimer();
uint32_t GetDuration();

#endif /* INC_TIMER_DRIVER_H_ */
