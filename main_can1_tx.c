#include "header.h"

CAN1 m1,m2;
int flag=0;
int distance=0;

int main()
{
	int pot,distance;
	can1_init();
	adc_init();
	en_can1_interrupt();
	while(1)
	{
		if(flag)
		{
			if(m1.rtr)
			 {		  pot = adc_read(2);
	                  distance = ((float)(400)/(1023))*(pot);
					 m2.id=0x178;
					 m2.rtr=0;
					 m2.dlc=4;
					
					 if(distance>=300 && distance<400){
					 m2.ByteA= 0xaa;
					 }
					 else if(distance>=200&& distance<300){
					 m2.ByteA=0xbb;
					 }
					 else if(distance>100&& distance<200){
					 m2.ByteA=0xcc;
					 }
					 else if(distance>=50&& distance<=100){
					 m2.ByteA=0xdd;
					 }
					 can1_tx(m2);
					 delay_ms(100);
			 }
		 }			 
	}
	
}
