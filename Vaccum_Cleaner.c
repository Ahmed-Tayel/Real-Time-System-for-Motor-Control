#include "Vaccum_Cleaner.h"
#include "Timer.h"
#include "Main.h"
#include "Display.h"
#include "SW.h"
#include "Motor.h"
#include "Led.h"

static tWord current_speed;
static Operation_Condition O1;

void Vaccum_Cleaner_init(void){
    current_speed = SPEED_MID;
    O1.OPER = NORMAL_OPERATION;
    O1.sensor_read = SENSOR_INACTIVE;
}

void Vaccum_Cleaner_update(void){
    tWord sw1_status = SW_RELEASED;
    tWord sw2_status = SW_RELEASED;
    tWord sensor_button = SW_RELEASED;
    static tByte Led_status = LED_LOW;
    static tWord v_counter=0;
    static tWord c_counter=0;
    v_counter += TMR_TICK_MS;
    if (v_counter != Vaccum_TICK){
        return;
    }
    v_counter = 0;

    sensor_button = SW_GetState(SW_SET);
    if (sensor_button == SW_PRE_PRESSED){
            switch (Led_status){
                case (LED_HIGH): Led_status = LED_LOW; O1.sensor_read = SENSOR_INACTIVE; break;
                case (LED_LOW) : Led_status = LED_HIGH; O1.sensor_read = SENSOR_ACTIVE; break;
            }
        }
    Led_SET(Led_status);

    switch(O1.OPER){
        case (NORMAL_OPERATION):
            if (O1.sensor_read == SENSOR_ACTIVE)
                O1.OPER = CRITICAL_OPERATION;
            else{
                sw1_status = SW_GetState(SW_MINUS);
                if (sw1_status == SW_PRE_PRESSED){
                        if (current_speed != SPEED_LOW)
                            current_speed --;
                }
                else{
                    sw2_status = SW_GetState(SW_PLUS);
                    if (sw2_status == SW_PRE_PRESSED){
                        if (current_speed != SPEED_HIGH)
                            current_speed ++;
                    }
                }
            }
            break;

        case (CRITICAL_OPERATION):
            if (O1.sensor_read == SENSOR_INACTIVE)
                O1.OPER = NORMAL_OPERATION;
            else
            {
                sw1_status = SW_GetState(SW_MINUS);
                if (sw1_status == SW_PRE_PRESSED)
                {
                    if (current_speed != SPEED_LOW)
                        current_speed -- ;
                }

                    c_counter += TMR_TICK_MS;
                   if (c_counter == CRITICAL_TIME)
                        {
                        switch(current_speed){
                        case SPEED_HIGH: current_speed = SPEED_MID; break;
                        case SPEED_MID:  current_speed = SPEED_LOW; break;
                        }
                        c_counter = 0;
                        }

            }
                    break;

            }

            DISP_SPEED(current_speed);
            Motor_Set_Alpha(current_speed);
}
