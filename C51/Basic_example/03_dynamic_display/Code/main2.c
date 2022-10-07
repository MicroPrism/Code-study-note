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
	uchar i,j;
	while(1)
	{		
		j=0x01;
		for(i=0;i<6;i++)
		{
			//P0=0;
			wela=1;
			P0=j;
			j=j<<1;
			wela=0;
			//P0=0;
			dula=1;
			P0=table[i];
			dula=0;
			delay(1);
		}
	}
}
void delay(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);
}