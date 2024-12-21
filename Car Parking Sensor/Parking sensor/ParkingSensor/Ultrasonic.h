/*
 * Ultrasonic.h
 *
 *  Created on: Oct 11, 2024
 *      Author: MOH
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#define TRIG_PORT_ID     PORTD_ID
#define TRIG_PIN_ID      PIN7_ID

void Ultrasonic_init(void);
uint16 Ultrasonic_readDistance(void);
void Ultrasonic_edgeProcessing(void);
void Ultrasonic_Trigger(void);

#endif /* ULTRASONIC_H_ */
