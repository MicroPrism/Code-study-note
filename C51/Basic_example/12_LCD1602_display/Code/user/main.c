#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit wela=P2^7;
sbit dula=P2^6;
sbit lcden=P3^4;
sbit lcdrs=P3^5;
uchar num;
uchar code table1[]="I LOVE MCU!";
uchar code table2[]="OH~ YES!";
void Delay(uint xms)//delay xms
{
	uchar i,j=0;
	for(i=xms;i>0;i--)
	{
		for(j=110;j>0;j--);
	}		
}
void Lcd_wr_commend(uint value)//lcd write command
{
	lcdrs=0;//RS=0,write
	P0=value;
	Delay(5);
	lcden=1;//E=H
	Delay(5);
	lcden=0;
}
void Lcd_wr_data(uint value)//lcd write data,display
{
	lcdrs=1;
	P0=value;
	Delay(5);
	lcden=1;
	Delay(5);
	lcden=0;
}
void init()
{
	dula=0;
	wela=0;
	lcden=0;
	Lcd_wr_commend(0x38);//setting 16*2
	Lcd_wr_commend(0x0c);//0000 1100 open display,close mouse 
	Lcd_wr_commend(0x06);//address add 1 after one char end,and mouse
	Lcd_wr_commend(0x01);//clear data ptr and monitor display of lcd
}
void main()
{
	init();
	Lcd_wr_commend(0x80);//set data address on first row  initiation 
	for(num=0;num<11;num++)
	{
		Lcd_wr_data(table1[num]);
		Delay(5);
	}
	Lcd_wr_commend(0x80+0x40);//+0x40,second row
		for(num=0;num<8;num++)
	{
		Lcd_wr_data(table2[num]);
		Delay(5);
	}
	while(1);//wait
}