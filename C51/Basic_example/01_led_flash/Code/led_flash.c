#include "led.h"
uchar a;
void main()
{
	P1=0xfe;
	while(1)
	{
		//P1=a;
		delay(500);
		P1=_crol_(P1,1);
	}
}