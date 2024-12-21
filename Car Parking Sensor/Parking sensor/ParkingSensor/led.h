/*
 * led.h
 *
 *  Created on: Oct 5, 2024
 *      Author: MOH
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"
typedef enum {
    LED_RED ,
    LED_GREEN,
    LED_BLUE
} LED_ID;

#define RED_LED_PORT_ID PORTC_ID
#define BLUE_LED_PORT_ID PORTC_ID
#define GREEN_LED_PORT_ID PORTC_ID

#define RED_LED_PIN_ID PIN0_ID
#define BLUE_LED_PIN_ID PIN2_ID
#define GREEN_LED_PIN_ID PIN1_ID

#define LED_ON LOGIC_HIGH
#define LED_OFF LOGIC_LOW

void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);


#endif /* LED_H_ */
