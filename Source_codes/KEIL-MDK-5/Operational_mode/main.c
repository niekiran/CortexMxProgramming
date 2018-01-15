
#include "stm32f407xx.h"

//we have to implement the watchdog interrupt handler 

void WWDG_IRQHandler(void)
{
	for(int i=0 ; i < 50 ; i++);
	
}

void generate_interrupt(void)
{
	//Lets simulate the watchdog interrupt
	NVIC_EnableIRQ(WWDG_IRQn);
	NVIC_SetPendingIRQ(WWDG_IRQn);
}

int main(void)
{
  	generate_interrupt();
  	while(1);
 	return 0;
}
