 #include "05_main.h"
 	uchar flag_award,flag_back,repeat_count;
	uchar count_T0,count_T1;
	void main()
	{
		Initial();
		while(1)
		{
		  Timer_59s(repeat_count,flag_award,flag_back);
			Restart();
		}
	}
