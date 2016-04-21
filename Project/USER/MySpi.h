#ifndef _MY_SPI_H
#define _MY_SPI_H
#include "stm8l15x.h"
void SPI1_Init(void);
u8 SpiReadDat8(u8 reg);
void  SpiWriteDat8(u8 reg,u8 dat);  
#endif
