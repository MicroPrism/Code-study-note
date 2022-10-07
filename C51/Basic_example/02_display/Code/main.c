#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
void delay(uint);
uint i,j;
uchar x;
void main()
{
	for(x=0x20;x>0;x=x>>1)
	{
	wela=1;
	P0=x;
	wela=0;
	
	dula=1;
	P0=0x80;
	dula=0;
	delay(1000);
	}
	while(1);
}
void delay(uint xms)
{
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}