#include "Timer1.h"

/* Public Timer1 Functions */
void Timer1_Init(tTMR1_Prescaler_Value prescale_value)
{
    prescale_value=0;
}
void Timer1_Set_Start_value(U8 value)
{
    value=0;
}
void Timer1_Start(void)
{
    ;
}
void Timer1_Stop(void)
{
    ;
}
/* Public Timer1 Additional Functions */
void Timer1_Start_Timeout(const U16 timeout_ms)
{
    if(timeout_ms);
}
U8 Timer1_Check_Timeout(void)
{
    return 0;
}
void Timer1_Stop_Timeout(void)
{
    ;
}

U16 Timer1_Calculate_Execution_Time_US(void)
{
    return 0;
}

