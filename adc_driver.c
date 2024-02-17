#include"header.h"
#define DONE ((ADDR>>31)&1)

void adc_init()
{
PINSEL1|=0x15400000;
ADCR|=0x00200400;
}

int adc_read(int ch_num)
{
int result=0;
ADCR|=(1<<ch_num);
ADCR|=(1<<24);
while(DONE==0);
ADCR^=(1<<ch_num);
ADCR^=(1<<24);
result=((ADDR>>6)&0x3FF);
return result;
}
