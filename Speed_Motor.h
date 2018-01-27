#ifndef _SPEED_MOTOR_H_
#define _SPEED_MOTOR_H_

#include "Port.h"

//Speed Motor should be invoked from the Slider Task
#define SPEED_MOTOR_MAX_FIRING_ANGLE 10
#define SPEED_MOTOR_MID_FIRING_ANGLE 90
#define SPEED_MOTOR_MIN_FIRING_ANGLE 140
#define SPEED_MOTOR_INITIAL_FIRING_ANGLE 170
#define SPEED_MOTOR_STOP_FIRING_ANGLE 180

typedef enum{
    Speed_Motor_Max,
    Speed_Motor_Mid,
    Speed_Motor_Min,

}tSpeed_Motor_Speeds;


void Speed_Motor_Init(void);
void Speed_Motor_Start(void);
void Speed_Motor_Stop(void);
void Speed_Motor_Set_Speed(tSpeed_Motor_Speeds);

void Speed_Motor_TRIAC_Output_Pulse(void);

void Speed_Motor_Task(void);



#endif // _SPEED_MOTOR_H_
