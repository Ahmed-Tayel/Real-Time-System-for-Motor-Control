#include "Main.h"
#include "SW.h"
#include "Timer.h"
#include "Display.h"
#include "Vaccum_Cleaner.h"
#include "SSD.h"
#include "Led.h"
#include "rto.h"
#include "Motor.h"

tWord __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;
tByte flag = 0;

#define SSD_Task_period         (SSD_PERIOD_MS)
#define SSD_Task_prio           (1)

#define Motor_Task_period       (MOTOR_TICK_MS)
#define Motor_Task_prio         (0)

#define SW_Task_period          (SW_PERIOD_MS)
#define SW_Task_prio            (2)

#define Vacuum_Task_period      (Vaccum_TICK)
#define Vacuum_Task_prio        (3)

Task SSD_Task, Motor_Task, SW_Task, Vacuum_Task;


void main (void)
{
    /* Initialization */
    SW_Init();
    DISP_Init();
    Vaccum_Cleaner_init();
    Led_init();
    RTO_init();

    RTO_create_task(& SSD_Task, SSD_Task_prio);
    RTO_create_task(& Motor_Task, Motor_Task_prio);
    RTO_create_task(& SW_Task, SW_Task_prio);
    RTO_create_task(& Vacuum_Task, Vacuum_Task_prio);

    RTO_set_task_values(SSD_Task_prio,SSD_Task_period , Running , &SSD_Update);
    RTO_set_task_values(Motor_Task_prio,Motor_Task_period , Running , &Motor_update);
    RTO_set_task_values(SW_Task_prio,SW_Task_period , Running , &SW_Update);
    RTO_set_task_values(Vacuum_Task_prio,Vacuum_Task_period , Running , &Vaccum_Cleaner_update);

    RTO_start_scheduler();

    TRISC7 = 0;
    RC7 = 0;

    TRISC6 = 0;
    RC6 = 0;

    while (1)
    {
        /* Do nothing */
        while (flag == 0);

        flag = 0;

    }

}
