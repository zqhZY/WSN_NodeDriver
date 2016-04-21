#include "MySpi.h"
#include "MyGpio.h"
#include "stm8l15x_spi.h"

void SPI1_Init(void)
{
  //spi_clk ->pB5  spi_miso->pB7  spi_mosi->pB6  CS PB1
  MyGpioOutPutInit(GPIOB,GPIO_Pin_1);
  MyGpioOutPutInit(GPIOB,GPIO_Pin_5);
  MyGpioOutPutInit(GPIOB,GPIO_Pin_6);
  
  MyGpioHigh(GPIOB,GPIO_Pin_1);
  MyGpioHigh(GPIOB,GPIO_Pin_5);
  MyGpioHigh(GPIOB,GPIO_Pin_6);
  
  MyGpioInputPutInit(GPIOB,GPIO_Pin_7);
  
  CLK_PeripheralClockConfig(CLK_Peripheral_SPI1, ENABLE);
  SPI_Init(SPI1,SPI_FirstBit_MSB,SPI_BaudRatePrescaler_64,SPI_Mode_Master,SPI_CPOL_Low,SPI_CPHA_1Edge,SPI_Direction_2Lines_FullDuplex,SPI_NSS_Soft, 0x00);
  SPI_Cmd(SPI1, ENABLE);     	 
}

u8 SpiReadDat8(u8 reg)
{
  u8 dat,n;
  MyGpioLow(GPIOB,GPIO_Pin_1);//CS
  
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  SPI_SendData(SPI1, reg);
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET);

  SPI_ReceiveData(SPI1);

  for(n=0;n<100;n++)dat=n;

  SPI_SendData(SPI1, 0XFF);

  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET);

  dat=SPI_ReceiveData(SPI1);

  MyGpioHigh(GPIOB,GPIO_Pin_1);
  return dat;
}

void  SpiWriteDat8(u8 reg,u8 dat)
{
  u16 n,temp;
  
  MyGpioLow(GPIOB,GPIO_Pin_1);//CS
  
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  SPI_SendData(SPI1, reg|0x80);
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET);

  SPI_ReceiveData(SPI1);

  for(n=0;n<100;n++){temp=n;n=temp;}

  SPI_SendData(SPI1, dat);

  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET);

  SPI_ReceiveData(SPI1);
  MyGpioHigh(GPIOB,GPIO_Pin_1);
}
   