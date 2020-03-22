#ifndef __DISPLAY_H__
#define __DISPLAY_H__

typedef enum {
SPEED_LOW = 0,
SPEED_MID,
SPEED_HIGH
} t_SPEED;


void DISP_Init(void);
void DISP_SPEED( t_SPEED );
#endif // __DISPLAY_H__
