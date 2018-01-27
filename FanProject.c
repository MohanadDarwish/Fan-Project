#include "Main.h"
#include "SSD.h"
#include "LCD.h"
#include "LED.h"
#include "SW.h"
#include "ADC.h"
#include "Buzzer.h"
#include "Speed_Motor.h"
#include "Swing_Motor.h"
#include "Display.h"
#include "Slider.h"
#include "sEOS.h"

U16 __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;

void main(void)
{
    SSD_Init(SSD_ALL);
    LCD_Init(LCD_4bit_mode);
    LED_Init(LED_ALL);
    SW_Init(SW_Plus);
    SW_Init(SW_Minus);
    SW_Init(SW_Timer);
    SW_Init(SW_Display);
    ADC_Init();
    Buzzer_Init();
    Speed_Motor_Init();
    Swing_Motor_Init();
    Display_Init(SSD_ALL,LCD_4bit_mode);
    Slider_Init();
    sEOS_Init();

    while(1)
    {
        //do nothing
    }
}
