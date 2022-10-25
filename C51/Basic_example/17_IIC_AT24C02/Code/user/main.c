/*
程序名称：51单片机与AT24C02IIC通信
功能：数码管计时，并将结果存放于存储器，待下次上电读取上次结果，不再重新计时
作者：@Youngs
时间：2022.10.25
误差来源：每次存储时序均为仿真时序，每15s约2s误差
*/
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int

sbit sda=P2^0;
sbit scl=P2^1;
sbit dula=P2^6;
sbit wela=P2^7;

bit write=0;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
uchar count;
uchar sec;
void Delayus()
{
	;;
}
void Delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
	{
		for(j=110;j>0;j--);
	}
}
void start()//scl高电平sda上升沿
{
	sda=1;
	Delayus();
	scl=1;
	Delayus();
	sda=0;
	Delayus();
}
void stop()//scl高电平上升沿
{
	sda=0;
	Delayus();
	scl=1;
	Delayus();
	sda=1;
	Delayus();	
}
void respo()
{
	uchar i;
	scl=1;
	Delayus();
	while((sda==1)&&(i<255))
		i++;
	//上方while或改为while(sda);等待来到低电平
	//但若始终未等到从设备sda拉低，将卡死
	//故若未收到应答信号，等待1ms后默认已应答
	scl=0;
	Delayus();
}
void Initial()
{
	sda=1;
	Delayus();
	scl=1;
	Delayus();
}
void write_byte(uchar date)
{
	uchar i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		scl=0;
		Delayus();
		sda=CY;
		Delayus();
		scl=1;
		Delayus();
	}
	scl=0;
	Delayus();
	sda=1;
	Delayus();
}
uchar read_byte()//读字节是从sda读，无需形参
{
	uchar i,k;
	scl=0;
	Delayus();
	sda=1;
	Delayus();
	for(i=0;i<8;i++)
	{
		scl=1;
		Delayus();
		k=(k<<1)|sda;
		scl=0;
		Delayus();
	}
	return k;
}
void write_add(uchar address,uchar date)
{
	start();
	write_byte(0xa0);//写元件地址
	respo();
	write_byte(address);
	respo();
	write_byte(date);
	respo();
	stop();
}
uchar read_add(uchar address)
{
	uchar date;
	start();
	write_byte(0xa0);
	respo();
	write_byte(address);
	respo();
	start();
	write_byte(0xa1);
	respo();
	date=read_byte();
	stop();
	return date;
}
void display(uchar bai,uchar shi)
{
	wela=1;
	P0=0x01;
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[bai];
	dula=0;
	P0=0x00;
	Delayms(5);
	
	wela=1;
	P0=0x02;
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[shi];
	dula=0;
	P0=0x00;
	Delayms(5);	
}
void main()
{
	Initial();
	sec=read_add(2);
	if(sec>100)
		sec=0;
	TMOD=0x01;
	EA=1;
	ET0=1;
	TH0=(65535-50000)/256;
	TL0=(65535-50000)%256;
	TR0=1;
	display(0,0);
	while(1)
	{
		//uchar temp;
		display(sec/10,sec%10);
		if(write==1)
		{
			write=0;
			write_add(2,sec);				
			//temp=read_add(2);
			//display(temp/10,temp%10);//尝试读取地址2中数据，而非直接对sec操作，仿真出错
		}
	}
}
void Timer0() interrupt 1
{	
	TH0=(65535-50000)/256;
	TL0=(65535-50000)%256;
	count++;
	if(count==20)
	{
		count=0;
		sec++;
		write=1;
		if(sec==100)
			sec=0;
	}
}	