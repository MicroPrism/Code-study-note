	#include <reg51.h>
	#define uint unsigned int
	#define uchar unsigned char
	sbit led1=P1^0;
	sbit dula=P2^6;
	sbit wela=P2^7;
	uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	extern uchar flag_award,flag_back,repeat_count;
	extern uchar count_T0,count_T1;
	void Initial() //initial 
	{
		led1=1;
		
		EA=1;
		ET0=1;
		ET1=1;
		TMOD=0x11;
		TR0=1;
		TR1=1;
		TH1=(65536-46083)/256;
		TL1=(65536-46083)%256;
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0=0;
		count_T1=0;
		
		flag_award=0;
		flag_back=0;
		repeat_count=0;
	}
	void T0_timer() interrupt 1  //T0,50ms
 	{
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0++;
	}
	void T0_is200ms()
	{
		if(count_T0==4)
		{
			count_T0=0;
			led1=~led1;
		}
	}
	void T1_timer() interrupt 3		//T1,50ms
	{
		TH1=(65536-46083)/256;
		TL1=(65536-46083)%256;
		count_T1++;
	}
	void T1_is1s()
	{
		if(count_T1==20)
		{
			count_T1=0;
			flag_back++;
		}
		if(flag_back==10)
		{
			flag_back=0;
			flag_award++;
		}
	}

	void Segment(uchar x,uchar y,uchar z)
	{
		if(x%2==0)
		{
			P0=table[y];
		}
		else
		{
			P0=table[z];
		}
	}
	void Selection(uchar x)
	{
		if(x%2==0)
		{
			P0=0x01;
		}
		else
		{
			P0=0x02;
		}
	}
	void Delay(uint xms)//delay
	{
		uchar i,j;
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}
	void Timer_59s(uchar i,uchar j,uchar k)		//dynamic display
	{
		wela=1;
		Selection(i);
		wela=0;
		P0=0x00;
		dula=1;
		Segment(i,j,k);
		dula=0;
		P0=0x00;
		repeat_count++;
		Delay(10);
		T0_is200ms();
		T1_is1s();
	}

	void Restart()//pulse 59s,display 0 
	{
		if(flag_award==6)
		{
			flag_back=0;
			flag_award=0;
		}
	}