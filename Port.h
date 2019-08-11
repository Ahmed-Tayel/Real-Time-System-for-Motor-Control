#ifndef __PORT_H__
#define __PORT_H__

#include "Main.h"


/* Leds' pins */

#define LED_4_PORT_DR   (GPIO_PORTB_DATA)
#define LED_4_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_4_PIN       (GPIO_PIN_3)

/* Fill missing code below */
/* Switches */
#define SW_PLUS_PORT_DR     (GPIO_PORTB_DATA)
#define SW_PLUS_PORT_CR     (GPIO_PORTB_CONTROL)
#define SW_PLUS_PIN         (GPIO_PIN_0)

#define SW_MINUS_PORT_DR    (GPIO_PORTB_DATA)
#define SW_MINUS_PORT_CR    (GPIO_PORTB_CONTROL)
#define SW_MINUS_PIN        (GPIO_PIN_1)

#define SW_SET_PORT_DR      (GPIO_PORTB_DATA)
#define SW_SET_PORT_CR      (GPIO_PORTB_CONTROL)
#define SW_SET_PIN          (GPIO_PIN_2)

/* SSD */
#define SSD_DATA_PORT_DR        (GPIO_PORTD_DATA)
#define SSD_DATA_PORT_CR        (GPIO_PORTD_CONTROL)

#define SSD_LOW_DR       (GPIO_PORTB_DATA)
#define SSD_LOW_CR       (GPIO_PORTB_CONTROL)
#define SSD_LOW_PIN      (GPIO_PIN_7)

#define SSD_MID_DR      (GPIO_PORTB_DATA)
#define SSD_MID_CR      (GPIO_PORTB_CONTROL)
#define SSD_MID_PIN     (GPIO_PIN_6)

#define SSD_HIGH_DR     (GPIO_PORTB_DATA)
#define SSD_HIGH_CR     (GPIO_PORTB_CONTROL)
#define SSD_HIGH_PIN    (GPIO_PIN_5)

#endif // __PORT_H__
