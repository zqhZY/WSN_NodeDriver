#include"Sensor.h"


volatile u8 fac_us=0; //us延时倍乘数

//延时函数初始化
//为确保准确度,请保证时钟频率最好为4的倍数,最低8Mhz
//clk:时钟频率(24/16/12/8等)
void delay_init(u8 clk)
{
 if(clk>16)fac_us=(16-4)/4;//24Mhz时,stm8大概19个周期为1us
 else if(clk>4)fac_us=(clk-4)/4;
 else fac_us=1;
}
//延时nus
//延时时间=(fac_us*4+4)*nus*(T)
//其中,T为CPU运行频率(Mhz)的倒数,单位为us.
//准确度:
//92%  @24Mhz
//98%  @16Mhz
//98%  @12Mhz
//86%  @8Mhz
void delay_us(u16 nus)
{
__asm(
"PUSH A          \n"  //1T,压栈
"DELAY_XUS:      \n"
"LD A,fac_us     \n"   //1T,fac_us加载到累加器A
"DELAY_US_1:     \n"
"NOP             \n"  //1T,nop延时
"DEC A           \n"  //1T,A--
"JRNE DELAY_US_1 \n"   //不等于0,则跳转(2T)到DELAY_US_1继续执行,若等于0,则不跳转(1T).
"NOP             \n"  //1T,nop延时
"DECW X          \n"  //1T,x--
"JRNE DELAY_XUS  \n"    //不等于0,则跳转(2T)到DELAY_XUS继续执行,若等于0,则不跳转(1T).
"POP A           \n"  //1T,出栈
);
}
//延时nms
//为保证准确度,nms不要大于16640.
void delay_ms(u32 nms)
{
 u8 t;
 if(nms>65)
 {
  t=nms/65;
  while(t--)delay_us(65000);
  nms=nms%65;
 }
 delay_us(nms*1000);
}

void Sensor_GOIO_Iint(void)
{
  GPIO_Init(GPIOD, GPIO_Pin_1, GPIO_Mode_Out_PP_High_Fast);//T1
  GPIO_Init(GPIOD, GPIO_Pin_2, GPIO_Mode_Out_PP_Low_Fast);//T2
  
   EXTI_DeInit();
 // EXTI_SelectPort(EXTI_Port_D);
  
  //GPIO_Init(GPIOD, GPIO_Pin_4, GPIO_Mode_Out_PP_High_Fast);//R2
  GPIO_Init(GPIOD, GPIO_Pin_5,GPIO_Mode_In_FL_No_IT);//R1浮空输入
  //EXTI_SetPinSensitivity(EXTI_Pin_5, EXTI_Trigger_Rising);

  
  GPIO_Init(GPIOA, GPIO_Pin_5, GPIO_Mode_Out_OD_HiZ_Fast);//发射端口使能
 }
//发送两路状态相反的波
u8 fuck;
void Sensor_Start(void)
{ 
  for(fuck=0;fuck<8;fuck++)
  {
  GPIOD->ODR |= GPIO_Pin_1;//置高
  GPIOD->ODR &= (uint8_t)(~GPIO_Pin_2);
  delay_us(11);
  GPIOD->ODR &= (uint8_t)(~GPIO_Pin_1);//拉低
  GPIOD->ODR |= GPIO_Pin_2;
  delay_us(11);
  }
 
}

//准备接收的发送信号，占空比可调，0<high<22
void Sensor_FlagTrig(uint8_t high)
{
  GPIOD->ODR |= GPIO_Pin_4;//置高  
  delay_us(high);
  GPIOD->ODR &= (uint8_t)(~GPIO_Pin_4);//拉低
  delay_us(20-high);
}








/*
u8 DelayUs(void)//延时10微秒
{
  u8 temp;
  for(temp=0;temp<16;temp++);
  return temp;
}
*/
 