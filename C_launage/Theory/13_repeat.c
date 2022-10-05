#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//循环：while、do...while、for等
int main()
{
	//while与break、continue
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", i);
		i++;
	}//{}程序块是所要执行的语句
	i = 0;
	while (i < 10)
	{
		if (5 == i)
			break;//break跳出当前循环，直接终止循环
		printf("%d\n", i);
		i++;
	}
	i = 0;
	//while (i < 10)
	//{
	//	if (5 == i)
	//		continue;//continue跳出本次循环继续下一次
	//	printf("%d\n", i);
	//	i++;
	//}
	int ch = 0;
	while (((ch = getchar()) != EOF))//getchar是将数据放在缓冲区，然后从缓冲区读数据输出到屏幕，回车也算字符
	{
		putchar(ch);
	}
	return 0;
}