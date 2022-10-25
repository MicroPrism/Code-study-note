#include <reg51.h>
#include <stdlib.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
#define LCD_data P0
sbit wela=P2^7;
sbit dula=P2^6;
//声明引脚，可调整
sbit LCD_RS=P3^5;//指令数据选择
sbit LCD_RW=P3^6;//读写选择端
sbit LCD_EN=P3^4;//使能端
sbit LCD_PSB=P3^7;//串行并行端
uchar dis1[10];
uchar code dis2[]="I LOVE MCU!";
uchar code dis3[]="我爱单片机";
uchar code dis4[]="-----";
//uchar* a;

void Delay(uint xms)//delay xms
{
	uchar i,j=0;
	for(i=xms;i>0;i--)
	{
		for(j=110;j>0;j--);
	}		
}
//写指令，RS=0(指令)，RW=0(写)，E=0=>1高脉冲，指令写入
void Write_cmd_12864(uchar cmd)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_EN=0;
	P0=cmd;
	Delay(5);
	LCD_EN=1;
	Delay(5);
	LCD_EN=0;
}
//写指令，RS=0(指令)，RW=0(写)，E=0=>1高脉冲，指令写入
void Write_data_12864(uchar dat)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_EN=0;
	P0=dat;
	Delay(5);
	LCD_EN=1;
	Delay(5);
	LCD_EN=0;
}
//设定起始显示位置，第x行，第y列
void LCD_pos(uchar X,uchar Y)
{
	uchar pos;
	if(X==1)
	{
		X=0x80;
	}
	else if(X==2)
	{
		X=0x90;
	}
	else if(X==3)
	{
		X=0x88;
	}
	else if(X==4)
	{
		X=0x98;
	}
	pos=X+Y;
	Write_cmd_12864(pos);
}
//数列存储随机数
void Makerand()
{
	uint ran;
	ran=rand();
	dis1[0]=ran/10000+0x30;
	dis1[1]=ran%10000/1000+0x30;
	dis1[2]=ran%1000/100+0x30;
	dis1[3]=ran%100/10+0x30;
	dis1[4]=ran%10+0x30;
	
	ran=rand();
	dis1[5]=ran/10000+0x30;
	dis1[6]=ran%10000/1000+0x30;
	dis1[7]=ran%1000/100+0x30;
	dis1[8]=ran%100/10+0x30;
	dis1[9]=ran%10+0x30;
}
//并行初始化
void LCD_initial_12864()
{
	LCD_PSB=1;//并口方式
	Write_cmd_12864(0x30);//基本指令
	Delay(5);
	Write_cmd_12864(0x0C);//显示开，光标关
	Delay(5);
	Write_cmd_12864(0x01);//清除显示
	Delay(5);
}
void main()
{
	uchar i;
	wela=0;
	dula=0;
	Delay(10);
	LCD_initial_12864();
	//dis2显示在第二行
	LCD_pos(2,0);
	i=0;
	while(dis2[i]!='\0')
	{
		Write_data_12864(dis2[i]);
		i++;
	}
	//dis3
	LCD_pos(3,0);
	i=0;
	while(dis3[i]!='\0')
	{
		Write_data_12864(dis3[i]);
		i++;
	}
	LCD_pos(4,0);
	i=0;
	while(dis4[i]!='\0')
	{
		Write_data_12864(dis4[i]);
		i++;
	}
	//死循环生成随机数，rand伪随机
	while(1)
	{
		LCD_pos(0,0);
		Makerand();
		for(i=0;i<10;i++)
		{
			Write_data_12864(dis1[i]);
		}
	}
}