	#include <reg51.h>
	#define uint unsigned int
	#define uchar unsigned char
	sbit button0=P3^0;
	sbit button1=P3^1;
	sbit button2=P3^2;
	sbit button3=P3^7;
	sbit dula=P2^6;
	sbit wela=P2^7;
	void Delay(uint xms);
	void Initial();
	void Segment(uchar x);
	void Selection(uchar x);
	void Display();
	void Button();
