#ifndef _FUNCONFIG_H
#define _FUNCONFIG_H

#define CH32V003 1

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


#define GPIO_CFGLR_Pin0 ( 4 * 0 )
#define GPIO_CFGLR_Pin1 ( 4 * 1 )
#define GPIO_CFGLR_Pin2 ( 4 * 2 )
#define GPIO_CFGLR_Pin3 ( 4 * 3 )
#define GPIO_CFGLR_Pin4 ( 4 * 4 )
#define GPIO_CFGLR_Pin5 ( 4 * 5 )
#define GPIO_CFGLR_Pin6 ( 4 * 6 )
#define GPIO_CFGLR_Pin7 ( 4 * 7 )


#endif
