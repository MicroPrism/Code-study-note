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
		key_flag=0;
	
		wela=1;
		P0=0x3f;
		wela=0;
		dula=1;
		P0=table[0];
		dula=0;
		Delay(5);
	}
	void Display()
	{
		//key_flag=Key_matrix();
		//while(P3/256!=0x0f);
		Key_matrix();
		while(temp!=0x0f)
		{
			temp=P3;
			temp=P3&0x0f;
		}
		P0=table[key_flag];
		dula=1;
		//P0=table[key_flag];
		dula=0;
		//Delay(5);
	}
	void Key_matrix()
	{
		P3=0xef;//Col0=0
		temp=P3;
		temp=temp&0x0f;//P3 L 0?
		if(temp!=0x0f)
		{
			Delay(10);
			temp=P3;
			temp=temp&0x0f;
			if(temp!=0x0f)
			{
				temp=P3;
				switch(temp)
				{
					case 0xee:key_flag=0;break;
					case 0xed:key_flag=1;break;
					case 0xeb:key_flag=2;break;
					case 0xe7:key_flag=3;break;
				}
//				while(temp!=0x0f)
//				{
//					temp=P3;
//					temp=P3&0x0f;
//				}
				}
			}
		P3=0xdf;//Col0=0
		temp=P3;
		temp=temp&0x0f;//P3 L 0?
		if(temp!=0x0f)
		{
			Delay(10);
			temp=P3;
			temp=temp&0x0f;
			if(temp!=0x0f)
			{
				temp=P3;
				switch(temp)
				{
					case 0xde:key_flag=4;break;
					case 0xdd:key_flag=5;break;
					case 0xdb:key_flag=6;break;
					case 0xd7:key_flag=7;break;
				}

			}
		}
		
		P3=0xbf;//Col0=0
		temp=P3;
		temp=temp&0x0f;//P3 L 0?
		if(temp!=0x0f)
		{
			Delay(10);
			temp=P3;
			temp=temp&0x0f;
			if(temp!=0x0f)
			{
				temp=P3;
				switch(temp)
				{
					case 0xbe:key_flag=8;break;
					case 0xbd:key_flag=9;break;
					case 0xbb:key_flag=10;break;
					case 0xb7:key_flag=11;break;
				}
//				while(temp!=0x0f)
//				{
//					temp=P3;
//					temp=P3&0x0f;
//				}
			}
		}
		P3=0x7f;//Col0=0
		temp=P3;
		temp=temp&0x0f;//P3 L 0?
		if(temp!=0x0f)
		{
			Delay(10);
			temp=P3;
			temp=temp&0x0f;
			if(temp!=0x0f)
			{
				temp=P3;
				switch(temp)
				{
					case 0x7e:key_flag=12;break;
					case 0x7d:key_flag=13;break;
					case 0x7b:key_flag=14;break;
					case 0x77:key_flag=15;break;
				}
//				while(temp!=0x0f)
//				{
//					temp=P3;
//					temp=P3&0x0f;
//				}
			}
		}
	}
	