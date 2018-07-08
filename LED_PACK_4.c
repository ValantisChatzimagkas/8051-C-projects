#include <reg51.h>

int loop_counter;//loop counter

//Array of data with 23 elements for pattern display in LED pack
unsigned int Data_Array[23] = {0x18,0x24,0x42,0x81,0x42,0x24,0x18,
					0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,
					0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF};

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
		for(loop_counter=0;loop_counter<23;loop_counter++)//counter 0-22, is 23 elements
		{
			P1 = Data_Array[loop_counter];//Fetching data with counter as array index
								   //sending fetched data to LED pack via P1
			delay();//wait for 0,1 second				   
		}
	}
}