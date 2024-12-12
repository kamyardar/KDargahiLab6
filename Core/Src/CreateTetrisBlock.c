/*
 * CreateTetrisBlock.c
 *
 *  Created on: Nov 29, 2024
 *      Author: kamwa
 */


#include "CreateTetrisBlock.h"

static uint8_t RNGvalue;

uint32_t TetriminoBlock[4][4];
uint8_t xAxis = 0;
uint8_t yAxis = 3;
uint8_t TetriminoRotation = 0;
uint32_t beginTim = 0;
uint32_t endTim = 0;
uint32_t totalTim = 0;
uint32_t firstGrid[10][10] ={0};
uint32_t newGrid[10][10] ={0};
char durationArray[10] = {'\0'};

bool GameCollisionCheck()
{
	bool collision = DoesBlockCollide();
	if (collision == true)
	{
		PlaceTetrisBlock(newGrid);
		PlaceTetrisBlock(newGrid);
		return 1;
	}
	else if (collision != true)
	{
		PlaceTetrisBlock(firstGrid);
		PlaceTetrisBlock(firstGrid);
		return 0;
	}
	return 0;
}

void startTetris() {
//    beginTim = HAL_GetTick();
	uint32_t ts = 0;
	uint32_t te = 0;

	ts = HAL_GetTick();
    CreateTetrisBlock();
    PlaceTetrisBlock(firstGrid);
    CreateTetrimino(firstGrid);
    HAL_Delay(499);

    for(;;)
    {
    	bool collidechecker = DoesBlockCollide();
		if (collidechecker)
		{
			PlaceTetrisBlock(newGrid);
			memcpy(firstGrid, newGrid, sizeof(newGrid));
			xAxis = 0;
			TetriminoRotation = 0;
			CreateTetrisBlock();
			if(GameCollisionCheck()) break; // end the game
		}
		else
		{
			 memcpy(firstGrid, newGrid, sizeof(newGrid));
			 MoveBlockDown();
			 bool collidechecker_2 = DoesBlockCollide();
			if (!collidechecker_2) CreateTetrimino(firstGrid);
		}
		HAL_Delay(499);
    }
    te = HAL_GetTick();
	uint32_t dur = 0;
	dur = GetDuration(ts,te);

	EndScreen(dur);
//	ResultScreen(durationArray);
}
//    if(endTim < beginTim){
//    	totalTim = (0xFFFFFFFF - beginTim)+endTim;
//    	sprintf(durationArray, "%d", totalTim/1000);
//    	ResultScreen(durationArray);
//    } else {
//    	totalTim = endTim - beginTim;
//    	sprintf(durationArray, "%d", totalTim/1000);
//    	ResultScreen(durationArray);
//    }
//}

void CreateTetrisBlock()
{
	RNGvalue = generator();
    memcpy(TetriminoBlock, TetrisBlocks[RNGvalue][0], sizeof(TetrisBlocks[RNGvalue][0]));
}

void MoveBlockDown(){
	uint8_t previousw = xAxis;
	xAxis = 1 + xAxis;
	bool collision = DoesBlockCollide();

	if (!collision)
	{
		PlaceTetrisBlock(firstGrid);
	}
	else
	{
		xAxis = previousw;
		PlaceTetrisBlock(newGrid);
	}
}

void PlaceTetrisBlock(uint32_t grid[10][10])
{
	uint8_t w;
    for (w = 0; w < 4; w++)
    {
    	uint8_t z;
        for (z = 0; z < 4; z++)
        {
            if (TetriminoBlock[w][z] == true)
            {
                uint8_t gridz = yAxis + z;
                uint8_t gridw = xAxis + w;

                if (10 > gridz && 10 > gridw)
                {
                	grid[gridw][gridz] = 1;
                	grid[gridw][gridz] = TetriminoBlock[w][z];
}}}}}

void RotateBlock(){
	uint8_t previousRot = TetriminoRotation;
	TetriminoRotation = 1 + TetriminoRotation;

	if (TetriminoRotation > 3)
	        TetriminoRotation = 0;

    memcpy(TetriminoBlock, deleteTetrimeno, sizeof(TetrisBlocks[RNGvalue][TetriminoRotation]));

    memcpy(TetriminoBlock, TetrisBlocks[RNGvalue][TetriminoRotation], sizeof(TetrisBlocks[RNGvalue][TetriminoRotation]));

    bool collision = DoesBlockCollide();
    if (collision == false)
    {
		memcpy(firstGrid, newGrid, sizeof(newGrid));
		PlaceTetrisBlock(firstGrid);
		CreateTetrimino(newGrid);
		CreateTetrimino(firstGrid);
	}
    else
    {
		TetriminoRotation = previousRot;
	    memcpy(TetriminoBlock, deleteTetrimeno, sizeof(TetrisBlocks[RNGvalue][TetriminoRotation]));
        memcpy(TetriminoBlock, TetrisBlocks[RNGvalue][TetriminoRotation], sizeof(TetrisBlocks[RNGvalue][TetriminoRotation]));
	}
}

bool DoesBlockCollide(){
	int gridz = 0;
	int gridw = 0;
	for (int w = 0; w <= 3; ++w)
	{
		for (int z = 0; z < 4; z++)
		{
			if (TetriminoBlock[w][z])
			{
				gridz = yAxis + z;
				gridw = xAxis + w;
				if (!(gridz < 10) || !(gridw < 10))
				{
				    memcpy(firstGrid, deleteGrid, sizeof(deleteGrid));
				    memcpy(newGrid, deleteGrid, sizeof(deleteGrid));
					return 1;
				}
				if (newGrid[gridw][gridz] != 0)
					return 1;
	}}}
    return 0;
}
