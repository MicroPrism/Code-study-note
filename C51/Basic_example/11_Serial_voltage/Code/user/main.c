#include "main.h"
uchar code table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0xf8,
0x80,0x90,0x88,0x83,
0xc6,0xa1,0x86,0x8e};
uchar code already[]="Turn on ad!\n";
uchar code close[]="Turn off ad!";
uchar bai,shi,ge;
uchar count;
uchar flag_on,flag_uart,flag_time;
uchar a,ad_val,ad_vo;
void main()
{
	Initial();
	while(1)
	{
		if(flag_uart==1)
		{
			flag_uart=0;//wait next receive
			ES=0;
			TI=1;
			switch(flag_on)
			{
				case 0:
					puts(already);TR0=1;break;
				case 1:
					printf("%s\n",close);TR0=0;break;
				case 2:
					puts("ERROR!\n");break;
			}
			while(!TI);
			TI=0;
			ES=1;
		}
		if(flag_time==1)
		{
			flag_time=0;
			ad_val=get_ad();
			ad_vo=(float)ad_val*5.0/256.0;
			ES=0;
			TI=1;
			printf("The voltage is %f V",ad_vo);
			while(!TI);
			TI=0;
			ES=1;
		}
		Display(ad_val);
	}	
}