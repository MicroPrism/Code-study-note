#include <reg51.h>
#include <intrins.h>//use _nop_() function
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;
sbit wr=P3^6;
sbit rd=P3^7;
void Delay(uint);
void Initial();
void Display(uchar,uchar,uchar);
