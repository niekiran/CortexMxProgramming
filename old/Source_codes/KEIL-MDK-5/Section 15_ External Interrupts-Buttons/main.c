#include <stdint.h>
#include <stdio.h>
#include "stm32f407xx.h"
#include "led.h"
#include "my_board.h"

void button_init(void);

void button_init(void)
{
	/*1. Enable GPIOA clock */
	/* because BUTTON is connected to GPIOA PIN0 */
	//RCC_AHB1ENR
	RCC->AHB1ENR |= 0X01; //Enables the clock
	

	/* 2. set the mode of GPIOA pin0 to "INPUT" */
	GPIOA->MODER &= ~0X03;


	
	/*3. set the interrupt triggering level */
	//(EXTI_FTSR
	EXTI->FTSR |= 0X01;	

	/*4. enable the interrupt over EXTI0 */
	EXTI->IMR |= 0X01;


	/*5. the interrupt on NVIC for IRQ6 */
  NVIC->ISER[0] |= ( 1 << EXTI0_IRQn);
	
}

int main()
{

	led_init();
	
	button_init();
	
	led_on(LED_4);
	led_on(LED_3);
	led_on(LED_5);
	led_on(LED_6);
	
	/*infinite loop */
	while(1)
	{
    
	}

	return 0;
}

void EXTI0_IRQHandler(void)
{
	/*clear the pending bit for exti0 */
		if( (EXTI->PR & 0x01) )
	{
		EXTI->PR = 0x01;//Writing 1 , clears the pending bit for exti0
	
	}
	led_toggle(LED_4);
	
}
