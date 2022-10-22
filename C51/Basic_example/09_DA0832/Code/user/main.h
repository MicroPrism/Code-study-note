#include <reg51.h>

#define uchar unsigned char 
#define uint  unsigned int
	
sbit dula=P2^6;
sbit wela=P2^7;
sbit csda=P3^2;//DA-CS
sbit dawr=P3^6;//WR
sbit beep=P3^0;
void Delay(uint xms);
void Initial();