#include "main.h"
#include "constant.h"
void Delay(uint xms)
{
	uchar i,j=0;
	for(i=xms;i>0;i--)
	{
		for(j=110;j>0;j--);
	}		
}
void Initial()
{
	P0=0x00;
	wela=1;
	P0=0x3f;
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[0];
	dula=0;
	
	TMOD=0x21;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	TH1=0xfd;
	TL1=0xfd;
	TR1=1;
	TR0=1;
	EA=1;
	//ET1=1;
	SM0=0;
	SM1=1;
	REN=1;
	ET0=1;
	ES=1;
}
void Display(uchar value)
{
	uchar bai,shi,ge;
	bai=value/100;
	shi=value/10%10;
	ge=value%10;
	P0=0x00;
	wela=1;
	P0=0x01;
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[bai];
	dula=0;
	Delay(5);
	
	P0=0x00;
	wela=1;
	P0=0x02;
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[shi];
	dula=0;
	Delay(5);
	
	P0=0x00;
	wela=1;
	P0=0x04;
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[ge];
	dula=0;
	Delay(5);
}
uchar get_ad()
{
	uchar ad_val;
	adwr=1;
	_nop_();
	adwr=0;
	_nop_();
	adwr=1;
	P1=0xff;
	adrd=1;
	_nop_();
	adrd=0;
	_nop_();
	ad_val=P1;
	adrd=1;
	return ad_val;
}
void Timer0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	count++;
	if(count==20)
	{
		count=0;
		flag_time=1;
	}
}
void Ser() interrupt 4
{
	RI=0;
	a=SBUF;
	flag_uart=1;//First receive ok!
	if(a==1)
		flag_on=0;
	else if(a==2)
		flag_on=1;
	else
		flag_on=3;
}