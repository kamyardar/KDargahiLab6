/*
 * Timer_Driver.c
 *
 *  Created on: Dec 6, 2024
 *      Author: kamya
 */

#include "Timer_Driver.h"

uint32_t GetDuration(uint32_t ts, uint32_t te){
	if(ts>te)
		return ((0xffffffff-ts)+te);
	return (te-ts);
}



