	#include <reg51.h>
	#define uint unsigned int
	#define uchar unsigned char
	void Initial();
	void Timer_59s(uchar repeat_count,uchar flag_award,uchar flag_back);
	void Restart();
	void Segment(uchar x,uchar y,uchar z);
	void Selection(uchar x);
	void Delay(uint xms);
	void T0_is200ms();
	void T1_is1s();