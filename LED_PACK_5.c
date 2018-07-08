#include <reg51.h>

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
void Left_to_Right()//LEDs go left to right 8 times
{	
	unsigned int data_in;
	int pattern1_counter = 0;
	
	while(pattern1_counter++ < 8)
	{
		for(data_in=0x80;data_in>0x00;data_in>>=1)
		{
			P1 = data_in;//Send data to LED
			delay();//wait for 0,1 second
		}
	}
}
void Right_to_Left()//LEDs go right to left 8 times
{	
	unsigned int data_in;
	int pattern2_counter = 0;
	
	while(pattern2_counter++ < 8)
	{
		for(data_in=0x01;data_in<0x100;data_in<<=1)
		{
			P1 = data_in;//Send data to LED
			delay();//wait for 0,1 second
		}
	}
}
void Blinking_Sets()//4 sets of LEDs blink alternately 8 times
{
	int pattern3_counter = 0;
	while(pattern3_counter++ <8)
	{
		P1=0xF0;
		delay();
		P1=~P1;
		delay();
	}
}
void Blinking_Pack()//LED pack blinks 8 times
{
	int pattern3_counter = 0;
	while(pattern3_counter++ <8)
	{
		P1=0xFF;
		delay();
		P1=~P1;
		delay();
	}
}

void main()
{
	for(;;)
	{
		Left_to_Right();
		Right_to_Left();
		Blinking_Sets();
		Blinking_Pack();
	}
}