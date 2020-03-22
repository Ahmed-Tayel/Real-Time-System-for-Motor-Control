#ifndef MOTOR_MODULE
#define MOTOR_MODULE

#include "Main.h"

#define START_UP_SPEED_ANGLE        (170)
#define LOW_SPEED_ANGLE             (140)
#define MID_SPEED_ANGLE             (90)
#define HIGH_SPEED_ANGLE            (10)
#define MOTOR_TICK_MS               (10)
#define SOFT_SWITCH_TIME            (40)
#define SOFT_SWITCH_SHIFT           (10)
#define HARMONICS_TIME              (20)
#define HARMONICS_SHIFT             (10)

typedef enum{
    soft_switch =0,
    harmonics
} t_motor_state;

typedef struct{
    t_motor_state state;
    tWord Current_Alpha;
    tWord Desired_Alpha;
} Motor_Condition;


void Motor_init(void);
void Motor_update(void);
static void Motor_fire(tByte);
void Motor_Set_Alpha(tWord);




#endif // MOTOR_MODULE
