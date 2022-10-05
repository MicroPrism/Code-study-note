#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//无论是何种循环，均需要注意判断语句是否是赋值，单个等号 语句

int main()
{
	//while-对于语句较多的情况，初始化部分、判断部分、增量部分分隔会较远，不适合程序改动
	int i = 1;
	while (i<=10)
	{
		i++;
	}//中间加入continue之后，可能会跳过增量语句导致死循环

	//for-三部分集成度较高
	for (i = 0; i <= 10; i++)
	{
		;
	}//加入continue不会出现死循环
	//for循环体内不要改变变量的值，可能出现死循环
	for (;; )//省略判断语句后始终视为真，省略初始化语句后，数据不会再重置
	{
		break;
	}

	//do...while-先执行，后判断，相同的条件下，要比while和for多循环一次 
	return 0;
}