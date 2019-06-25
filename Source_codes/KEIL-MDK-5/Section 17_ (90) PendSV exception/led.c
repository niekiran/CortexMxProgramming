
#include "my_board.h"
#include "stm32f407xx.h"


void led_init()	
{
	
	RCC->AHB1ENR |= (0x08 );
	
	//configure LED_4 . YELLOW 
	GPIOD->MODER  |= (0x01 << (LED_4 * 2));
	GPIOD->OTYPER |= ( 0 << LED_4);
	GPIOD->PUPDR   |= (0x00 << (LED_4 * 2));
	GPIOD->OSPEEDR |= (0X00 << (LED_4 * 2));
	
		
	//configure LED_3 . SAFFRON  
	GPIOD->MODER  |= (0x01 << (LED_3 * 2));
	GPIOD->OTYPER |= ( 0 << LED_3);
	GPIOD->PUPDR   |= (0x00 << (LED_3 * 2));
	GPIOD->OSPEEDR |= (0X00 << (LED_3 * 2));
	
		
	//configure LED_5 . RED 
	GPIOD->MODER  |= (0x01 << (LED_5 * 2));
	GPIOD->OTYPER |= ( 0 << LED_5);
	GPIOD->PUPDR   |= (0x00 << (LED_5 * 2));
	GPIOD->OSPEEDR |= (0X00 << (LED_5 * 2));
	
		
	//configure LED_6 . BLUE 
	GPIOD->MODER  |= (0x01 << (LED_6 * 2));
	GPIOD->OTYPER |= ( 0 << LED_6);
	GPIOD->PUPDR   |= (0x00 << (LED_6 * 2));
	GPIOD->OSPEEDR |= (0X00 << (LED_6 * 2));
	
}


void led_on(uint8_t led_no)
{
	GPIOD->BSRR = ( 1 << led_no );
}

void led_off(uint8_t led_no)
{
	GPIOD->BSRR = ( 1 << (led_no+16) );
}


void led_toggle(uint8_t led_no)
{
	if(GPIOD->ODR & (1 << led_no) )
	{
		led_off(led_no);
	}else
	{
		led_on(led_no);
	}
	
}