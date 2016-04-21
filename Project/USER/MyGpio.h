#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm8l15x.h"

void MyGpioOutPutInit(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);
void MyGpioHigh(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);
void MyGpioLow(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);

void MyGpioInputPutInit(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin);
u8 MyGpioGet(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin);
#endif
