#include <reg51.h>

unsigned int data_in;
void delay()//This function will cause 0,5 sec delay
{
	int counter = 0;
	
	while(counter++ < 10)//0,5 seconds delay					
	{					 //if counter=2 is 0,1 seconds then counter 10 = 0,5 sec
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
		for(data_in=0x00;data_in<0x9A;data_in++)// counts from 00 to 99
		{
			if((data_in & 0x0F) == 0x0A)// We cannot accept values A-F so we cut them out here
			{							
				data_in = data_in+0x06;//If you add 0x06 0x0A will turn to 0x10
			}
			P1 = data_in;//We send the data to 7-segment display via P1
			delay();//Wait for 0,5 seconds
		}
		for(data_in=0x99;data_in<0xF9;data_in--)// counts from 99 to 0
		{
			if((data_in & 0x0F) == 0x0F)// We cannot accept values A-F so we cut them out here
			{							//Since we got backwards we reach 0x0F 					
				data_in = data_in-0x06;//We go backwards so now we subtract 6
			}
			P1 = data_in;//We send the data to 7-segment display via P1
			delay();//Wait for 0,5 seconds
		}
	}
}