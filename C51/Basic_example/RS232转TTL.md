# RS232转TTL

早期MC1488，75188可以实现**TTL->RS232.**MC1489,75189可以实现**RS232->TTL.**

目前MAX232，MAX202，HIN232可以实现**RS232<->TTL**互转。

## 1.分立元件实现

MAX232将TTL电平从0-5V转换到3~ 15V或者-3~ -15V。

<img src="https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/20221021125904.png" style="zoom: 50%;" />

**原理说明：**

**TTL发送：**TXD为5V高电平时，Q1截止，PCTXD内部高阻，且PCRXD输出电压为-3~ -15V，受二极管D1与R2、C7作用，此时PCRXD被拉低到-3~ -15V，计算机接收1。

TXD为低电平时，Q1导通PCRXD将由空闲低电平被拉至高电平，若用中断接收将会产生中断，满足条件。

**RS232发送：**PCTXD=-3~ -15V低电平时，D2导通，三极管中间脚电压拉高至0V，Q2截止，RXD被拉高至5V高电平。

PCTXD变高时，Q2导通，RXD拉低。

**无论是谁转谁，都有一个三极管起作用，另外有两个参考电压(T->R:5v、-3~ -15V)(R->T:VCC、GND)，其余就是电阻限流，二极管保护电路，调整电压。**

## 2.MAX232实现

MAX232内部有两路接收器和驱动器IC芯片，内部有电源电压变换器，可以把输入+5V电压变为RS232需要的+10V电压。

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/MAX232引脚.jpg)

C1、C2、C3、C4，V+、V-为电源变换部分，Vcc要加对地去耦电容C5，防止噪声干扰。

C1-C4取1uF/16V的电解电容，实际可以使用0.1uF的非极性瓷片电容，同时尽量靠近MAX232，提高抗干扰能力。

MAX共有2路接收，使用时仅用一路即可

+ T1IN(11)：TTL-TXD
+ T1OUT(14)：RS232-RXD(2)

+ R1IN(13)：RS232-TXD(3)
+ R1OUT(12)：TTL-RXD

![](https://raw.githubusercontent.com/MicroPrism/All-image/main/C51/MAX232接线.jpg)

无论如何接线，只需要保证TTL与计算机RS232的TXD与RXD相互对应，但是受限于开发板不能直接插到电脑上，开发板上会附带一个RS232，需要通过交叉线或者平行线连接至PC机。

此时注意，开发板与其上的232接线，选取合适的线连接PC机，使其满足上方的要求。