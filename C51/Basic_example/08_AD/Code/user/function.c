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
}
void Display(uchar bai,uchar shi,uchar ge)
{
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