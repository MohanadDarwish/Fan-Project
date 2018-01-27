#ifndef _SSD_H_
#define _SSD_H_

#include "Port.h"

#define SYMBOLS_MAX_NUMBER 12

typedef enum{
    SSD_Hrs_Tens,       //SSD1
    SSD_Hrs_Units,      //SSD2
    SSD_Min_Tens,       //SSD3
    SSD_Min_Units,      //SSD4
    SSD_ALL             //ALL SSD
}tSSD;

typedef enum{
    SSD_OFF,
    SSD_ON
}tSSD_State;

typedef enum{
    SSD_Symbol_0,
    SSD_Symbol_1,
    SSD_Symbol_2,
    SSD_Symbol_3,
    SSD_Symbol_4,
    SSD_Symbol_5,
    SSD_Symbol_6,
    SSD_Symbol_7,
    SSD_Symbol_8,
    SSD_Symbol_9,
    SSD_Symbol_dot,
    SSD_Symbol_Null
}tSSD_Symbol;

void SSD_Init(tSSD ssd);
void SSD_Disable(void);
void SSD_Enable(void);
void SSD_Write_Symbol(tSSD ,tSSD_Symbol);


#endif // _SSD_H_
