#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define N 30//宏定义

//定义枚举变量，枚举变量整个大括号属于一个变量，只在最后加分号，变量内部采用逗号分隔，而非分号
enum Sex
{
	Male,//默认为0
	Female,//依次+1
	secret
};
enum Sex1
{
	Male1,//0
	Female1=10,//10
	secret1//11
};
int main()
{
	//1.常量
	3.14;
	'a';
	
	//2.const修饰的常变量
	const int num = 10;
	//此时num是常变量，const修饰后变量具有常属性，意味着其值不能更改，但还是变量，而非常量
	//char ch[num] = {0};此条语句是错误的，数组大小只能为常量而非常变量  
	
	//3.#define 定义的标识符常量
	int n = N;
	printf("%d\n",n);

	//4.枚举类型-可以一一列举的常量
	enum Sex s = Male;//可以用内部的数进行赋值

	printf("%d\n",Male);//输出为0，后续Famle、secret依次递增
	//可以在定义时，enum Sex{ Male=3，...}设定初值
	//见Sex与Sex1的区别
	return 0;
}