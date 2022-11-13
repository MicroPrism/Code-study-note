# C51提高篇部分

## 1.定时器

基础部分曾使用方式1(TMOD=0x10),设计定时器中断计时，也使用方式2(TMOD=0x20),设定串行通信波特率。

回顾串行通信：（波特率受定时器T1影响）

| 方式0 | 波特率f~osc~/12       |
| ----- | --------------------- |
| 方式1 | (2^SMOD^/32)*T1溢出率 |
| 方式2 | (2^SMOD^/64)*f~osc~   |
| 方式3 | (2^SMOD^/32)*T1溢出率 |

### 1.1 方式0

对于方式0，TMOD=0x00，为13位计数；TL0的低5位与TH0高8位可用，TL0的高3位不使用。TL0低5位溢出时，向TH0进位，TH0溢出向TF0进位，申请中断。

对方式0，最多计数2^13^=8192个数。设机器周期T~cy~，希望每次申请中断时间间隔为t，需要计数次数为N=t/T~cy~

TH0=(8192-N)/32,TL0=(8192-N)%32;

注意，方式0最大值为8192，最大计时8192us=9ms，单次计时可选择5ms。对于11.0592MHz晶振，计算得N=4608。

```C
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit led=P1^0;
uchar timer_count;
void main()
{
    TMOD=0x00;
    TH0=(8192-4068)/32;
    TL0=(8192-4068)%32;
    EA=1;
    ET0=1;
    TR0=1;
    while(1)
    {
        if(timer_count==200)
        {
            timer_count=0;
            led=~led;
        }
    }
}
void Timer0() interrupt 1
{
    TH0=(8192-4068)/32;
    TL0=(8192-4068)%32;
    timer_count++;
}
```

由于TL0只用低5位，因此赋初值时需要/2^5^,即/或%32.

### 1.2 方式2

方式0、1需要在中断函数中重装初值，必然影响精度，方式2自动重装初值避免软件重装带来的时间误差，提高时间精度，但长时间定时依然会产生误差。

方式2更适合用作精确脉冲信号发生器，但此时的晶振要求为12的整数倍，机器周期才没有误差。

12MHz晶振，每个机器周期为1us，8位计256机器周期就会溢出，若使用11.0592MHz，机器周期将有误差(1.0851us)，且随时间误差会越来越大。

其初值的计算与方式0.1完全类似，机器周期T~cy~，单次计时t，需要N=t/T~cy~

TH0=TL0=(256-N),例如单次计时250机器周期(250/271.275us),则累计4000/3686次将计1s。

```C
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit led=P1^0;
uint timer_count;//uhar 0-255，由于要计3686次，需要使用uint
void main()
{
    TMOD=0x02;
    TH0=6;
    TL0=6;
    EA=1;
    ET0=1;
    TR0=1;
    while(1)
    {
        if(timer_count==4000)//若为11.0592MHz，计3686次
        {
            timer_count=0;
            led=~led;
        }
    }
}
void Timer0() interrupt 1
{
    timer_count++;//只需计次即可
}
```

### 1.3 方式3

方式3只使用T0，将T1设为方式3时，T1不计数。

对于T0方式3，T0将分为两个双八位赋值，低8位溢出后TF0置1，申请中断。高八位将占用定时器T1的标志位TF1与TR1，因此T0设定为方式3时，T1不可使用中断，但是可做波特率发生器。

```C
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit led1=P1^0;
sbit led2=P1^1;
uint timer_count1,timer_count2;//uhar 0-255，由于要计3686次，需要使用uint
void main()
{
    TMOD=0x03;
    TH0=6;
    TL0=6;
    EA=1;
    ET0=1;
    ET1=1;
    TR0=1;
    TR1=1;
    while(1)
    {
        if(timer_count1>=3686)//若为11.0592MHz，计3686次
        {
            timer_count1=0;
            led1=~led1;
        }
        if(timer_count2>=1843)//若为11.0592MHz，计3686次
        {
            timer_count2=0;
            led2=~led2;
        }
    }
}
void Timer0() interrupt 1
{
    TL0=6;
    timer_count1++;//只需计次即可
}
void Timer1() interrupt 3//定时器1中断被用于T0方式3高八位
{
    TH0=6;
    timer_count2++;//只需计次即可
}
```

**由于死循环内有两个判断，不排除两个条件同时达标的可能，若均采用==判断，则在count1==3686执行后，count2可能=1844，将少执行一次，判断时序的影响导致冲突。**

### 1.4 计数器

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/51机器周期.jpg)

机器周期包含6个状态周期，12个节拍，包括S1P1、S1P2、S2P1……S6P2。

指令周期:执行一条指令所需时间，以机器周期为单位，乘除为4个机器周期、其余为单周期或双周期。

在计数器情况下，单片机对外部信号进行采样（P3.4、P3.5），输入信号产生1到0的负跳变时，计数+1。

确定一次跳变需要2个机器周期（24个振荡周期），即在当前周期S5P2采样，下一个S5P2再次采样，并于再下一个机器周期S3P1计数。因此外部输入计数脉冲频率要小于1/24振荡周期，外部电平必须保持1个机器周期，12振荡。

+ 占空比：Duty Cycle，在一串理想脉冲序列中，正脉冲持续时间与总周期的比值。

```C
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula=P2^6;
sbit wela=P2^7;
uchar code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
void Delay(uint xms)
{
    uint i,j;
    for(i=xms;i>0;i++)
    {
        for(j=110;j>0;j++)
            ;
    }
}
void Display(uchar shi,uchar ge)
{
    P0=0x00;
    wela=1;
    P0=0x01;
    wela=0;
    P0=0x00;
    dula=1;
    P0=table[shi];
    dula=0;
    Delay(5);
    
    P0=0x00;
    wela=1;
    P0=0x02;
    wela=0;
    P0=0x00;
    dula=1;
    P0=table[ge];
    dula=0;
    Delay(5);
}
uint Read()
{
    uchar t1,th1,th2;
    uint val;
    while(1)//循环读取TH0的值，确保TL0没有进位 
    {
        //在读取TH0后的瞬间TL0若有进位1111 1111->0000 0000,读取将出错
        th1=TH0;
        t1=TL0;
        th2=TH0;
        if(th1==th2)
        {
            break;
        }
    }
    val=th1*256+t1;
    return val;
}
void main()
{
    uchar a,b;
    uint num;
    TMOD=0x05;//0000 0101 C/T=1,计数器，方式1
    TH0=0;
    TL0=0;
    TR0=1;
    while(1)
    {
        num=read();
        if(num>=100)
        {
            num=0;
            TH0=0;
            TL0=0;
        }
        a=num/10;
        b=num%10;
        Display(a,b);
    }
}
```

## 2.串口通信

### 2.1 方式0

方式0通信与方式1类似，不过方式0仅为8位同步移位寄存器，扩展输入并行口或输出并行口，而非进行多机通信的。数据收发均是低位在先，高位在后，波特率固定位f~osc~/12。发送时，SBUF为并行进入，串行输出的寄存器，通过RXD输出。接收时，SBUF为串行输入并行输出。

+ 发送：TI=0，数据移入SBUF，RXD发送位数据，TXD发送同步脉冲，发送完时TI=1，申请中断，软件清0。
+ 接收：REN=1，RI=0，串行数据由RXD输入，TXD发送同步脉冲，发送完成RI=1，申请中断，软件清0。

```C
//串口方式0，间隔循环发送0xAA,示波器观察3.0与3.1口
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
void Delay(uint xms)
{
    uint i,j;
    for(i=xms;i>0;i--)
    {
        for(j=110;j>0;j--)
            ;
    }
}
void main()
{
    SCON=0;
    EA=1;
    ES=1;
    TI=0;
    while(1)
    {
        SBUF=0xAA;
        Delay(1);
    }
}
void Ser() interrupt 4
{
    TI=0;
}
```

### 2.2 方式2、方式3

方式2/3为11位异步通信口，唯一区别是传输速率不同，TXD发RXD收。起始位1位，数据位9位（含附加位TB8/RB8），一位停止位，1帧11位。

方式2波特率为晶振1/32或1/64。方式3波特率受T1溢出率影响。

TB8为发送第9位，RB8为接收第9位，用于模式2、3，模式1中，若SM2=0，则RB8存放接收到的停止位，模式0时不使用。

```C
//串口方式2，间隔循环发送0xAA,示波器观察3.0,此设计针对TX-1C开发板
#include <reg51.h>
#define uchar unsigned char
#define uint unsigned int
void Delay(uint xms)
{
    uint i,j;
    for(i=xms;i>0;i--)
    {
        for(j=110;j>0;j--)
            ;
    }
}
void main()
{
    SM0=1;
    SM1=0;
    TB8=0;
    
    EA=1;
    ES=1;
    TI=0;
    while(1)
    {
        SBUF=0xAA;
        Delay(1);
    }
}
void Ser() interrupt 4
{
    TI=0;
}
```

示波器显示：RB8=0时，10 01010101 0 1，显示4个凸起；RB8=1时，10 01010101 1 1，显示3个凸起。

### 2.3 双机通信

1m内称为短距离通信，1000米左右称为长距离通信，更长的需要加入无线通信设备。

细分：TTL通信，RS232C通信，RS422A通信，RS485通信。

#### 2.3.1 TTL互联

A机TXD直接接B机RXD，B机TXD接A机RXD，但是双机需要共地，系统电源地线接至一起。

双机电源共地，目的是确定相同的参考值，统一双机高低电平。若不做共地，数据将传输失败。

#### 2.3.2 RS232C

RS232规定数据终端(DTE)与数据通信设备(DCE)之间的物理接口。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/RS232接口.png)

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/RS232引脚说明.png)

运用RS232标准进行两个单片机通信时，只需要用到RXD，TXD和GND，单片机上要有RS232转TTL模块。

RS232电平传输数据时，比TTL传输远，一般不超过15m，也要求双方共地。

RS232电平转换时采用单端输出输入，传输过程中，干扰和噪声会混在正常信号中，为提高信噪比，RS232标准需要采用较大的电压摆幅。

#### 2.3.3 RS422A

RS422A为双端平衡驱动，其中一条线为1，另一条一定为0，比采用单端不平衡驱动放大倍数大一倍，差分接收器可以从地线分辨200mv电位差，还可抵消传输过程的噪声与干扰，大大减弱地线干扰与电磁干扰。

#### 2.3.4 RS485

RS422A用于全双工，RS485用于半双工，RS485采用两线间的电压表示逻辑1或0。，收发双方只需要两条线。由于采用差动通道，干扰抑制性较好，阻抗低，无接地问题，传输距离可达1200米，速率1Mbps。

#### 2.3.5 远程无线通信

适用于通信距离过长的情况，几十千米，基本用不到。。

## EX1.MCU1键盘扫描，MCU2码管显示

### 2.4 多机通信

多机系统通常为总线式主从结构，一主多从。

51串行方式2，方式3适合此种方式。

多机通信，协议规则：

+ 所有从机SM2置1，处于地址接收帧状态
+ 主机发送地址帧，8位地址，第9位为数据地址区分标志，置1表示为地址帧。从机接收到地址帧后将与本机地址比较，地址相符的从机SM2=0，表示选中，将本机地址发送回主机表示应答。
+ 从机发送数据结束后，需要发送1位校验位，置TB8=1，表示发送结束。
+ 主机接收数据时，先判断数据接收标志RB8，RB8=1表示数据传输结束，并比较此帧校验和，若一致回送00H，从机复位，错误回送0FFH，从机重发数据。若RB8=0，数据存放至暂存区SBUF，并准备接收下一帧信息。
+ 主机收到地址后，确认地址是否相符，若地址不符，发送复位信号TB8=1；地址相符则TB8清0，开始发送数据。
+ 从机收到复位命令时，SM2=1，回到地址监听状态，否则将开始收发数据。

编程顺序：

1. 主机地址联络信号：00H，01H，02H....（数据），0FFH（复位）

2. 主机编码：01：主机命令从机接收数据，02H，从机发送数据

3. | D7   | D6   | D5   | D4   | D3   | D2   | D1   | D0   |
   | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
   | ERR  | 0    | 0    | 0    | 0    | 0    | TRDY | RRDY |

状态字ERR=1，收到非法命令，TRDY，从机发送准备就绪，RXDY，从机接收准备就绪。

