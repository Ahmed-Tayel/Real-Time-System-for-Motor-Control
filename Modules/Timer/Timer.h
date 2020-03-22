#ifndef __TIMER_H__
#define __TIMER_H__
#include "Main.h"

#define TMR_INTERRUPT_ENABLE	    /* 0 --> Interrupts disabled */
									/* 1 --> Interrupts enabled */

#define TMR_TICK_MS				(10) /* HCF(P1, P2, ..., PN) */
typedef unsigned char u8;


void TMR_Init(void);
void TMR_Start(void);
tByte TMR_CheckOverFlow(void);
void TMR_Stop(void);

u8 TMR_Read_time(void);

void TMR_Update(void) __interrupt 0; /* ISR @  vector 0 */

#endif
