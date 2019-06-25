
#include <stdint.h>
#include "stm32f407xx.h"

/* This application explains how  to get started with using CMSIS core APIs. The Code demonstrates 
setting up using CMSIS environemnt with headerfile and its core APIS to read/modify/write some of 
the system registers */


int main()
{
	uint32_t val;

	__set_PRIMASK(1);
	val = __get_PRIMASK();

		__set_FAULTMASK(1);
	val = __get_FAULTMASK();
	
		__set_BASEPRI(0x80);
	val = __get_BASEPRI();

	val = __get_MSP();
	__set_MSP(val+4);

	val = __get_PSP();
	__set_PSP(val+4);
	

	return 0;
	
}