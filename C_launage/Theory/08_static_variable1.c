#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define SUM(a,b) (a+b)//宏定义
typedef unsigned int u_int;//类型重命名，取别名
//*********************声明区***********************
extern int keyword_g_val1;//即便声明，也无法调用工程中其他.c文件内的变量
keyword_g_val2;//extern与变量类型int均可以省略
int Add(int a, int b);//函数声明
extern int Sub(int a, int b);//即使声明也无法使用static定义的函数
//**********************函数区**********************
int test1()
{
	int a = 1;
	a++;
	printf("%d\t", a);
	return 0;
}
int test2()
{
	static int a = 1;
	a++;
	printf("%d\t", a);
	return 0;
}
int main()
{
	//关键字，c语言已经定义好的，不可用于其他用途
	//局部变量：均为auto形式，省略掉
	//register 寄存器关键字
	register int x = 100;//建议num的值存放在寄存器中，目前编译器可以自动识别
	//计算机中数据可以存放在内存、硬盘、网盘、高速缓存、寄存器（cpu中，调用快）中，越往后造价越高速度越快。

	//signed，有符号；unsigned，无符号
	//include、define不是关键字，而是预处理指令 

	//typedef，即typedefine,类型重定义
	unsigned int num = 0;
	u_int max = 0;

	//计算机内部的3个区与存放内容
	//栈区：局部变量、函数的参数
	//堆区：动态内存分配的
	//静态区：全局变量、static修饰的局部变量
	
	//static-静态变量
	//1.修饰局部变量：自定义函数test1与test2的区别，static改变变量a的存储类型，改变了存储周期
	int i = 0;
	while (i < 10)
	{
		test1();//自定义函数test1，输出10个2，打印局部变量a
		printf("\n");
		test2();
		i++;
	}
	//2.修饰全局变量：见08_static_variable2.c文件内容
	//static修饰后，变成了内部链接属性，修饰前是有外部链接属性
	 //printf("%d\n", keyword_g_val1);//静态全局变量无法解析
		printf("%d\n", keyword_g_val2);
	//3.修饰函数:static int Sub(int a, int b){}，效果同全局变量
	printf("%d\n", Add(2, 3));
	//printf("%d\n", Sub(2, 3));//同上

	//define定义宏-#define SUM(a,b) (a+b),宏变量只会在编译之前做简单的替换，遇见乘除可能会出现问题，非要用的话记得加括号
	printf("%d\n",3*SUM(2,3));
	return 0;
}