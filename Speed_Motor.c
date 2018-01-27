#include "Speed_Motor.h"

static void Speed_Motor_Set_Firing_Angle(U8 angle);
static U8 Firing_Angle = 180;
static U8 Desired_Angle = 180;

void Speed_Motor_Init(void)
{
    //configure speed motor (triac pin)
    GPIO_InitPortPin(SPEED_MOTOR_TRIAC_CR,SPEED_MOTOR_TRIAC_PIN,GPIO_OUT);

    //initially the AC Motor speed is at 170degree from the sine wave
    Speed_Motor_Set_Firing_Angle(SPEED_MOTOR_INITIAL_FIRING_ANGLE);
}

void Speed_Motor_Start(void)
{
    Speed_Motor_Set_Firing_Angle(SPEED_MOTOR_MIN_FIRING_ANGLE);
}

void Speed_Motor_Stop(void)
{
    //stopping the ac motor
    Speed_Motor_Set_Firing_Angle(SPEED_MOTOR_STOP_FIRING_ANGLE);
}
void Speed_Motor_Set_Speed(tSpeed_Motor_Speeds speed)
{
    switch(speed)
    {
        case Speed_Motor_Max:
            //set speed motor's speed to MAX
            Speed_Motor_Set_Firing_Angle(SPEED_MOTOR_MAX_FIRING_ANGLE);
            break;
        case Speed_Motor_Mid:
            //set speed motor's speed to MID
            Speed_Motor_Set_Firing_Angle(SPEED_MOTOR_MID_FIRING_ANGLE);
            break;
        case Speed_Motor_Min:
            //set speed motor's speed to MIN
            Speed_Motor_Set_Firing_Angle(SPEED_MOTOR_MIN_FIRING_ANGLE);
            break;
    }

}
//private function
static void Speed_Motor_Set_Firing_Angle(U8 angle)//called every 80ms
{
    Desired_Angle= angle;
    //difference betweeen desired angle and current
    if(Firing_Angle > angle)
    {
        Firing_Angle--;
        //output triac pule of 100us at corresponding Firing angle
    }
    else if(Firing_Angle < angle)
    {
        Firing_Angle++;
        //output triac pule of 100us at corresponding Firing angle
    }
    else
    {
        Firing_Angle = angle;
        //output triac pule of 100us at corresponding Firing angle

    }
}

void Speed_Motor_TRIAC_Output_Pulse(void)
{

    //1 triac pin
    GPIO_WritePortPin(SPEED_MOTOR_TRIAC_DR, SPEED_MOTOR_TRIAC_PIN,1);
    //wait 100us
    Delay_US(DELAY_100US);
    //0 traic pin
    GPIO_WritePortPin(SPEED_MOTOR_TRIAC_DR, SPEED_MOTOR_TRIAC_PIN,0);

}
void Speed_Motor_Task(void)
{

    ;
}
