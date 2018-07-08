#include <reg51.h>


unsigned int tens_digit;//This is the tens digits counter so we can go 0x10 - 0x90
unsigned int Data_Array[10] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};//data for 0-9
unsigned int array_index;//Indexes the data from our Data_Array

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
		for(tens_digit=0x00;tens_digit<0xA0;tens_digit=tens_digit+0x10)//This loop affects tens digits 0x10-0x90
		{
			for(array_index=0;array_index<10;array_index++)//We fecth data from our array to count 0-9
			{
				P1 = tens_digit + Data_Array[array_index];// We send our data here every time we complete a couunt 0-9, tens change
				delay();
			}
		}
	}
}