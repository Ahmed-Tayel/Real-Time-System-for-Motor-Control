#include "Led.h"
#include "Main.h"
#include "Port.h"

void Led_init(void){
    GPIO_InitPortPin(LED_4_PORT_CR,LED_4_PIN,GPIO_OUT);
    GPIO_WritePortPin(LED_4_PORT_DR,LED_4_PIN,LED_LOW);
}



void Led_SET(tByte Led_state){
    GPIO_WritePortPin(LED_4_PORT_DR,LED_4_PIN,Led_state);
}
