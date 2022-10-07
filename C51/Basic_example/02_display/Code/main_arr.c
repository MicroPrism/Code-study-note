#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
void delay(uint);
uchar x;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void main()
{
	wela=1;
	P0=0x3f;
	wela=0;
	while(1)
	{
	for(x=0;x<16;x++)
		{
		dula=1;
		P0=table[x];
		dula=0;
		delay(500);
		}
	}
}
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}