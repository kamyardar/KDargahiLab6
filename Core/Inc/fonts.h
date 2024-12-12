/*
 * fonts.h
 *
 *  Created on: Nov 29, 2024
 *      Author: kamya
 */

#ifndef INC_FONTS_H_
#define INC_FONTS_H_

//#ifndef __FONTS_H
//#define __FONTS_H

#include <stdint.h>

//This was taken and adapted from stm32's mcu code

typedef struct
{
  const uint16_t *table;
  uint16_t Width;
  uint16_t Height;
} FONT_t;

extern FONT_t Font16x24;
extern FONT_t Font12x12;

#endif /* INC_FONTS_H_ */
