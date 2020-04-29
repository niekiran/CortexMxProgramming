#include <stdint.h>
#include "stm32f407xx.h"

/* offest of the AHB1ENR register from RCC block */
#define RCC_AHB1ENR_OFFSET         0x30

/* Base address of the RCC.. we got this address by looking into memory map */
#define RCC_BASE_ADDR              (0x40023800)

/* actual address of the RCC_AHB1ENR Register */
#define RCC_AHB1ENR_ADDR            *((volatile unsigned long *)(RCC_BASE_ADDR + RCC_AHB1ENR_OFFSET) )

#define GPIOD_MODER_OFFSET        0X00

#define BASE_ADDR_GPIOD           (0x40020C00)

#define GPIOD_MODER                *((volatile unsigned long *)(BASE_ADDR_GPIOD + GPIOD_MODER_OFFSET))
	
#define OFFSET_OF_OUTPU_DATA_REG 0X14
#define GPIOD_OPDATAREG      *( (volatile unsigned long *)(BASE_ADDR_GPIOD+OFFSET_OF_OUTPU_DATA_REG))

#define OFFSET_OF_INPUT_DATA_REG 0X10
#define GPIOD_IPDATAREG      *( (volatile unsigned long *)(BASE_ADDR_GPIOD+OFFSET_OF_INPUT_DATA_REG))

void toggle_led(void)
{
	
	if(GPIOD_IPDATAREG & (1<<12) )
	{
		//LED IS on , turn if off 
		GPIOD_OPDATAREG &= ~(1<<12);
	}else
	{
		GPIOD_OPDATAREG |= (1<<12);
	}
}

int main(void)
{
	uint32_t i=0;
	/* 1. Enable the clock for GPIOD port */
	RCC_AHB1ENR_ADDR |= (1<<3);//bit 3 enables the clock for the GPIOD port
	
	/* 2. Configure the GPIO PIN to output mode using MODE register  */
	
	GPIOD_MODER |= (1 << (12 * 2)); //set 24th bit and 25 bit to 0x01 to make 12pin output
	
	/* 3. use the DATA REGISTER of GPIOD port to write to or read from LED */
	
	GPIOD_OPDATAREG |= (1<<12);//turn the led4 on. remember led 4 is connected to GPIOD PIN 12
	
	while(1)
	{
		toggle_led();
		for(i=0;i<500000;i++);
		toggle_led();
		for(i=0;i<500000;i++);
	}
	
	return 0;
}