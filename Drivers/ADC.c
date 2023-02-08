/*
 * ADC.c
 *
 *  Created on: Apr 19, 2022
 *
 */


#include "_BIT_MATH.h"
#include "ADC.h"


void ADC_Init (void)
{
	// ADC Enable
	// Put the number of bit ////
	SET_BIT(ADCSRA_Reg,7);  

	// Prescaler Configuration as 128
	SET_BIT(ADCSRA_Reg,2);
	SET_BIT(ADCSRA_Reg,1);
	SET_BIT(ADCSRA_Reg,0);

	// Reference Voltage as AREF, Internal Vref turned off
	CLR_BIT(ADMUX_Reg,7);
	CLR_BIT(ADMUX_Reg,6);

	// ADC Data Rgith Adjustment
	CLR_BIT(ADMUX_Reg,5);
}

unsigned short int ADC_Read (unsigned char channel) 
{	
	// ADC Channel Selection
	channel &= 0x07;
	ADMUX_Reg &= 0xE0;
	ADMUX_Reg |= channel;

	// Start Single Conversion
	SET_BIT(ADCSRA_Reg,6);

	//wait for the conversion
	while(!(ADCSRA_Reg & (1<<4)));//check int

	//ADC Flag Clear
	CLR_BIT(ADCSRA_Reg,4);
	
	//////Put the shifting code to store resolution value ////////
	unsigned short int result = 0;
	unsigned short int L = ADCL_Reg & 0x00FF;
	unsigned short int M = ADCH_Reg & 0x0003;
	result = L | (M<<8);

	return result;
}
