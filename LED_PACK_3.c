#include <reg51.h>

int loop_counter;//loop counter
unsigned int leftmost_leds = 0x80;//Leftmost LED turns on
unsigned int rightmost_leds = 0x01;//Rightmost LED turn on

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
		for(loop_counter=0;loop_counter<4;loop_counter++)//convergence
		{
			P1 = leftmost_leds+rightmost_leds;//Send data to LED
			delay();//wait for 0,1 second
			
			leftmost_leds>>=1;//going one step right
			rightmost_leds<<=1;//going one step left
		}
		for(loop_counter=0;loop_counter<4;loop_counter++)//seperation
		{			
			leftmost_leds<<=1;//going one step left
			rightmost_leds>>=1;//going one step left
			
			P1 = leftmost_leds+rightmost_leds;//Send data to LED
			delay();//wait for 0,1 second
		}
	}
}