#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
static int keyword_g_val1 = 10;//定义静态全局变量
int keyword_g_val2 = 103;//全局变量

int Add(int a, int b)
{
	return a + b;
}
static int Sub(int a, int b)//static函数只能在源文件（.c）文件内部使用
{
	return a - b;
}