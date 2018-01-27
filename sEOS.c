#include "sEOS.h"

volatile U16 sys_tick=0;

void sEOS_Init()
{
    //for tick every 56us
//    Timer0_Init(Timer0_Prescaler_16);// (16*4*n/*8MHz) = 8us/counts
//    Timer0_Set_Start_value(249);//7 counts to ovf 7 counts = 8us*7 = 56us(tick period)
//    Timer0_Start();

    Timer0_Init(Timer0_Prescaler_265);// (256*4*n/*8MHz)
    Timer0_Set_Start_value(178);//78 counts to ovf 7 counts = 8us*7 = 56us(tick period)
    Timer0_Start();
}

void sEOS_IRQ_Handler(void) __interrupt 0
{
    sys_tick++;
    //SSD_Task();
    //LCD_Task();
                    //LED_Task();
//    SW_Task();
                    //ADC_Task();
//    Speed_Motor_Task();
//    Swing_Motor_Task();
    Display_Task();
//    Slider_Task();

    TIMER0_INTERRUPT_FLAG_CLEAR();
    Timer0_Set_Start_value(178);
}

