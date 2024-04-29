#include <stdint.h>

extern volatile int_least8_t encoder_direction;
extern volatile int_least8_t encoder_button_event;

void EXTI7_0_IRQHandler( void ) __attribute__( ( interrupt ) );