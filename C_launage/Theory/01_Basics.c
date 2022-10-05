#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//新建文件-空项目-重命名、更改路径-源文件-添加项-新建.cpp-更改后缀为.c
//主函数main函数

int main()//int为返回值类型，main为函数名
{
	printf("hello world\n");//printf为库函数，需要引用头文件
	return 0;
}
//编辑+链接+运行CTRL+f5
//若为vs2010，可能出现程序执行太快，看不到结果，需要设置属性，右击文件名-属性-链接器-系统-子系统，改为控制台
//一个工程中可以有多个.c文件，但只能有一个main

//数据类型
//程序-计算-实际问题最优解
//char-字符；short-短整形；int...
//'a',单引号引出的为字符a