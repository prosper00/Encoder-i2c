#include "exti_pin_change_isr.h"
#include "ch32v003fun.h"
#include <stdio.h>

volatile int_least8_t encoder_direction;
volatile int_least8_t encoder_button_event;

void EXTI7_0_IRQHandler( void )
{
	// check if EXT1 [rotation] fired:
	if ( EXTI->INTFR & EXTI_Line1 )
	{
		// read the OTHER (non EXTI) encoder pin
		if ( !( funDigitalRead( PA2 ) ) )
			encoder_direction--;
		else
			encoder_direction++;

		// Acknowledge the interrupt
		EXTI->INTFR |= EXTI_Line1;
	}

	// check if EXT4 [pushbutton] fired:
	if ( EXTI->INTFR & EXTI_Line4 )
	{
		encoder_button_event = 1;
		//  Acknowledge the interrupt
		EXTI->INTFR |= EXTI_Line4;
	}
}
