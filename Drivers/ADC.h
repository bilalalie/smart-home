/*
 * ADC.h
 *
 *  Created on: Apr 19, 2022
 *      Author: Barhoom
 */

#ifndef ADC_H_
#define ADC_H_

//////// Put addresses here ////////////////

#define ADMUX_Reg 	*((volatile unsigned char*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile unsigned char*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile unsigned char*)0x25) 		// ADC High Register
#define ADCL_Reg 	*((volatile unsigned char*)0x24) 		// ADC Low Register


extern void ADC_Init (void); // ADC Initialization And Enable
extern unsigned short int ADC_Read (unsigned char); // Read From The ADC Channel

#endif /* ADC_H_ */

/*

*/