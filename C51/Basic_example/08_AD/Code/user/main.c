#include "main.h"
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void main()
{
	uchar A1,A2,A3,adval;
	Initial();
	while(1)
	{
		wr=1;
		_nop_();
		wr=0;//wr 0->1,restart AD
		_nop_();
		wr=1;
		Display(A1,A2,A3);
		
		P1=0xff;
		rd=1;
		_nop_();
		rd=0;
		_nop_();
		adval=P1;
		rd=1;
		A1=adval/100;
		A2=adval/10%10;
		A3=adval%10;
	}
}