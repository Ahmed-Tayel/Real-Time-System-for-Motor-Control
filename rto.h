#ifndef RTO_1
#define RTO_1
#include "Main.h"

typedef enum {
    Paused = 0,
    Running
} t_state;

typedef struct{
    t_state state;
    tWord delay;
    tWord period;
    void (*fptr)(void);
} Task;

void RTO_init(void);
void RTO_create_task(Task * tptr, tByte prio);
void RTO_set_task_values(tByte prio, tWord period, t_state state, void(*fptr)(void));
void RTO_scheduler_update(void);
void RTO_start_scheduler(void);

#endif // RTO_1
