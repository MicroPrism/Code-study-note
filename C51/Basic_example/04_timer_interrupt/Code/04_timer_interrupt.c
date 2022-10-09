#include <reg51.h>
#define uint unsigned int
#define uchar unsigned char
sbit led1=P1^0;
uchar x=0;
//3.
void main()
{
	led1=0;
	EA=1;//open all interrupt
	ET0=1;
	TMOD=0x01;//T0 mode 00
	TH0=(65536-46083)/256;
	TL0=(65536-46083)%256;
	TR0=1;
	while(1)
	{
		if(x==20)
		{
			x=0;
			led1=~led1;
		}	
	};
}
//2.
//void main()
//{
//	led1=0;
//	while(1)
//	{
//		EA=1;//open all interrupt
//		ET0=1;
//		TMOD=0x01;//T0 mode 00
//		TH0=(65536-46083)/256;
//		TL0=(65536-46083)%256;
//		TR0=1;
//	}
//}
//1.
//void main()
//{
//	led1=0;
//	while(1)
//	{
//		EA=1;//open all interrupt
//		TMOD=0x01;//T0 mode 00
//		TH0=(65536-46083)/256;
//		TL0=(65536-46083)%256;
//		TR0=1;
//	}
//}
void T0_timer() interrupt 1
{
	TH0=(65536-46083)/256;
	TL0=(65536-46083)%256;
	x++;
}