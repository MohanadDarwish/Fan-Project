#ifndef _MAIN_H_
#define _MAIN_H_

#include <pic16f877a.h>

/* Standard data types */
typedef unsigned char   U8;
typedef unsigned short  U16;
typedef unsigned long   U32;
typedef char   S8;
typedef short  S16;
typedef long   S32;
typedef float  F32;

#include "Util.h"

/* DEBUGGINNG MACRO*/
#define _DEBUG  0
#define _ERROR  0

#if _DEBUG ==1
#define LCD_DEBUG(x,y,str)  LCD_Clear_Screen(); LCD_GoTo(x,y); LCD_Write_String(str)
#else
#define LCD_DEBUG(x,y,str)
#endif // _DEBUG

#if _ERROR ==1
#define LCD_ERROR(x,y,str)  LCD_Clear_Screen(); LCD_GoTo(x,y); LCD_Write_String(str)
#else
#define LCD_ERROR(x,y,str)
#endif // _ERROR

/* bit Levels */
#define HIGH_LEVEL     (1)
#define LOW_LEVEL      (0)


/* Interrupt Control */
#define GLOBAL_INTERRUPT_ENABLE() ((GIE) = 1)

#define GLOBAL_INTERRUPT_DISABLE() ((GIE) = 0)

#define PHERIPHERAL_INTERRUPT_ENABLE() ((PEIE) = 1)

#define PHERIPHERAL_INTERRUPT_DISABLE() ((PEIE) = 0)

/* GPIO definitions */

/* GPIO Pins */
#define GPIO_PIN_0                           (0)
#define GPIO_PIN_1                           (1)
#define GPIO_PIN_2                           (2)
#define GPIO_PIN_3                           (3)
#define GPIO_PIN_4                           (4)
#define GPIO_PIN_5                           (5)
#define GPIO_PIN_6                           (6)
#define GPIO_PIN_7                           (7)


/* GPIO Analog Pins */
#define GPIO_PIN_AN0                           (0)
#define GPIO_PIN_AN1                           (1)
#define GPIO_PIN_AN2                           (2)
#define GPIO_PIN_AN3                           (3)
#define GPIO_PIN_AN4                           (4)
#define GPIO_PIN_AN5                           (5)
#define GPIO_PIN_AN6                           (6)
#define GPIO_PIN_AN7                           (7)
#define GPIO_PIN_AN8                           (0)
#define GPIO_PIN_AN9                           (1)
#define GPIO_PIN_AN10                          (2)
#define GPIO_PIN_AN11                          (3)


/* GPIO Port Registers redefinition */
#define GPIO_PORTA_DATA                             (PORTA)
#define GPIO_PORTA_DIRECTION                        (TRISA)

#define GPIO_PORTB_DATA                             (PORTB)
#define GPIO_PORTB_DIRECTION                        (TRISB)

#define GPIO_PORTC_DATA                             (PORTC)
#define GPIO_PORTC_DIRECTION                        (TRISC)

#define GPIO_PORTD_DATA                             (PORTD)
#define GPIO_PORTD_DIRECTION                        (TRISD)

#define GPIO_PORTE_DATA                             (PORTE)
#define GPIO_PORTE_DIRECTION                        (TRISE)

#define GPIO_ANSEL                                  (ANSEL)
#define GPIO_ANSELH                                 (ANSELH)


/* GPIO direction setting */
#define GPIO_OUT                                    (0)
#define GPIO_IN                                     (1)

/* GPIO direction setting */

#define ADC_Set_Digital                                 (0)
#define ADC_Set_Analog                                  (1)

/* GPIO port operations */
#define GPIO_InitPort(CONTROL, DIRECTION)           (  (CONTROL) = (DIRECTION)?(~GPIO_OUT):(GPIO_OUT)  )
#define GPIO_WritePort(PORT, DATA)                  (  (PORT) = (DATA)  )
#define GPIO_ReadPort(PORT)                         (  PORT  )

/* GPIO port pin operations */
#define GPIO_InitPortPin(CONTROL, PIN, DIRECTION)   (  (CONTROL) = ( CONTROL & (~(1 << PIN)) ) | (DIRECTION << PIN)  )
#define GPIO_WritePortPin(PORT, PIN, DATA)          (  (PORT) = ( PORT & (~(1 << PIN)) ) | (DATA << PIN)  )
#define GPIO_ReadPortPin(PORT, PIN)                 (  ((PORT) & (1 << PIN)) >> (PIN)  )

///* GPIO Setting Analog Pins */
//
//#define GPIO_SetAnalog(REGESTER, PIN, SET)          (  (REGESTER) = ( REGESTER & (~(1 << PIN)) ) | (SET << PIN)  )
//#define GPIO_SetAnalog(REGESTER, SET)               (  (REGESTER) = (SET)  )






/*-------------------------------TIMER0------------------------------*/

/* Timer 0 macros */


//#define TMR_SET_PRESCALER_256	                    (??)
//
//#define TMR_GET_FLAG			                    (??)
//#define TMR_CLEAR_FLAG	                        (??)
//
//#define TMR_UPDATE_REGISTER(TIME)		            (??)
//
//#define TMR_ENABLE_INTERRUPT	                    (??)
//#define GLOBAL_INTERRUPT_ENABLE 	                (??)
//
//#define TMR_ENABLE_CLOCK		                    (??)
//#define TMR_DISABLE_CLOCK		                    (??)
//

#endif // _MAIN_H_
