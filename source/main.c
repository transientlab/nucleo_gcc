#include "main.h"
#include "ui.h"
#include "nvic.h"
#include "system.h"



int main(void) {

  SystemInit();
  NVICInit();


  DAC->CR |=  DAC_CR_WAVE1_1;

  
  while(1) {

	 
  }
}



