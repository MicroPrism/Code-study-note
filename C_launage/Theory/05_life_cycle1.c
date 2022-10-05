#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//作用域（scope）与生命周期，变量通常只在一个程序块内有效，局部变量可以理解为临时变量
//全局变量的作用域为整个工程
//生命周期，对于局部定义时开始，出程序块结束；对于全局，定义时开始，直到程序结束

extern int globel;//在一个文件中调用另外一个文件的变量时，需要extern先声明
//globel变量在05_life_cycle2.c文件中定义
int main()
{
	printf("%d\n", globel);
	return 0;
}