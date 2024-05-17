/* Template app on which you can build your own. */
// #pragma GCC optimize( "O3" )

#define I2C_CLKRATE 400000
#define CH32V003_I2C_IMPLEMENTATION
#define I2C_MODE_IRQ // if using the interrrupt based driver

#include "ch32v003fun.h"
#include "i2c.h"
#include <stdio.h>


int main( void )
{
	uint8_t read_buff[2];

	SystemInit();
	i2c_init();

	while ( 1 )
	{
		Delay_Ms( 1000 );

		/* if the read fails or times out, then reset the i2c bus */
		if ( ( i2c_read( 0x9, read_buff, 2 ) ) ) i2c_setup();

		printf( "got: %2x %2x \n", read_buff[0], read_buff[1] );
	}
}
