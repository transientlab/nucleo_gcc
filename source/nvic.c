#include "stm32f303x8.h"
#include "nvic.h"
#include "ui.h"
#include <stdint.h>



uint32_t cycle;

/* ========================================================== */
/* Interrupts initialization */
void NVICInit(void) {
	/* Setting priorities and enabling IRQ */

	/* High priorities for conversion and processing */



	/* Low priorities for interface handling */
	/* Display refresh */
  	NVIC_SetPriority(TIM1_UP_TIM16_IRQn, 0xFE);
  	NVIC_EnableIRQ(TIM1_UP_TIM16_IRQn);
	/* Buttons handling */
  	// NVIC_SetPriority(EXTI3_IRQn, 0xFF);
  	// NVIC_EnableIRQ(EXTI3_IRQn);
  	// NVIC_SetPriority(EXTI9_5_IRQn, 0xFF);
  	// NVIC_EnableIRQ(EXTI9_5_IRQn);
}

/* ========================================================== */
/* Interrupts handlers */

void TIM1_UP_TIM16_IRQHandler(void) {
	if (cycle == 0) {
			GPIOB->BSRR = (0x00000008<<16);
			cycle = 1;
		}
		else {
			GPIOB->BSRR = (0x00000008);
			cycle = 0;
		}
	TIM16->SR &= ~(TIM_SR_UIF);
	NVIC_ClearPendingIRQ(TIM1_UP_TIM16_IRQn);
}

// void EXTI3_IRQHandler(void) {
// 	GPIOB->BSRR = (0x00000008);
// 	EXTI->PR = 0x8;
// 	NVIC_ClearPendingIRQ(EXTI3_IRQn);
// }

// void EXTI9_5_IRQHandler(void) {
// 	GPIOB->BSRR = (0x00000008);
// 	EXTI->PR = 0x80;
// 	NVIC_ClearPendingIRQ(EXTI9_5_IRQn);
// }


