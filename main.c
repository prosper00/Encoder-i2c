/* Template app on which you can build your own. */
// #pragma GCC optimize( "O3" )

#include "ch32v003fun.h"
#include "exti_pin_change_isr.h"
#include "i2c_slave.h"
#include <stdio.h>

#define I2CADDR 0x09

// read and write buffers for i2c
// we are an i2c slave device, so a 'write' is INBOUND data (MOSI)
// and a 'read' is outbound data (MISO)
volatile uint8_t i2c_read_registers[2] = { 0x00 }; // [0] is the encoder rotation and [1] is the button status
volatile uint8_t i2c_write_registers[2] = { 0x00 }; // eventually, I'll use this to set LEDs

// callback function to handle i2c write requests
void onWrite( uint8_t reg, uint8_t length )
{
	// set LEDs on the board. Not implemented on the SOIC-8 device - insufficient pins
}

// callback function to handle i2c read requests
// called *after* the data is sent out
void onRead( uint8_t reg )
{
	i2c_read_registers[reg] = 0; // clear the buffers once it's been transmitted
	encoder_direction = 0; // clear the encoder data
	encoder_button_event = 0;
}

void i2c_Init( void )
{
	// Initialize I2C slave
	funPinMode( PC1, GPIO_CFGLR_OUT_10Mhz_AF_OD ); // SDA
	funPinMode( PC2, GPIO_CFGLR_OUT_10Mhz_AF_OD ); // SCL
	SetupI2CSlave( I2CADDR, i2c_read_registers, sizeof( i2c_read_registers ), i2c_write_registers,
		sizeof( i2c_write_registers ), onWrite, onRead, false );
}

void Exti_Init( void )
{
	// Assumes all encoder pins are externally pulled up.
	// PA1 and PA2 are encoder inputs
	funPinMode( PA1, GPIO_CFGLR_IN_FLOAT );
	funPinMode( PA2, GPIO_CFGLR_IN_FLOAT );

	// PC4 is encoder button
	funPinMode( PC4, GPIO_CFGLR_IN_FLOAT );

	// Configure the PA1 and PC4 as an interrupt.
	AFIO->EXTICR = ( AFIO_EXTICR1_EXTI1_PA | AFIO_EXTICR_EXTI4_PC );
	// Enable the interrupt channels
	EXTI->INTENR = ( EXTI_INTENR_MR1 | EXTI_INTENR_MR4 ); // Enable EXT line 1 and 4
	EXTI->FTENR = ( EXTI_FTENR_TR1 | EXTI_FTENR_TR4 ); // Falling edge trigger on channels/pins 1 and 4

	// enable interrupt
	NVIC_EnableIRQ( EXTI7_0_IRQn );
}

int main( void )
{
	SystemInit();
	funGpioInitAll();
	Exti_Init();
	i2c_Init();

	while ( 1 )
	{
		__WFI(); // halt until an event comes in
		Delay_Ms( 10 ); // wait a bit for data to come in
		// put the encoder data into the i2c queue to send
		i2c_read_registers[0] = encoder_direction; // signed / unsigned?
		i2c_read_registers[1] = encoder_button_event;
	}
}
