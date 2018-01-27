#include "Slider.h"

void Slider_Init(void)
{
    ADC_Init();
    //idk if we need to init the slider pin direction or not depends on the adc config if it is enough or not
    GPIO_InitPortPin(SLIDER_PORT_CR,SLIDER_PIN,GPIO_IN);
}
U16 Slider_Get_Value(void)
{
    U16 value=0;
    ADC_Update();
    value = ADC_Read();
    return value;
}
void Slider_Task(void)
{
    //logic controlling the different swing angles
    //0 , 45 , 90 , 135 , 180 , 225 , 270 , 315 , 360
    ;
}


