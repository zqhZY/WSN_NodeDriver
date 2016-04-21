#ifndef MYUART_H
#define MYUART_H
#include "stm8l15x.h"
void MyCOMInit(uint32_t USART_BaudRate,
                      USART_WordLength_TypeDef USART_WordLength,
                      USART_StopBits_TypeDef USART_StopBits,
                      USART_Parity_TypeDef USART_Parity,
                      USART_Mode_TypeDef USART_Mode);
void USART_Config(void);
#endif