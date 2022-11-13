//MCU2
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit wela=P2^7;
sbit dula=P2^6;
//sbit flag=P3^2;
uchar number;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void Delay(xms)
{
    uint i,j;
    for(i=xms;i>0;i--)
        for(j=110;j>0;j--);
}
void Display(uchar value)
{
    /*
    uchar shi,ge;
    shi=value/10;
    ge=value%10;
    */
    
    P0=0x00;
    wela=1;
    P0=0x01;
    wela=0;
    P0=0x00;
    dula=1;
    P0=table[value];
    dula=0;
    Delay(5);
   /* 
    P0=0x00;
    wela=1;
    P0=0x02;
    wela=0;
    P0=0x00;
    dula=1;
    P0=table[ge];
    dula=0;
    Delay(5); 
    */
}
/*void Send_char()
{
    ES=0;
    SBUF=0x01;
    while(!TI);
    TI=0;
		ES=1;
}*/
void main()
{
		//flag=1;
    TMOD=0x20;
    SCON=0x50;
    TH1=0xfd;
    TL1=0xfd;
    EA=1;
    ES=1;
    TR1=1;
    while(1);
			
}
void Ser() interrupt 4
{    
    RI=0;
    number=SBUF;
	 Display(number); 
}