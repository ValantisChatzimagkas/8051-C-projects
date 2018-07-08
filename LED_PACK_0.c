#include <reg51.h>

unsigned int data_in=0xFF;//Input data for LED pack
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
	for(;;)
	{
		P1 = data_in;//all LEDs on
		delay();//wait for 0,1 second
		P1 = ~data_in;//invert input data, all off
		delay();//wait for 0,1 second
	}
}