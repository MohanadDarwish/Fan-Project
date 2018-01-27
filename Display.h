#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "Port.h"
#include "SSD.h"
#include "LCD.h"

void Display_Init (tSSD, tLCD_Mode);
void Display_Update_SSD(tSSD ssd,tSSD_Symbol ssd_symbol);
void Display_Update_LCD(U8 *ch, U8 line,U8 Column);
void Display_Task(void);

#endif // _DISPLAY_H_
