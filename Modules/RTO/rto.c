#include "rto.h"
#include "Timer.h"


#define TASK_NUM    (4)


static Task * T_arr[TASK_NUM];


void RTO_init(void){
    tByte i;
    TMR_Init();
    for(i=0;i<TASK_NUM;i++){
        T_arr[i] = (void *)0;
    }
}

void RTO_create_task(Task * tptr, tByte prio){
    T_arr[prio] = tptr;
    T_arr[prio] ->delay = 0;
}


void RTO_set_task_values(tByte prio,tWord period, t_state state, void(*fptr)(void)){
    T_arr[prio] -> period = period;
    T_arr[prio] -> fptr= fptr;
    T_arr[prio] ->state = state;
}

void RTO_scheduler_update(void){
    tByte i;
    for(i=0; i<TASK_NUM; i++){
        if(T_arr[i]->state == Running){
                T_arr[i]->delay += TMR_TICK_MS;
                if(T_arr[i] ->delay == T_arr[i]->period)
                {
                    T_arr[i] ->fptr();
                    T_arr[i] ->delay = 0;
                }
                else
                {
                    //DO Nothing
                }

        }
    }
}


void RTO_start_scheduler(void){
    TMR_Start();
}
