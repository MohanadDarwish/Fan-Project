#ifndef _SEOS_H_
#define _SEOS_H_

#include "Port.h"
#include "Timer0.h"

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

void sEOS_Init(void);

void sEOS_IRQ_Handler(void) __interrupt 0 ;/* ISR @  vector 0 */


#endif // _SEOS_H_
