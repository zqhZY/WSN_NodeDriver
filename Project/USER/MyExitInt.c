#include "MyExitInt.h"
#include "stm8l15x.h"
void MyExitIntInit(void)
{
    //GPIO_Init( GPIOD,GPIO_Pin_3, GPIO_Mode_In_PU_IT);
    //EXTI_SetPinSensitivity(EXTI_Pin_3,EXTI_Trigger_Falling);
    
    GPIO_Init(GPIOA,GPIO_Pin_5,GPIO_Mode_In_PU_IT);//GPIO_Mode_In_FL_IT);
    EXTI_SetPinSensitivity(EXTI_Pin_5,EXTI_Trigger_Falling);
}

/*uint8_t MyExitIntGetState(Button_TypeDef Button)
{
    return GPIO_ReadInputDataBit(BUTTON_PORT[Button], (GPIO_Pin_TypeDef)BUTTON_PIN[Button]);
}*/
