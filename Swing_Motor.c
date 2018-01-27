#include "Swing_Motor.h"

static void Swing_Motor_Set_Swinging_Angle(tSwing_Motor_Angle);
static U8 Swinging_Angle;

//initializing the motor control signal pins direction(output) and setting the intial swing angle(0 degrees)
void Swing_Motor_Init(void)
{
    //Initializing the 4 pins for the swing motor as output to single the swing motor
    GPIO_InitPortPin(SWING_MOTOR_PORT_CR,SWING_MOTOR_CONTROL_SIGNAL_BIT_0,GPIO_OUT);//pin0
    GPIO_InitPortPin(SWING_MOTOR_PORT_CR,SWING_MOTOR_CONTROL_SIGNAL_BIT_1,GPIO_OUT);//pin1
    GPIO_InitPortPin(SWING_MOTOR_PORT_CR,SWING_MOTOR_CONTROL_SIGNAL_BIT_2,GPIO_OUT);//pin2
    GPIO_InitPortPin(SWING_MOTOR_PORT_CR,SWING_MOTOR_CONTROL_SIGNAL_BIT_3,GPIO_OUT);//pin3
    //initially the Swing Motor angle 0 degrees initially
    Swinging_Angle = Swing_Motor_0_Degrees;
}

//setting/changing the angle of swinging of the swing motor as desired from the values 0,45,90,135,180,225,270,315,360
void Swing_Motor_Set_Swinging_Angle(tSwing_Motor_Angle angle)
{
    Swinging_Angle = angle;
}

//starting the swing motor P.S. the motor won't start swinging until this API is invoked
void Swing_Motor_Start(void)
{
    Swing_Motor_Set_Swinging_Angle(Swinging_Angle);
}

//stopping the swing motor P.S. the motor won't stop swinging until this API is invoked
void Swing_Motor_Stop(void)
{
    Swing_Motor_Set_Swinging_Angle(Swing_Motor_0_Degrees);
}

void Swing_Motor_Task(void)
{
    ;
}

