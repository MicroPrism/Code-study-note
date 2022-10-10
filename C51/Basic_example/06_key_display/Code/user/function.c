	#include "main.h"
	#include "constant.h"
	void Delay(uint xms)
	{
		uchar i,j;
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}
	void Initial()
	{
		wela=1;
		P0=0x01;
		wela=0;
		P0=0x00;
		dula=1;
		P0=table[0];
		dula=0;
		P0=0x00;
		Delay(5);
		
		wela=1;
		P0=0x02;
		wela=0;
		P0=0x00;
		dula=1;
		P0=table[0];
		dula=0;
		P0=0x00;
		Delay(5);
		
		count_T0=0;
		
		repeat_count=0;
		shi=0;
		ge=0;
		
			TMOD=0x01;
			EA=1;
			ET0=1;
			TH0=(65536-46083)/256;
		  TL0=(65536-46083)%256;
	}
	void Button()
	{
		if(button0==0)
		{
			Delay(10);
			if(button0==0)
			{
				ge++;
				if(ge==10)
				{
					ge=0;
					shi++;
				}
				if(shi==6)
				{
					shi=0;ge=0;
				}
				while(!button0);
			}
		}
		if(button1==0)
		{
			Delay(10);
			if(button1==0)
			{
				if(shi!=0&&ge==0)
				{
					shi--;
					ge=9;
				}
				else if(ge!=0)
				{
					ge--;
				}
				else
				{
					ge=0;shi=0;
				}
				while(!button1);
			}
		}
		if(button2==0)
		{
			Delay(10);
			if(button2==0)
			{
				shi=0;
				ge=0;
			}
			while(!button2);
		}
		if(button3==0)
		{
			Delay(10);
			if(button3==0)
			{
				while(!button3);
				TR0=~TR0;
			}
		}
	}
	void Segment(uchar x)
	{
		if(x%2==0)
		{
			P0=table[shi];
		}
		else
		{
			P0=table[ge];
		}
	}
	void Selection(uchar x)
	{
		if(x%2==0)
		{
			P0=0x01;
		}
		else
		{
			P0=0x02;
		}
	}
	void Display()
	{
		Button();
		wela=1;
		Selection(repeat_count);
		wela=0;
		P0=0x00;
		dula=1;
		Segment(repeat_count);
		dula=0;
		P0=0x00;
		repeat_count++;//correct i->repeat_count
		Delay(5);
	}
	void T0_timer() interrupt 1
	{
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0++;
		if(count_T0==20)
		{
			count_T0=0;//Timmer, Error!lack of this clear
			ge++;
			if(ge==10)
			{
				shi++;
				ge=0;
			}
			if(shi==6)
			{
				ge=0;
				shi=0;
			}
		}			
	}