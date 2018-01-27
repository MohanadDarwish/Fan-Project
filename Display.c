#include "Display.h"

//sys_tick = 56us 1-->178
static U8 tick_SSD = 1;// 5*sys_tick
static U8 tick_LCD = 1;//100*sys_tick

static U8 tick_counter_SSD = 0;
static U8 tick_counter_LCD = 0;
static tSSD SSD_counter = 0;

typedef struct
{
    tSSD ssd_name;
    tSSD_Symbol ssd_symbol;
}tDisplay_SSD_Info;

static tDisplay_SSD_Info display_ssd_info[4];

void Display_Init(tSSD ssd, tLCD_Mode mode)
{
    SSD_Init(ssd);//SSD_ALL
    LCD_Init(mode);
}

void Display_Update_SSD(tSSD ssd,tSSD_Symbol ssd_symbol)
{
    //count down real human time if timer is active else display 00.00 while toggling . every second

    //
    SSD_Write_Symbol(ssd, ssd_symbol);
}
void Display_Update_LCD(U8* str, U8 line,U8 Column)
{
        SSD_Disable();
        LCD_Clear_Screen();
        LCD_GoTo(line,Column);
        LCD_Write_String(str);
        SSD_Enable();
}
void Display_Task(void)
{
    //dummy values
    display_ssd_info[0].ssd_symbol = SSD_Symbol_0;
    display_ssd_info[1].ssd_symbol = SSD_Symbol_0;
    display_ssd_info[2].ssd_symbol = SSD_Symbol_0;
    display_ssd_info[3].ssd_symbol = SSD_Symbol_0;

    if (tick_counter_SSD != tick_SSD)
    {
        tick_counter_SSD++;
        return;
    }
    else
    {
        Display_Update_SSD(SSD_counter, display_ssd_info[SSD_counter].ssd_symbol);
        if (SSD_counter == 3)
        {
            SSD_counter = 0;
        }
        else
        {
            SSD_counter++;
        }
        tick_counter_SSD = 0;
    }

    if (tick_counter_LCD != tick_LCD)
    {
        tick_counter_LCD++;
        return;
    }
    else
    {
    Display_Update_LCD("  Motor Speed", 0,0);
    tick_counter_LCD = 0;
    }
}
