#include "Main.h"
#include "Timer.h"
#include "SW.h"
#include "Vaccum_Cleaner.h"
#include "Display.h"
#include "SSD.h"
#include "Motor.h"
#include "rto.h"


extern tByte flag;

void TMR_Init(void)
{
	TMR_SET_PRESCALER_256;
	TMR_DISABLE_CLOCK;
}
void TMR_Start(void)
{
	TMR_CLEAR_FLAG;
	TMR_UPDATE_REGISTER(TMR_TICK_MS);
	TMR_ENABLE_INTERRUPT;
	GLOBAL_INTERRUPT_ENABLE;
	TMR_ENABLE_CLOCK;
}
tByte TMR_CheckOverFlow(void)
{
	return TMR_GET_FLAG;
}
void TMR_Stop(void)
{
	TMR_DISABLE_CLOCK;
}

u8 TMR_Read_time(void){
    //This Function is designed for 10 ms Tick
    u8 time;
    time = (256 - TMR0)/8;
    return (10-time);
}

void TMR_Update(void) __interrupt 0
{
	TMR_CLEAR_FLAG;
	TMR_UPDATE_REGISTER(TMR_TICK_MS);
    RC7 = 1 ^ RC7;
    RTO_scheduler_update();
}
