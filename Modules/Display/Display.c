#include "Main.h"
#include "SSD.h"
#include "Timer.h"
#include "Display.h"
#include "SW.h"


void DISP_Init(void)
{
        SSD_Init(SSD_LOW);
        SSD_Init(SSD_MID);
        SSD_Init(SSD_HIGH);

        SSD_SetValue(SSD_LOW, SSD_NULL);
        SSD_SetValue(SSD_MID,SSD_NULL);
        SSD_SetValue(SSD_HIGH, SSD_NULL);
}

void DISP_SPEED(t_SPEED spd){
    switch(spd){
    case SPEED_LOW:
        SSD_SetValue(SSD_LOW,SSD_d);
        SSD_SetValue(SSD_MID,SSD_NULL);
        SSD_SetValue(SSD_HIGH,SSD_NULL);
        break;
    case SPEED_MID:
        SSD_SetValue(SSD_LOW,SSD_d);
        SSD_SetValue(SSD_MID,SSD_2d);
        SSD_SetValue(SSD_HIGH,SSD_NULL);
        break;
    case SPEED_HIGH:
        SSD_SetValue(SSD_LOW,SSD_d);
        SSD_SetValue(SSD_MID,SSD_2d);
        SSD_SetValue(SSD_HIGH,SSD_3d);
        break;
    }
}
