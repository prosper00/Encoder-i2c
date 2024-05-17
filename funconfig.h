#ifndef _FUNCONFIG_H
#define _FUNCONFIG_H

#define CH32V003 1


/*****************************************************************************
    CH32V003 Fun Configs:

#define FUNCONF_USE_PLL 1               // Use built-in 2x PLL
#define FUNCONF_USE_HSI 1               // Use HSI Internal Oscillator
#define FUNCONF_USE_HSE 0               // Use External Oscillator
#define FUNCONF_HSITRIM 0x10            // Use factory calibration on HSI Trim.
#define FUNCONF_SYSTEM_CORE_CLOCK 48000000  // Computed Clock in Hz (Default only for 003, other chips have other
defaults)
#define FUNCONF_HSE_BYPASS 0            // Use HSE Bypass feature (for oscillator input)
#define
FUNCONF_USE_CLK_SEC	1			// Use clock security system, enabled by default
#define FUNCONF_USE_DEBUGPRINTF 1
#define FUNCONF_USE_UARTPRINTF  0
#define FUNCONF_NULL_PRINTF 0           // Have printf but direct it "nowhere"
#define FUNCONF_SYSTICK_USE_HCLK 0      // Should systick be at 48 MHz or 6MHz?
#define FUNCONF_TINYVECTOR 0            // If enabled, Does not allow normal interrupts.
#define FUNCONF_UART_PRINTF_BAUD 115200 // Only used if FUNCONF_USE_UARTPRINTF is set.
#define FUNCONF_DEBUGPRINTF_TIMEOUT 160000 // Arbitrary time units
*/

#define FUNCONF_USE_PLL 0
#define FUNCONF_SYSTEM_CORE_CLOCK 24000000
#define FUNCONF_NULL_PRINTF 0


#define BREAKPT() __asm( "C.EBREAK" ) // software breakpoint

#define AFIO_EXTICR_EXTI0 ( (uint16_t)0x0003 ) /* EXTI 0 configuration */
#define AFIO_EXTICR_EXTI1 ( (uint16_t)0x000C ) /* EXTI 1 configuration */
#define AFIO_EXTICR_EXTI2 ( (uint16_t)0x0030 ) /* EXTI 2 configuration */
#define AFIO_EXTICR_EXTI3 ( (uint16_t)0x00C0 ) /* EXTI 3 configuration */
#define AFIO_EXTICR_EXTI4 ( (uint16_t)0x0300 ) /* EXTI 4 configuration */
#define AFIO_EXTICR_EXTI5 ( (uint16_t)0x0C00 ) /* EXTI 5 configuration */
#define AFIO_EXTICR_EXTI6 ( (uint16_t)0x3000 ) /* EXTI 6 configuration */
#define AFIO_EXTICR_EXTI7 ( (uint16_t)0xC000 ) /* EXTI 7 configuration */

#define AFIO_EXTICR_EXTI0_PC ( (uint16_t)0x0002 ) /* PC[0] pin */
#define AFIO_EXTICR_EXTI0_PD ( (uint16_t)0x0003 ) /* PD[0] pin */
#define AFIO_EXTICR_EXTI1_PA ( (uint16_t)0x0000 ) /* PA[1] pin */
#define AFIO_EXTICR_EXTI1_PC ( (uint16_t)0x0008 ) /* PC[1] pin */
#define AFIO_EXTICR_EXTI1_PD ( (uint16_t)0x000C ) /* PD[1] pin */
#define AFIO_EXTICR_EXTI2_PA ( (uint16_t)0x0000 ) /* PA[2] pin */
#define AFIO_EXTICR_EXTI2_PC ( (uint16_t)0x0020 ) /* PC[2] pin */
#define AFIO_EXTICR_EXTI2_PD ( (uint16_t)0x0030 ) /* PD[2] pin */
#define AFIO_EXTICR_EXTI3_PC ( (uint16_t)0x0080 ) /* PC[3] pin */
#define AFIO_EXTICR_EXTI3_PD ( (uint16_t)0x00C0 ) /* PD[3] pin */
#define AFIO_EXTICR_EXTI4_PC ( (uint16_t)0x0200 ) /* PC[4] pin */
#define AFIO_EXTICR_EXTI4_PD ( (uint16_t)0x0300 ) /* PD[4] pin */
#define AFIO_EXTICR_EXTI5_PC ( (uint16_t)0x0800 ) /* PC[5] pin */
#define AFIO_EXTICR_EXTI5_PD ( (uint16_t)0x0C00 ) /* PD[5] pin */
#define AFIO_EXTICR_EXTI6_PC ( (uint16_t)0x2000 ) /* PC[6] pin */
#define AFIO_EXTICR_EXTI6_PD ( (uint16_t)0x3000 ) /* PD[6] pin */
#define AFIO_EXTICR_EXTI7_PC ( (uint16_t)0x8000 ) /* PC[7] pin */
#define AFIO_EXTICR_EXTI7_PD ( (uint16_t)0xC000 ) /* PD[7] pin */


#endif
