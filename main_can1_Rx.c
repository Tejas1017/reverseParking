#include "header.h"
 
#define LED (1<<17)
#define BUZZER (1<<21)
 
CAN1 m1;
int flag=0;
int f=1;
int main()
{
	can1_init();
  en_can1_interrupt(); 
	enEintInterrupt();
	config_vic();
	IODIR0=1<<21|1<<17;
	IOSET0=1<<21|1<<17;
	while(1)
	{
		if(f==0)
			{
				
		if(flag==1){
					flag=0;
					switch(m1.ByteA)
					{
					case 0xa :	while(!f){
										IOCLR0=1<<21|1<<17;
										delay_ms(200);
										IOSET0=1<<21|1<<17;
										delay_ms(200);
										}
										break;
					case 0xb :	while(!f){
										IOCLR0=1<<21|1<<17;
										delay_ms(100);
										IOSET0=1<<21|1<<17;
										delay_ms(100);
									}
										break;
				
					case 0xc :	while(!f){
										IOCLR0=1<<21|1<<17;
										delay_ms(50);
										IOSET0=1<<21|1<<17;
										delay_ms(50);
										}
										break;
					case 0xd :	while(!f){
										IOCLR0=1<<21|1<<17;
										delay_ms(10);
										IOSET0=1<<21|1<<17;
										delay_ms(10);
										}
										break;
					case 0xe : 	while(!f){
										IOCLR0=1<<21|1<<17;
										//delay_ms(500);
										//IOSET0=1<<21|1<<17;
										//delay_ms(500);
										}
										break;
		}
	}
	}
}
}
