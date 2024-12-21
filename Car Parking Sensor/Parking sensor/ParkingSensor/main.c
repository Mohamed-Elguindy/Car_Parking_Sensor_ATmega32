/*
 * main.c
 *
 *  Created on: Oct 11, 2024
 *      Author: MOH
 */
#include "icu.h"
#include "Ultrasonic.h"
#include "led.h"
#include "buzzer.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"
uint16 distance;
void display(void) {
	LCD_moveCursor(0, 0);
	LCD_displayString("Distance=");
	LCD_moveCursor(0, 9);

	LCD_intgerToString(distance);

	if(distance < 100)
	{
		LCD_displayCharacter(' ');
	}

	LCD_moveCursor(1, 6);

	if(distance <= 5)
	{
		LCD_displayString("STOP");
	}
	else
	{
		LCD_displayString("    ");
	}
	LCD_moveCursor(0, 12);
	LCD_displayString("CM");

}


void buzzerled(void){
	if(distance<=5){
		LED_on(LED_RED);
		LED_on(LED_GREEN);
		LED_on(LED_BLUE);
		Buzzer_on();
		_delay_ms(500);
		LED_off(LED_RED);
		LED_off(LED_GREEN);
		LED_off(LED_BLUE);
		Buzzer_off();
		_delay_ms(500);
	}
	else if(distance>=6&&distance<=10){
		LED_on(LED_RED);
		LED_on(LED_GREEN);
		LED_on(LED_BLUE);
		Buzzer_off();
	}
	else if(distance>=11&&distance<=15){
		LED_on(LED_RED);
		LED_on(LED_GREEN);
		LED_off(LED_BLUE);
		Buzzer_off();
	}
	else if(distance>=16&&distance<=20){
		LED_on(LED_RED);
		LED_off(LED_GREEN);
		LED_off(LED_BLUE);
		Buzzer_off();
	}
	else if(distance>20){
		LED_off(LED_RED);
		LED_off(LED_GREEN);
		LED_off(LED_BLUE);
		Buzzer_off();
	}
}

int main(void){
	Ultrasonic_init();
	LCD_init();
	LEDS_init();
	Buzzer_init();

	while(1){
		sei();
		distance = Ultrasonic_readDistance();
		buzzerled();
		display();
	}
}
