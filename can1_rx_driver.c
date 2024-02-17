#include"header.h"

#define TCS ((C1GSR>>3)&1)
#define RBS (C1GSR&1)

extern CAN1 m1,m2;
extern int flag;

void can1_init(void)
{
	PINSEL1|=0x00040000;        //p0.25->RD1
	VPBDIV=1;                   //PCLK=60MHz
	C1MOD=1;                    //select reset mode
	C1BTR=0x001C001D;           //set 125kbps baudrate
	AFMR=2;                     //accept all incoming messages
	C1MOD=0;                    //cancel reset mode
}

void can1_tx(CAN1 v)
{
	C1TID1=v.id;
	C1TFI1=v.dlc<<16;           //ptr=0,16,17,18,19 bits=dlc;
	if(v.rtr==0)                //if data frame
	{
		C1TDA1=v.ByteA;
		C1TDB1=v.ByteB;
	}
	else
		C1TFI1|=(1<<30);          //if remote frame RTR=1;
	C1CMR=1|(1<<5);             //start tx and select TxBuff 1
	while(TCS==0);
}

//void can1_rx(CAN1 *ptr)
//{
//	while(RBS==0);
//	ptr->id=C1RID;
//	ptr->dlc=(C1RFS>>16)&0xF;
//	ptr->rtr=(C1RFS>>30)&1;
//	if(ptr->rtr==0)                //if data frame received
//	{
//		ptr->ByteA=C1RDA;
//		ptr->ByteB=C1RDB;
//	}
//	C1CMR=1<<2;                  	//release RxBuff Mandatory
//}

void can1_Rx_Handler(void)__irq
{
	m1.id=C1RID;
	m1.dlc=(C1RFS>>16)&0xF;
	m1.rtr=(C1RFS>>30)&1;
	if(m1.rtr==0)
	{
		m1.ByteA=C1RDA;
		m1.ByteB=C1RDB;
	}
	C1CMR=1<<2;
	flag=1;
	VICVectAddr=0;
}

void en_can1_interrupt(void)
{
	VICIntSelect=0;
	VICVectCntl1=26|(1<<5);
	VICVectAddr1=(int)can1_Rx_Handler;
	VICIntEnable|=1<<26;
	C1IER=1;
}
