//MCU1
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define SLAVE 0x02
#define BN 16
uchar rbuf[16];//预留数组尽量给定长度，rbuf[]虽然可以生成文件，但是会报警
uchar code table[16]={"master transmit"};

void Error()
{
	SBUF=0xff;
	while(!TI);
	TI=0;
}
uchar Master(uchar addr,uchar command)
{
	uchar a,i,p;
	while(1)
	{
		SBUF=SLAVE;//送从机地址
		while(TI!=1);
		TI=0;
		while(RI!=1);//等从机应答
		RI=0;
		if(SBUF!=addr)//从机回送地址错，发送复位信号
			Error();
		else
		{
			TB8=0;//主从机地址相同，TB8清0，准备收发数据
			SBUF=command;
			while(TI!=1);
			TI=0;
			while(RI!=1);
			RI=0;
			a=SBUF;//主机发送完指令，读取一次SBUF，从机发送？
			//暂且未知为何使用如下判断？是否是从机回送
			if((a&0x08)==0x08)
			{
				TB8=1;
				Error();
			}
			else
			{
				if(command==0x01)//主机发送
				{
					if((a&0x01)==0x01)//从机准备接收
					{
						do
						{
							p=0;//清空校验位
							for(i=0;i<BN;i++)
							{
								SBUF=table[i];
								p+=table[i];
								while(TI!=1);
								TI=0;
							}
							SBUF=p;
							while(TI!=1);
							TI=0;
							while(RI!=1);
							RI=0;
						}while(SBUF!=0);
						TB8=1;
						return 0;
					}
					else
					{
						if((a&0x02)==0x02)//接收命令，从机发送
						{
							while(1)
							{
								p=0;
								//循环接收数据并存放至数组中
								for(i=0;i<BN;i++)
								{
									while(RI!=1);
									RI=0;
									rbuf[i]=SBUF;
									p+=rbuf[i];//主机中进行累加
								}
								while(RI!=1);
								RI=0;
								if(SBUF==p)//从机发送的校验位==主机校验位
								{
									SBUF=0x00;//主收，从发完成
									while(TI!=1);
									TI=0;
									break;
								}
								else
								{
									SBUF=0xff;//数据错误，发送0FFH，该数据重新收发
									while(TI!=1);
									TI=0;
								}
							}
							TB8=1;
							return 0;
							}
					}
				}
			}
		}
	}
}
void main()
{
	TMOD=0x20;
	TL1=0xfd;
	TH1=0xfd;
	PCON=0x00;
	TR1=1;
	SCON=0xf8;//1111 1000,SM0\SM1,SM2=1,REN=1，TB8=1，串口方式3，SM2拉高，从机监听，允许串口接收，复位
	Master(SLAVE,0x01);
	Master(SLAVE,0x02);
	while(1);
}