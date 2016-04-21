#include "stm8l15x_it.h"
#include "MyGpio.h"

INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  
}

INTERRUPT_HANDLER(FLASH_IRQHandler, 1)
{

}

INTERRUPT_HANDLER(DMA1_CHANNEL0_1_IRQHandler, 2)
{

}

INTERRUPT_HANDLER(DMA1_CHANNEL2_3_IRQHandler, 3)
{

}

INTERRUPT_HANDLER(RTC_CSSLSE_IRQHandler, 4)
{
     RTC_WakeUpCmd(DISABLE); 
     RTC_ClearITPendingBit(RTC_IT_WUT);
}

INTERRUPT_HANDLER(EXTIE_F_PVD_IRQHandler, 5)
{

}

INTERRUPT_HANDLER(EXTIB_G_IRQHandler, 6)
{

}

INTERRUPT_HANDLER(EXTID_H_IRQHandler, 7)
{

}

INTERRUPT_HANDLER(EXTI0_IRQHandler, 8)
{

}

INTERRUPT_HANDLER(EXTI1_IRQHandler, 9)
{

}

INTERRUPT_HANDLER(EXTI2_IRQHandler, 10)
{

}

extern u8 ExitStatus;
extern u8 input_key;
extern u8 input_flag;
INTERRUPT_HANDLER(EXTI3_IRQHandler, 11)
{

  

}

INTERRUPT_HANDLER(EXTI4_IRQHandler, 12)
{

}

INTERRUPT_HANDLER(EXTI5_IRQHandler, 13)
{ 
  
 // assert_param(IS_EXTI_ITPENDINGBIT(EXTI_IT_Pin5));
 // EXTI->SR1 = (uint8_t) (EXTI_IT_Pin5);
   
 

  
//  ExitStatus=1;
//  if(key==0)key=1;
//  else key=0;
  
}

INTERRUPT_HANDLER(EXTI6_IRQHandler, 14)
{
  
  //  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
                    //USART_SendData8(USART1,0x11); 
        
    EXTI_ClearITPendingBit(EXTI_IT_Pin6);
    
    
    
    
    
  
  //  enableInterrupts();
}

INTERRUPT_HANDLER(EXTI7_IRQHandler, 15)
{
 
}

INTERRUPT_HANDLER(LCD_AES_IRQHandler, 16)
{
  
}

INTERRUPT_HANDLER(SWITCH_CSS_BREAK_DAC_IRQHandler, 17)
{
  
}

INTERRUPT_HANDLER(ADC1_COMP_IRQHandler, 18)
{
 
}

INTERRUPT_HANDLER(TIM2_UPD_OVF_TRG_BRK_USART2_TX_IRQHandler, 19)
{
  
  //USART_SendData8(EVAL_COM1, TxBuffer[TxCounter++]);
  //USART_ClearITPendingBit(EVAL_COM1, USART_IT_TC);
  //if (TxCounter == TX_BUFFER_SIZE)
  //{
    //USART_ITConfig(EVAL_COM1, USART_IT_TC, DISABLE);
  //}
}

INTERRUPT_HANDLER(TIM2_CC_USART2_RX_IRQHandler, 20)
{
  //uint8_t temp;
  //temp = (USART_ReceiveData8(EVAL_COM1) & 0x7F);
  //USART_SendData8(EVAL_COM1, temp);
}

INTERRUPT_HANDLER(TIM3_UPD_OVF_TRG_BRK_USART3_TX_IRQHandler, 21)
{

}

INTERRUPT_HANDLER(TIM3_CC_USART3_RX_IRQHandler, 22)
{

}
 u16 TIM1_SET1;
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_COM_IRQHandler, 23)
{    
       
       TIM1_ClearITPendingBit(TIM1_IT_Update);
 
}

INTERRUPT_HANDLER(TIM1_CC_IRQHandler, 24)
{

}

extern void TimingDelay_Decrement(void);
extern u16 UartLoop;
extern u8 TIM4_Count;
extern u8 TIM4_Outflag;
#include "MyUart.h"

INTERRUPT_HANDLER(TIM4_UPD_OVF_TRG_IRQHandler, 25)
{
  TIM4_Count++;
  if(TIM4_Count==20)//20次标志位置1 约40ms
  {
    TIM4_Count=0;
    TIM4_Outflag=1;
    TIM4_Cmd(DISABLE);
    //USART_ITConfig(USART1, USART_IT_TC, ENABLE);
  // USART_SendData8(USART1,0X11);
  }
  TIM4_ClearITPendingBit(TIM4_IT_Update);
}

INTERRUPT_HANDLER(SPI1_IRQHandler, 26)
{

}
extern u8 comcount;
INTERRUPT_HANDLER(USART1_TX_TIM5_UPD_OVF_TRG_BRK_IRQHandler, 27)
{
  switch(comcount)
  {
  case 0:
    comcount++;
   // USART_SendData8(USART1,DevData1[0]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
  case 1:
    comcount++;
    //USART_SendData8(USART1,DevData1[1]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
  case 2:
    comcount++;
    //USART_SendData8(USART1,DevData1[2]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
    
  case 3:
    comcount++;
   // USART_SendData8(USART1,DevData2[0]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
  case 4:
    comcount++;
    //USART_SendData8(USART1,DevData2[1]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
  case 5:
    comcount++;
    //USART_SendData8(USART1,DevData2[2]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
    
  case 6:
    comcount++;
    //USART_SendData8(USART1,DevData3[0]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
  case 7:
    comcount++;
    //USART_SendData8(USART1,DevData3[1]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
  case 8:
    comcount++;
    //USART_SendData8(USART1,DevData3[2]);
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    break;
    
  case 9:
    comcount=0;
    USART_ClearITPendingBit(USART1, USART_IT_TC);
    //USART_ITConfig(USART1, USART_IT_TC, DISABLE);
    break; 
  }
}

extern u8 DevData1[5]; 
extern u8 DevData2[5];
extern u8 DevData3[5];
extern u8 DevData4[5];
extern u8 DevData5[5];

extern u8 Data_Num;
extern u8 UartBuffer[6];
extern u8 UartFlag;
extern u8 SetIdFlag;
extern u8 StartFlag;
u8 CountFlag=0;
u8 first;
//接收数据‘a’,'b'开头之后的2个字节存入全局变量DevData5[0]和DevData[1]
//为车位号的高八位和低八位


//u8 DEVID=1;
INTERRUPT_HANDLER(USART1_RX_TIM5_CC_IRQHandler, 28)
{  
  u8 n;
  u8 Res; 
  u8 bit_status;
  USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);
  Res=USART_ReceiveData8(USART1);
 
 
 
 if (StartFlag == SET)  //SET or RESET
 {  

  if(CountFlag==0)
 {
    if(Res=='a')
    {
      CountFlag=1;
    }
  }
 else
 {
   if(CountFlag==1)
   {  if(Res=='b')
      { 
        first=1;
        UartFlag=1; 
        CountFlag=2;
      }         
   }
 }
 
 if(CountFlag==2)
 { 
 if(UartFlag==1)
 { 
     if(first==1)
     {
        first=0;
     }
     else
     {

           UartBuffer[Data_Num++]=Res; 
           if(Data_Num==3)
         {  
           Data_Num=0;UartFlag=0;
           DevData5[0]=UartBuffer[0];
           DevData5[1]=UartBuffer[1]; 
           DevData5[2]=UartBuffer[2]; 
           SetIdFlag=1;
           CountFlag=0;
            
        }
       
       
            
     }
  } 
     
 }
 }

 USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

INTERRUPT_HANDLER(I2C1_SPI2_IRQHandler, 29)
{
  
}