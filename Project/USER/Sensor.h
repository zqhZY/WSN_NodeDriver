#ifndef _MY_SENSOR_H
#define _MY_SENSOR_H
#include "stm8l15x.h"


void delay_init(u8 clk);
void delay_us(u16 nus);
void delay_ms(u32 nms);

//u8 Delayms(u8 num);
//u8 DelayUs(void);//—” ±10Œ¢√Î
void Sensor_GOIO_Iint(void);
void Sensor_Start(void);
void Sensor_FlagTrig(uint8_t high);




#endif
