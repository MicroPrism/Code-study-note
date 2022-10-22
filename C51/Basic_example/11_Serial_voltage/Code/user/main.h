#include <reg51.h>
#include <intrins.h>//_nop_();
#include <stdio.h>
#define uchar unsigned char
#define uint  unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
sbit adwr=P3^6;
sbit adrd=P3^7;
void Delay(uint);
void Initial();
void Display(uchar value);
uchar get_ad();