#ifndef     _SW_H_
#define     _SW_H_

#include "Port.h"

#define SW_BOUNCING_TIME_MS       (20)
#define SW_SAMPLE_TIME_MS         (30)


#if SW_SAMPLE_TIME_MS < SW_BOUNCING_TIME_MS
#warning "Sampling time must be Greater than Bouncing time"
#endif

typedef enum
{
    SW_Released,    //0
    SW_Pre_Pressed, //1
    SW_Pressed,     //2
    SW_Pre_Released //3
}tSW_State;

typedef enum
{
    SW_Plus,    //0
    SW_Minus,    //1
    SW_Timer,   //2
    SW_Display //3
}tSW_Name;


void SW_Init (tSW_Name);
tSW_State SW_Get_State (tSW_Name name);
void SW_Set_State (tSW_Name name ,tSW_State state);
void SW_Update(tSW_Name name);
void SW_Task(void);

#endif // _SW_H_
