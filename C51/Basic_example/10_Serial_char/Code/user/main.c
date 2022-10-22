#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
	
uchar flag,a,i;
uchar code table[]="I get";

void Initial();
void main()
{
	Initial();
	while(1)
	{
		if(flag==1)
		{
			ES=0;
			for(i=0;i<6;i++)
			{
				SBUF=table[i];
				while(!TI);//wait TI=1
				TI=0;
			}
			SBUF=a;
			while(!TI);
			TI=0;
			ES=0;//close serial interrupt
			flag=0;
		}
	}
}
void Initial()
{
	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	
	REN=1;//enable serial receive
	SM0=0;
	SM1=1;
	
	EA=1;
	ES=1;
}
void ser() interrupt 4 //model of timer interrupt is 5
{
	RI=0;
	a=SBUF;
	flag=1;
}