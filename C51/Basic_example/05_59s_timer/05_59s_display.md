# 实例5——片选两位数码管实现59s计时

## 1.电路原理图

<img src="https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/05_59s原理图.png" style="zoom: 50%;" />

## 2.程序设计

```C
	//main.h
	#include <reg51.h>
	#define uint unsigned int
	#define uchar unsigned char
	void Initial();
	void Timer_59s();
	void Restart();
	void Delay(uint xms);

    //main.c
    #include "05_main.h"
    void main()
    {
        Initial();
        while(1)
        {
            Timer_59s();
            Restart();
        }
    }
//05_function.c
	#include <reg51.h>
	#define uint unsigned int
	#define uchar unsigned char
	sbit led1=P1^0;
	sbit dula=P2^6;
	sbit wela=P2^7;
	uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	uchar flag_award,flag_back;
	uchar count_T0,count_T1;
	void Initial() //initial 
	{
		led1=1;
		
		EA=1;
		ET0=1;
		ET1=1;
		TMOD=0x11;
		TR0=1;
		TR1=1;
		TH1=(65536-46083)/256;
		TL1=(65536-46083)%256;
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0=0;
		count_T1=0;
		
		flag_award=0;
		flag_back=0;
		//flag_select=0;
	}
	void T0_timer() interrupt 1  //T0,50ms
 	{
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0++;
		if(count_T0==4)
		{
			count_T0=0;
			led1=~led1;
		}
	}
	void T1_timer() interrupt 3		//T1,50ms
	{
		TH1=(65536-46083)/256;
		TL1=(65536-46083)%256;
		count_T1++;
		if(count_T1==20)
		{
			count_T1=0;
			flag_back++;
		}
		if(flag_back==10)
		{
			flag_back=0;
			flag_award++;
		}
	}
	void Delay(uint xms)//delay
	{
		uchar i,j;
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}
	void Timer_59s()		//dynamic display
	{
		wela=1;//片选第一个数码管并显示十位数字
		P0=0x01;
		wela=0;
		P0=0x00;
		dula=1;
		P0=table[flag_award];
		dula=0;
		P0=0x00;
		Delay(5);
		
		wela=1;//片选第2个数码管并显示个位数字
		P0=0x02;
		wela=0;
		P0=0x00;
		dula=1;
		P0=table[flag_back];
		dula=0;
		P0=0x00;
		Delay(5);
	}
	void Restart()//pulse 59s,display 0 
	{
		if(flag_award==6)
		{
			flag_back=0;
			flag_award=0;
			EA=0;
		}
	}
```

```C
//模块化程度更高的代码
//下方代码将T0200ms计时，T11s计时均防在主函数中，因为此时主函数运行时间小于中断，所以不会出现意外
//但是假设主程序执行时间为50ms，而每次中断设定为20ms，恰好在count_T0=3且运行主程序时经过两次中断，其count_T0=5,再去进行T0的4次或者说200ms的判断，将永远不可能成功，程序出错
//因此，需要注意，主程序的时间时间不要比中断计时长太多
//05main.h
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
//05main.c
   #include "05_main.h"
 	uchar flag_award,flag_back,repeat_count;
	uchar count_T0,count_T1;
	void main()
	{
		Initial();
		while(1)
		{
		  Timer_59s(repeat_count,flag_award,flag_back);
			Restart();
		}
	}
//05function.c
	#include <reg51.h>
	#define uint unsigned int
	#define uchar unsigned char
	sbit led1=P1^0;
	sbit dula=P2^6;
	sbit wela=P2^7;
	uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	extern uchar flag_award,flag_back,repeat_count;
	extern uchar count_T0,count_T1;
	void Initial() //initial 
	{
		led1=1;
		
		EA=1;
		ET0=1;
		ET1=1;
		TMOD=0x11;
		TR0=1;
		TR1=1;
		TH1=(65536-46083)/256;
		TL1=(65536-46083)%256;
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0=0;
		count_T1=0;
		
		flag_award=0;
		flag_back=0;
		repeat_count=0;
	}
	void T0_timer() interrupt 1  //T0,50ms
 	{
		TH0=(65536-46083)/256;
		TL0=(65536-46083)%256;
		count_T0++;
	}
	void T0_is200ms()
	{
		if(count_T0==4)
		{
			count_T0=0;
			led1=~led1;
		}
	}
	void T1_timer() interrupt 3		//T1,50ms
	{
		TH1=(65536-46083)/256;
		TL1=(65536-46083)%256;
		count_T1++;
	}
	void T1_is1s()
	{
		if(count_T1==20)
		{
			count_T1=0;
			flag_back++;
		}
		if(flag_back==10)
		{
			flag_back=0;
			flag_award++;
		}
	}

	void Segment(uchar x,uchar y,uchar z)
	{
		if(x%2==0)
		{
			P0=table[y];
		}
		else
		{
			P0=table[z];
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
	void Delay(uint xms)//delay
	{
		uchar i,j;
		for(i=xms;i>0;i--)
			for(j=110;j>0;j--);
	}
	void Timer_59s(uchar i,uchar j,uchar k)		//dynamic display
	{
		wela=1;
		Selection(i);
		wela=0;
		P0=0x00;
		dula=1;
		Segment(i,j,k);
		dula=0;
		P0=0x00;
		repeat_count++;
		Delay(10);
		T0_is200ms();
		T1_is1s();
	}

	void Restart()//pulse 59s,display 0 
	{
		if(flag_award==6)
		{
			flag_back=0;
			flag_award=0;
		}
	}
```



## 3.结果

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/59s仿真.gif)

+ 模块化实现59s数据动态显示

## 4.收获

1. **编程时要考虑程序执行时间，是否要延迟**

   **如下结果，这是将Time_59s函数内的延迟时间改为1ms，动态刷新的速度太快，同一数码管两次显示间隔只有2ms，码管显示数字重叠，始终全亮，影响结果**

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/错误结果.gif)

**2.模块化设计，C51带参函数设计**

3.main.c、main.h、function.c三个文件虽然可以调用，全局变量在.h中定义后，若要在function中使用，依然需要声明，或者**另外新建.h头文件专门存放全局变量，每个.c文件包含后调用**

## 5.优化

优化三数码管实现10分钟计时，代码见Code9.59，增加flag_mint变量，增加Selection（）与Segment（）函数内分支，即P0=0x04，第三个数码管显示

<img src="https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/三位显示.png" style="zoom: 50%;" />