/*
 * numberGenerator.c
 *
 *  Created on: Nov 29, 2024
 *      Author: kamya
 */


#include <stdio.h>
#include "numberGenerator.h"


RNG_HandleTypeDef numberGenerator;

uint32_t generator()
{
    uint32_t createNumber;
    uint32_t generatedValue;
    HAL_RNG_GenerateRandomNumber(&numberGenerator, &createNumber);

    generatedValue = createNumber % 7;
    return generatedValue;
}

void numberGenerator_init()
{
    __HAL_RCC_RNG_CLK_ENABLE();
    numberGenerator.Instance = RNG;
    HAL_RNG_Init(&numberGenerator);
}

