//MCU2
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define SLAVE 0x02
#define BN 16
uchar trbuf[16];
uchar rebuf[16];
bit trdy;//从机发送状态位
bit rrdy;//从机接收状态位
void str();
void sre();
void main()
{
	TMOD=0x20;
	TH1=0xfd;
	TL1=0xfd;
	PCON=0x00;
	TR1=1;
	SCON=0xf0;//方式2，监听模式，串行接收中断允许
	ES=1;
	EA=1;
	while(1)
	{
		trdy=1;
		rrdy=1;
	}
}
void ssio() interrupt 4//串口中断
{
	uchar a;
	RI=0;
	ES=0;
	if(SBUF!=SLAVE)
	{
		ES=1;
		goto reti;
	}
	SM2=0;
	SBUF=SLAVE;//回送从机地址
	while(TI!=1);
	TI=0;
	while(RI!=1);
	RI=0;
	if(RB8==1)//从机RB8=1？
	{
		SM2=1;
		ES=1;
		goto reti;
	}
	a=SBUF;
	if(a==0x01)//从机接收
	{
		if(rrdy==1)//从机接收准备就绪
		{
			SBUF=0x01;//回送准备状态
		}
		else
		{
			SBUF=0x00;//回送复位
		}
		while(TI!=1);
		TI=0;
		while(RI!=1);
		RI=0;
		if(RB8==1)//从机RB8=1？
		{
			SM2=1;
			ES=1;
			goto reti;
		}
		sre();//接收数据
	}
	else if(a==0x02)//从机发送，主机接收
	{
		if(trdy==1)//从机就绪
		{
			SBUF=0x02;
		}
		else
		{
			SBUF=0x00;
		}
			while(TI!=1);
			TI=0;
			while(RI!=1);
			RI=0;
			if(RB8==1)//从机RB8=1？
			{
				SM2=1;
				ES=1;
				goto reti;
			}
			str();//发送函数
	}		
	else
	{
		SBUF=0x80;//从机状态字最高位ERR=1，命令出错。
		while(TI!=1);
		TI=0;
		SM2=1;
		ES=1;
	}
	reti: ;
}
void str()
{
	uchar p,i;
	trdy=0;//从机发送准备标志位清0
	do
	{
		p=0;
		for(i=0;i<BN;i++)
		{
			SBUF=trbuf[i];
			p+=trbuf[i];
			while(TI!=1);
			TI=0;
		}
		SBUF=p;
		while(TI!=1);
		TI=0;
		while(RI!=1);
		RI=0;
		}while(SBUF!=0);//该while语句为主机回送的校验和比较数据，
	SM2=1;
	ES=1;
}
void sre()//从机接收函数
{
	uchar p,i;
	rrdy=0;
	while(1)
	{
		p=0;
		for(i=0;i<BN;i++)
		{
			while(RI!=1);
			RI=0;
			rebuf[i]=SBUF;
			p+=rebuf[i];
		}
		//接收函数不需要发送校验位，即SBUF=p;
		while(RI!=1);
		RI=0;
		if(SBUF==p)
		{
			SBUF=0x00;
			break;
		}
		else
		{
			SBUF=0xff;
			while(TI!=1);
			TI=0;
		}
	}
	SM2=1;
	ES=1;
}		