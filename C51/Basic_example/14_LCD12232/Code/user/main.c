#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit wela=P2^7;
sbit dula=P2^6;

sbit sclk=P3^0;
sbit sid=P3^1;
sbit cslcd=P3^2;

uchar code table1[]="I LOVE MCU!";
uchar code table2[]="我爱单片机";
//uchar* a;

void Delay(uint xms)//delay xms
{
	uchar i,j=0;
	for(i=xms;i>0;i--)
	{
		for(j=110;j>0;j--);
	}		
}
void send_command(uchar command_data)
{
	uchar i;
	uchar i_data;
	i_data=0xf8;//11111000写指令的指令码
	cslcd=1;
	sclk=0;
	//通过移位将指令码存入二进制字节
	for(i=0;i<8;i++)
	{
		sid=(bit)(i_data&0x80);
		sclk=0;
		sclk=1;
		i_data=i_data<<1;
	}
	//重新赋值，高四位传入第二字节
	i_data=command_data;
	i_data=i_data&0xf0;
	for(i=0;i<8;i++)
	{
		sid=(bit)(i_data&0x80);//只留最高位
		sclk=0;
		sclk=1;
		i_data=i_data<<1;
	}
	//重新赋值移位后传入低四位
	i_data=command_data;
	//i_data=i_data&0x0f;无需进行高位屏蔽，直接移位低位自动补0
	i_data=i_data<<4;
	for(i=0;i<8;i++)
	{
		sid=(bit)(i_data&0x80);
		sclk=0;
		sclk=1;
		i_data=i_data<<1;
	}
	cslcd=0;
	Delay(10);
}
void send_data(uchar command_data)
{
	uchar i;
	uchar i_data;
	i_data=0xfa;//11111010，写数据的指令码
	cslcd=1;
	sclk=0;
	//通过移位将指令码存入二进制字节
	for(i=0;i<8;i++)
	{
		sid=(bit)(i_data&0x80);
		sclk=0;
		sclk=1;
		i_data=i_data<<1;
	}
	//重新赋值，高四位传入第二字节
	i_data=command_data;
	i_data=i_data&0xf0;
	for(i=0;i<8;i++)
	{
		sid=(bit)(i_data&0x80);//只留最高位
		sclk=0;
		sclk=1;
		i_data=i_data<<1;
	}
	//重新赋值移位后传入低四位
	i_data=command_data;
	i_data=i_data<<4;
	for(i=0;i<8;i++)
	{
		sid=(bit)(i_data&0x80);
		sclk=0;
		sclk=1;
		i_data=i_data<<1;
	}
	cslcd=0;
	Delay(10);
}
void Display_test()
{
	uchar a;
	send_command(0x80);
	for(a=0;a<16;a++)
	{
		send_data(table1[a]);
	}
}
void Display_C1(uchar *p)
{
	uchar* a=p;
	send_command(0x80);
	for(;*a!=0;a++)
	{
		send_data(*a);
	}
}
void Display_C2(uchar *p)
{
	uchar* a=p;//变量创建要在发送指令之前
	send_command(0x90);
	//uchar* a=p;
	for(;*a!=0;a++)
	{
		send_data(*a);
	}
}
void init()
{
	Delay(100);
	send_command(0x30);//功能设定：8位数据接口，基本指令模式
	send_command(0x02);//地址归位：DDRAM计数器AC清0
	send_command(0x06);//进入点设定：数据读写游标显示右移
	send_command(0x0c);//显示状态：整体开，游标关，反白关
	send_command(0x01);//清除显示
	send_command(0x80);//设定DDRAM地址：首行80H-87H，第二行90-97H
}
void main()
{
	init();
	Display_test();
	//Display_C1(table1);
	Display_C2(table2);
	while(1);
}