#include "osKernel.h"
#include "Board_LED.h"

#define QUANTA	10

uint32_t count0,count1,count2,i;

void Task0(void)
{
	while(1)
	{
		count0++;
	}
}


void Task1(void)
{
	while(1)
	{
		count1++;
	}
	
}


void Task2(void)
{
	while(1)
	{
		LED_Off(0); 
		for(i=0 ; i < 300000 ; i++ ){}
		LED_On(0);
		for(i=0 ; i < 300000 ; i++ ){}
		count2++;
	}
}


int main(void)
{
	LED_Initialize();
	LED_Off(0);
	osKernelInit();
	osKernelAddThreads(&Task0,&Task1,&Task2);
	osKernelLaunch(QUANTA);
}

