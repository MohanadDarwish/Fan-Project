#ifndef _TIMER1_H_
#define _TIMER1_H_

#include "Port.h"

typedef enum {
    Timer0_Prescaler_2  ,
    Timer0_Prescaler_4  ,
    Timer0_Prescaler_8  ,
    Timer0_Prescaler_16 ,
    Timer0_Prescaler_32 ,
    Timer0_Prescaler_64 ,
    Timer0_Prescaler_128,
    Timer0_Prescaler_265

}tTMR1_Prescaler_Value;


void Timer1_Init(tTMR1_Prescaler_Value prescale_value);
void Timer1_Set_Start_value(U8 value);
void Timer1_Start(void);
void Timer1_Stop(void);


void Timer1_Start_Timeout(const U16 timeout_ms);
U8 Timer1_Check_Timeout(void);
void Timer1_Stop_Timeout(void);

U16 Timer1_Calculate_Execution_Time_US(void);


#endif // _TIMER1_H_
