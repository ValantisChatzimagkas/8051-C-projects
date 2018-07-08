#include <reg51.h>

unsigned int data_in;//Contains our input data

void delay()//This function will cause 0,1 sec delay
{
	int counter = 0;
	
	while(counter++ < 2)
	{
		TMOD = 0x01;
		TH0 = 0x3C;
		TL0 = 0xB0;
		TR0 = 1;
		TF0 = 0;
	}
}

void main()
{	
	for(;;)//Endless loop
	{
		for(data_in=0x80;data_in>0x00;data_in>>=1)
		{
			P1 = data_in;//Send data to LED
			delay();//wait for 0,1 second
		}
	}
}