#ifndef VACC_CLEAN
#define VACC_CLEAN

#define Vaccum_TICK         (20)
#define CRITICAL_TIME       (300)


typedef enum{
    NORMAL_OPERATION=0,
    CRITICAL_OPERATION
} t_Operation_State;

typedef enum{
    SENSOR_INACTIVE =0,
    SENSOR_ACTIVE
} t_sensor_status;

typedef struct{
    t_Operation_State OPER;
    t_sensor_status sensor_read;
} Operation_Condition;


void Vaccum_Cleaner_update(void);
void Vaccum_Cleaner_init(void);


#endif // VACC_CLEAN
