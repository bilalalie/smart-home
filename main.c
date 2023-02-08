/*
 * ADC.h
 *
 *  Created on: Apr 19, 2022
 *      Author: Barhoom
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include "Drivers/ADC.h"

int main(void) {
	
	DDRB = 0xff; 
	ADC_Init();
	unsigned short int value_read;
	
	while(1) {
		value_read = ADC_Read(0); // reading analogue from PIN0
		
		if(value_read > 650) { // checking the status of PIN, if it is '1', turns on the LED 
			PORTB = 0x00; // Turning on the Relay
		}
		else { // checking the status of PIN, if it is '0', turns off the LED
			PORTB = 0x02;   // Turning off the Relay 
		}
	}
}