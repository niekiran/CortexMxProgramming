#include <stdint.h>
#include "stm32f407xx.h"
#include "led.h"
#include "my_board.h"


void button_init(void)
{
	/* Enable GPIOA clock */
	/* because BUTTON is connected to GPIOA */
	RCC->AHB1ENR |= 0x01;

	//set the mode 
	GPIOA->MODER &= ~0x3;
	GPIOA->PUPDR  &= ~0x3;

	//enable clock for RCC
	RCC->APB2ENR |= 0x00004000;

	//configure the interrupt 
	EXTI->IMR |= 0x01;
	//	EXTI->RTSR |= 0X01;
	EXTI->FTSR |= 0X01;

	//nvic configuration 
	NVIC->IP[EXTI0_IRQn] = 0x00;
	NVIC_EnableIRQ(EXTI0_IRQn);

}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{

	led_init();

	/* Configure EXTI Line0 (connected to PA0 pin) in interrupt mode */
	button_init();
	
	/* Infinite loop */
	while (1)
	{
	}
}

/* ISR for the button interrupt */
void EXTI0_IRQHandler(void)
{
	/* clear EXTI0 pending bit */
	if( (EXTI->PR & 0x01) )
	{
		EXTI->PR = 0x01;
	}

	led_toggle(LED_4);
	/*process only which is important and trigger the pendsv to 
	handle rest in the pendsv handler  */
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;
}


/* PendSV Exception handler */
void PendSV_Handler(void)
{
		// bottom half work can be done here. 
	 led_toggle(LED_3);
}



