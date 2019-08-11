#include "Motor.h"
#include "Display.h"
#include "Timer.h"

static Motor_Condition M1;

void Motor_init(void){
    M1.Current_Alpha = START_UP_SPEED_ANGLE;
    M1.Desired_Alpha = MID_SPEED_ANGLE;
    M1.state = soft_switch;
}

void Motor_Set_Alpha(tWord speed){
    switch(speed){
    case (SPEED_LOW):   M1.Desired_Alpha = LOW_SPEED_ANGLE; break;
    case (SPEED_MID):   M1.Desired_Alpha = MID_SPEED_ANGLE; break;
    case (SPEED_HIGH):  M1.Desired_Alpha = HIGH_SPEED_ANGLE; break;
    }
}

static void Motor_fire(tByte alpha){
    //This Function is designed for 10 ms Tick
    float time = alpha/18;
    RC6 = 0;
    while(TMR_Read_time() < time);
    RC6 = 1;
    while(TMR_Read_time() < (time + 0.1));
    RC6 = 0;
}

void Motor_update(void){
    static tWord soft_switch_count=0;
    static tWord harmonics_count=0;

    switch(M1.state){
    case (soft_switch):
        if((M1.Current_Alpha >= (M1.Desired_Alpha-HARMONICS_SHIFT)) && (M1.Current_Alpha <= (M1.Desired_Alpha+HARMONICS_SHIFT)))
            M1.state = harmonics;
        else{
            soft_switch_count += MOTOR_TICK_MS;
            if(soft_switch_count == SOFT_SWITCH_TIME){
                (M1.Current_Alpha > M1.Desired_Alpha)? (M1.Current_Alpha -= SOFT_SWITCH_SHIFT):(M1.Current_Alpha += SOFT_SWITCH_SHIFT);
                soft_switch_count = 0;
            }
            }
            break;
    case (harmonics):
        if (((M1.Current_Alpha) >= (M1.Desired_Alpha+HARMONICS_SHIFT)) || ((M1.Current_Alpha) <= (M1.Desired_Alpha-HARMONICS_SHIFT)))
            M1.state = soft_switch;
        else
        {
            harmonics_count += MOTOR_TICK_MS;
            if (harmonics_count == HARMONICS_TIME)
            {
                if (M1.Current_Alpha == M1.Desired_Alpha)
                    M1.Current_Alpha += HARMONICS_SHIFT;
                else if (M1.Current_Alpha > M1.Desired_Alpha)
                {
                    M1.Current_Alpha -= (2*HARMONICS_SHIFT);
                }
                else
                {
                    M1.Current_Alpha += (2*HARMONICS_SHIFT);
                }
                harmonics_count = 0;
            }
        }
        break;
    }
    Motor_fire(M1.Current_Alpha);
}
