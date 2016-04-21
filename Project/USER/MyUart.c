#include "MyUart.h"
#include "stm8l15x_usart.h"
#include "stm8l15x.h"

void MyCOMInit(uint32_t USART_BaudRate,
                      USART_WordLength_TypeDef USART_WordLength,
                      USART_StopBits_TypeDef USART_StopBits,
                      USART_Parity_TypeDef USART_Parity,
                      USART_Mode_TypeDef USART_Mode)
{
  /* Enable USART clock */
  CLK_PeripheralClockConfig(CLK_Peripheral_USART1, ENABLE);
  /* Configure USART Tx as alternate function push-pull  (software pull up)*/
  GPIO_ExternalPullUpConfig(GPIOC,GPIO_Pin_3, ENABLE);//tx
  /* Configure USART Rx as alternate function push-pull  (software pull up)*/
  GPIO_ExternalPullUpConfig(GPIOC,GPIO_Pin_2, ENABLE);//rx
  /* USART configuration */
  USART_Init(USART1, USART_BaudRate,USART_WordLength,USART_StopBits,USART_Parity,USART_Mode);
}
void USART_Config(void)
{
  MyCOMInit((uint32_t)9600, USART_WordLength_8b, USART_StopBits_1,USART_Parity_No, (USART_Mode_TypeDef)(USART_Mode_Tx | USART_Mode_Rx));
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  //USART_ITConfig(USART1, USART_IT_TC, ENABLE);
  USART_ClearITPendingBit(USART1, USART_IT_RXNE);//清除中断标志
  USART_Cmd(USART1, ENABLE);
  enableInterrupts();
}

