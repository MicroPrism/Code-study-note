#include "main.h"
void main()
{
	uchar val,flag;
	Initial();
	while(1)
	{
		if(flag==0)
		{
			val+=5;
			P0=val;
			if(val==255)
			{
				flag=1;
				beep=1;
				Delay(100);
				beep=0;
			}
			Delay(50);
		}
		else
		{
			val-=5;
			P0=val;
			if(val==0)
			{
				flag=0;
				beep=1;
				Delay(100);
				beep=0;
			}
			Delay(50);
		}
	}
}