/*
 * Ultrasonic.c
 *
 *  Created on: Oct 11, 2024
 *      Author: MOH
 */
#include "common_macros.h"
#include "gpio.h"
#include "icu.h"
#include "Ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>

uint8 g_edgeCount = 0;
uint16 g_time ;

void Ultrasonic_init(void) {

	ICU_ConfigType ICU_Configurations = {F_CPU_8,RAISING};
	ICU_init(&ICU_Configurations);
	GPIO_setupPinDirection(TRIG_PORT_ID,TRIG_PIN_ID,PIN_OUTPUT);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
}
void Ultrasonic_Trigger(void){
	GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_HIGH);
    _delay_us(10);
	GPIO_writePin(TRIG_PORT_ID,TRIG_PIN_ID,LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void) {
	Ultrasonic_Trigger();
    return ((g_time * 10) / 1176)+1;
}
void Ultrasonic_edgeProcessing(void) {
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		g_time = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount=0;
	}

}
