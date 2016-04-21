#include "MyGpio.h"
#include "stm8l15x_gpio.h"
void MyGpioOutPutInit(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin)
{
  //        GPIOA          GPIO_Pin_4    GPIO_Mode_Out_PP_High_Fast
  GPIO_Init(GPIOx,GPIO_Pin,GPIO_Mode_Out_PP_Low_Slow);
  
}

void MyGpioHigh(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin)
{
  GPIO_SetBits(GPIOx, GPIO_Pin);
}

void MyGpioLow(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin)
{
  GPIO_ResetBits(GPIOx, GPIO_Pin);
}


void MyGpioInputPutInit(GPIO_TypeDef* GPIOx, uint8_t GPIO_Pin)
{
  GPIO_Init(GPIOx,GPIO_Pin,GPIO_Mode_In_PU_No_IT);
}

u8 MyGpioGet(GPIO_TypeDef* GPIOx, GPIO_Pin_TypeDef GPIO_Pin)
{
  return GPIO_ReadInputDataBit(GPIOx,GPIO_Pin);
}




