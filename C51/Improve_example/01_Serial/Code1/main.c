#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
void Delay(uint xms)
{
    uint i,j;
    for(i=xms;i>0;i--)
    {
        for(j=110;j>0;j--)
            ;
    }
}
void main()
{
    SM0=1;
    SM1=0;
    TB8=0;
    
    EA=1;
    ES=1;
    TI=0;
    while(1)
    {
        SBUF=0xaa;
        Delay(1);
    }
}
void Ser() interrupt 4
{
    TI=0;
}