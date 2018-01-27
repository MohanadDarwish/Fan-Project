#include "SW.h"
//for debugging purposes
#include "LED.h"
#include "LCD.h"

#define SW_MAX_NUMBER         (4)
#define SW_MAX_STATE_NUMBER   (4)

//sys_tick = 56us 1-->178
static U8 tick_SW_Plus = 50;// 50*sys_tick
static U8 tick_SW_Minus = 50;//50*sys_tick
static U8 tick_SW_Display =100 ;//100*sys_tick
static U8 tick_SW_Timer = 100;// 100*sys_tick

static U8 tick_counter_SW_Plus    = 0;
static U8 tick_counter_SW_Minus   = 0;
static U8 tick_counter_SW_Display = 0;
static U8 tick_counter_SW_Timer   = 0;

typedef enum
{
    SW_Level_Low = 0,
    SW_Level_High,
}tSW_Level;

typedef struct
{
    tSW_Name  name;
    tSW_State current_state;//current state of the switch
    tSW_Level samples[3];
}SW_Info;

    static U8 sw_state_lookup_table[4][3]={  {1,0,0},//released
                                             {0,0,0},//pre-press
                                             {0,0,1},//press
                                             {0,1,1},//pre-released
                                             };

volatile static SW_Info sw_info[SW_MAX_NUMBER];

void SW_Init (tSW_Name sw_name)
{
            GPIO_InitPortPin(SW_TIMER_PORT_CR, SW_TIMER_PIN, GPIO_IN);
            sw_info[sw_name].samples[0] = SW_Level_High;
            sw_info[sw_name].samples[1] = SW_Level_High;
            sw_info[sw_name].samples[2] = SW_Level_High;
            //initial state
            sw_info[sw_name].current_state = SW_Released;
}

tSW_State SW_Get_State (tSW_Name sw_name )
{
    return sw_info[sw_name].current_state ;
}


void SW_Set_State (tSW_Name sw_name ,tSW_State state)
{

    sw_info[sw_name].current_state = state;

}

void SW_Update(tSW_Name sw_name)
{
    //////////////////////////////////////////////////////
    //current_state        | n-2 | n-1  | n | next_state//
    //--------------------------------------------------//
    //released     | 1   | x    | 0 | pre-pressed       //
    //pre-pressed  | x   | 0    | 0 | pressed           //
    //pressed      | 0   | x    | 1 | pre-released      //
    //pre-released | x   | 1    | 1 | released          //
    //////////////////////////////////////////////////////

    //shift the 3 old samples to the left adding the new sample to (n)
    sw_info[sw_name].samples[0] = sw_info[sw_name].samples[1] ;//left shifting to sample n-1
    sw_info[sw_name].samples[1] = sw_info[sw_name].samples[2] ;//left shifting to sample n

    //check for new sample "Acquire the new Sample from the GPIO_ReadPortPin(SW1_DR)
    sw_info[sw_name].samples[2] = GPIO_ReadPortPin(SW_TIMER_PORT_DR,SW_TIMER_PIN);

    //check if the current 3 samples matching the desired 3 samples corresponding to the current state from the Look Up Table

         if((sw_info[sw_name].current_state == SW_Released) || (sw_info[sw_name].current_state == SW_Pressed))
        {
            if(( sw_info[sw_name].samples[0] == sw_state_lookup_table[ sw_info[sw_name].current_state ][0] ) &&
                    (sw_info[sw_name].samples[2] ==  sw_state_lookup_table[ sw_info[sw_name].current_state ][2] ) )
            {
                //go to the next corresponding state to the current state
                //if True change state

                    SW_Set_State(sw_name,(sw_info[sw_name].current_state) +1); // updating state
                    if(sw_info[sw_name].current_state == SW_Pre_Pressed)
                    {
                        LCD_DEBUG(1,0,"SW_Pre_Pressed");//0,2
                    }else if(sw_info[sw_name].current_state == SW_Pre_Released)
                    {
                        LCD_DEBUG(1,0,"SW_Pre_Released");//0,2
                    }

            }
         }
         else if((sw_info[sw_name].current_state == SW_Pre_Released) || (sw_info[sw_name].current_state == SW_Pre_Pressed))
         {
            if(( sw_info[sw_name].samples[1] == sw_state_lookup_table[ sw_info[sw_name].current_state ][1] ) &&
                    (sw_info[sw_name].samples[2] ==  sw_state_lookup_table[ sw_info[sw_name].current_state ][2] ) )
            {
                //go to the next corresponding state to the current state
                //if True change state
                 if(sw_info[sw_name].current_state == 3)
                {
                    SW_Set_State(sw_name,SW_Released ); // updating state
                    LCD_DEBUG(1,0,"SW_Released");//1,3
                }
                else
                {
                    LCD_DEBUG(1,0,"SW_Pressed");//1,3
                    SW_Set_State(sw_name,(sw_info[sw_name].current_state) +1); // updating state
                }
            }
         }

    //else do nothing and go back to the calling function
    return;
}

//SW Task
void SW_Task(void)
{

//    if (tick_counter_SSD != tick_SSD)
//    {
//        tick_counter_SSD++;
//        return;
//    }
//    else
//    {
//        Display_Update_SSD(SSD_counter, display_ssd_info[SSD_counter].ssd_symbol);
//        if (SSD_counter == 3)
//        {
//            SSD_counter = 0;
//        }
//        else
//        {
//            SSD_counter++;
//        }
//        tick_counter_SSD = 0;
//    }
//
//    if (tick_counter_LCD != tick_LCD)
//    {
//        tick_counter_LCD++;
//        return;
//    }
//    else
//    {
//
//    tick_counter_LCD = 0;
//    }
//






    //code to keep track of switches and thier turn

    //looping intially (once)to set all thier default state
    //SW_Set_State(xyz,xyz);

    //looping on all switches to Update thier state
    //SW_Update(xyz,xyz);

    //Timer SW with its possible values 0hrs , 1hrs , 2hrs , 4hrs
    //Turning the Fan off after FAN Timer timeout
    //Speed_Motor_Stop();
    //Swing_Motor_Stop();

    //invoke the Buzzzer for 2 sec if a valid press detected or change in the swing value
//    Buzzer_ON();
    //TMR1_Delay( 2sec);
//    Buzzer_OFF();

    //controlling the speed of the fan max 10 degrees,mid 90 degrees,min 140 degrees
    //Speed_Motor_Soft_Speed_Switching(decreaseBy1Degree/increaseBy1Degree);



}

