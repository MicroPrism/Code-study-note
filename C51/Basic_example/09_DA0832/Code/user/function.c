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
	dula=0;
	wela=0;
	dawr=0;
	P0=0;
}