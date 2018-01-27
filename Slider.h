#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "Port.h"
#include "ADC.h"


void Slider_Init(void);
U16  Slider_Get_Value(void);
void Slider_Task(void);

#endif // _SLIDER_H_
