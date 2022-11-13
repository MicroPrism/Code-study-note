//一块板扫描，一块板显示数据
//MCU1
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
uchar Rece_flag;
void Send_char(uchar);
void Delay(xms)
{
    uint i,j;
    for(i=xms;i>0;i--)
        for(j=110;j>0;j--);
}
//此段注释部分是在扫描函数内部发送，检测到按键之后发送标号
//下一次检测到之前将一直保持
/*void mat_key()
{
    uchar temp;
    uchar key_number;
    P1=0xfe;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xfe;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xee:key_number=0;break;
                case 0xde:key_number=4;break;
                case 0xbe:key_number=8;break;
                case 0x7e:key_number=12;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
         Send_char(key_number);
    }
    
    P1=0xfd;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xfd;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xed:key_number=1;break;
                case 0xdd:key_number=5;break;
                case 0xbd:key_number=9;break;
                case 0x7d:key_number=13;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
         Send_char(key_number);
    }
    
    P1=0xfb;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xfb;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xeb:key_number=2;break;
                case 0xdb:key_number=6;break;
                case 0xbb:key_number=10;break;
                case 0x7b:key_number=14;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
         Send_char(key_number);
    }
    P1=0xf7;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xf7;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xe7:key_number=3;break;
                case 0xd7:key_number=7;break;
                case 0xb7:key_number=11;break;
                case 0x77:key_number=15;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
        Send_char(key_number);
    }
}*/
//uchar 扫描函数需要注意，默认返回值不建议设定为0，第n次检测发送编号x
//若第n+1次未检测到键盘按下，将返回默认值0，导致观察时只能看到0，不设返回值仿真正常
uchar mat_key()
{
    uchar temp;
    uchar key_number;
    P1=0xfe;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xfe;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xee:key_number=0;break;
                case 0xde:key_number=4;break;
                case 0xbe:key_number=8;break;
                case 0x7e:key_number=12;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
         return key_number;
    }
    
    P1=0xfd;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xfd;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xed:key_number=1;break;
                case 0xdd:key_number=5;break;
                case 0xbd:key_number=9;break;
                case 0x7d:key_number=13;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
         return key_number;
    }
    
    P1=0xfb;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xfb;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xeb:key_number=2;break;
                case 0xdb:key_number=6;break;
                case 0xbb:key_number=10;break;
                case 0x7b:key_number=14;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
         return key_number;
    }
    P1=0xf7;
    temp=P1&0xf0;
    if(temp!=0xf0)
    {
		Delay(10);
        P1=0xf7;
        temp=P1&0xf0;
        if(temp!=0xf0)
        {
            temp=P1;
            switch(temp)
            {
                case 0xe7:key_number=3;break;
                case 0xd7:key_number=7;break;
                case 0xb7:key_number=11;break;
                case 0x77:key_number=15;break;
            }
        }
        while((temp&0xf0)!=0xf0)
        {
            temp=P1;
        }
        return key_number;
    }
		//return 0;
}
void Send_char(uchar number)
{
    SBUF=number;
    while(!TI);
    TI=0;
}
void main()
{
    TMOD=0x20;//T1方式2设置波特率
    TH1=0xfd;
    TL1=0xfd;
    SCON=0x40;//设定方式1串口通信
    EA=1;
    ES=1;
    TR1=1;
    while(1)
    {
			Send_char(mat_key());
    }
}
