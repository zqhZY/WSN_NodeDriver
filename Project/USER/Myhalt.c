#include "Myhalt.h"
#include "stm8l15x.h"
void AWU_Config(void)
{
  //AWU_DeInit();
  //AWU_LSICalibrationConfig(128000);
  // AWU_Init(AWU_TIMEBASE_1S);
  
}
void RTC_Config(u16 time) 
{  
   RTC_DeInit(); //初始化默认状态 
   CLK_PeripheralClockConfig(CLK_Peripheral_RTC, ENABLE); //允许RTC时钟 
   CLK_RTCClockConfig(CLK_RTCCLKSource_LSI, CLK_RTCCLKDiv_2); //选择RTC时钟源LSI、2=19K 
   RTC_WakeUpClockConfig(RTC_WakeUpClock_RTCCLK_Div16); //19k/16=1.1875KHz t=0.85ms 
   RTC_ITConfig(RTC_IT_WUT, ENABLE); //开启中断 
  RTC_SetWakeUpCounter(time); //设置RTC Weakup计算器初值 
  RTC_WakeUpCmd(ENABLE); //使能自动唤醒 
} 


