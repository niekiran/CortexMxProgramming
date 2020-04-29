/*
Write a  program to PUSH the contents of R0,R1,R2 Registers 
using MSP as a stack pointer, and then POP the contents back  using PSP as a stack pointer 
*/

#include <stdint.h>
#include "stm32f407xx.h"

extern void do_stack_operations(void);
int  main()
{
	/* This function is implemeted in Assembly */
	do_stack_operations();
	return 0;
}