
extern void SystemInit(void);
extern int __main(void);

int main(void)
{
	
	return 0;
	
}

void Reset_Handler(void)
{
	SystemInit();
	__main();
	
}