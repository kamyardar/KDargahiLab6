/*
 * CreateTetrisBlock.h
 *
 *  Created on: Nov 29, 2024
 *      Author: kamya
 */

#ifndef INC_CREATETETRISBLOCK_H_
#define INC_CREATETETRISBLOCK_H_

#include <stdbool.h>
#include <stm32f4xx_hal.h>
#include <string.h>
#include <LCD_Driver.h>
#include <NumberGenerator.h>

uint32_t TetrisBlocks[7][4][4][4] =
{
    {
        {
            { 0 , 0 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 0 , 0 , 0 },{ 0 , 1 , 1 , 0 },{ 0 , 1 , 1 , 0 },{ 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 0 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 0 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        }
    },
    {
        {
            { 0 , 0 , 0 , 0 }, { 1 , 1 , 1 , 1 }, { 0 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 0 , 1 , 0 }, { 0 , 0 , 1 , 0 }, { 0 , 0 , 1 , 0 }, { 0 , 0 , 1 , 0 }
        },
        {
            { 0 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }, { 1 , 1 , 1 , 1 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }
        }
    },
    {
        {
            { 0 , 0 , 0 , 0 }, { 1 , 1 , 1 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 1 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 1 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        }
    },
    {
        {
            { 0 , 0 , 0 , 0 }, { 1 , 1 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 ,  1 , 0 , 0 }, { 1 , 1 , 0 , 0 }, { 1 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 0 , 0 , 0 }, { 1 , 1 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 1 , 1 , 0 , 0 }, { 1 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        }
    },
    {
        {
            { 0 , 0 , 0 , 0 }, { 1 , 1 , 1 , 0 }, { 1 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 1 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 0 , 1 , 0 }, { 1 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0 , 1 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        }
    },
    {
        {
            { 0 , 0 , 0 , 0 }, { 1 , 1 , 1 , 0 }, { 0 , 0 , 1 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 1, 1 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 1 , 0 , 0 , 0 }, { 1 , 1 , 1 , 0 }, { 0, 0 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        },
        {
            { 0, 1 , 1 , 0 }, { 0 , 1 , 0 , 0 }, { 0, 1 , 0 , 0 }, { 0 , 0 , 0 , 0 }
        }
    },
    {
        {
            { 0 , 0 , 0 , 0 }, { 0, 1 , 1 , 0 }, { 1 , 1 , 0 , 0 }, { 0, 0 , 0 , 0 }
        },
        {
            { 1, 0 , 0 , 0 }, { 1 , 1 , 0 , 0 }, { 0 , 1 , 0 , 0 }, { 0, 0 , 0 , 0 }
        },
        {
            {0 , 0 , 0 , 0 }, { 0, 1 , 1 , 0 }, { 1 , 1 , 0 , 0 }, { 0, 0 , 0 , 0 }
        },
        {
            {1, 0 , 0 , 0 },{ 1 , 1 , 0 , 0 },{ 0 , 1 , 0 , 0 },{ 0 , 0 , 0 , 0 }
        }
    },
};

uint32_t deleteTetrimeno[4][4] = { 0} ;
uint32_t deleteGrid[10][10] = { 0 };

void startTetris();

void CreateTetrisBlock();
void MoveBlockDown();
void PlaceTetrisBlock();
void RotateBlock();
bool DoesBlockCollide();

//void MoveLeft();
//void MoveRight();

#endif /* INC_CREATETETRISBLOCK_H_ */
