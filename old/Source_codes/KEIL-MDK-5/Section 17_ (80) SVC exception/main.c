#include <stdio.h>
#include <stdint.h>

/*This is how you execute a SVC instruction in c
  compiler will replace this functin call by "svc 0x36" instruction */
int __svc(0x36) svc_service_add(int x , int y);

int  SVC_Handler_C(unsigned int *svc_args);

int result = 0;

int main(void)
{
	int x , y;

	x = 0x17, y =0x27;
	
	/* below line will be replaced by svc instruction */
	result = svc_service_add(x,y);

	while(1);
	
}



int SVC_Handler_C(unsigned int *svc_args)
{

	uint32_t svc_number;

	/* svc_args[6] will give address of next instruction after "svc 0x36" instruction 
	   (svc_args[6]- 2) will give the address of "svc 0x36" instruction 
	   so *( ((char *)(svc_args[6])) -2 ); will give the value of svc service number 
	*/
	svc_number = *( ((char *)(svc_args[6])) -2 );
	switch(svc_number)
	{
		case 0x36 :
			svc_args[0] = svc_args[0]+svc_args[1];
			break;
			
		case 0x37 :
			svc_args[0] = svc_args[0] * svc_args[1];
			break;

		default:
			break;
	}

	 
	return svc_args[0];
}




