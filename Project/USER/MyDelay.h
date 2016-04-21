#ifndef _MY_DELAY_H
#define _MY_DELAY_H
#include "stm8l15x.h"
void TIM4_Config(void);
void TIM1_Config(void);
void Delay1(__IO uint32_t nTime);
void TimingDelay_Decrement(void);
#endif
