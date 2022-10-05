#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct test
{
	double high;
	int weight;
};
struct Stu
{
	struct test no_1;//结构体变量可以包含其他结构体
	char name[20];
	char ID[20];
	int age;
}Li_si, Wang_wu;//Li_si,Wang_wu也为结构体变量，而且为全局结构体变量
//struct test
//{
//	float high;
//	int weight;
//};//在下方时会显示未定义

void printf_struct1(struct Stu t)//结构体作为函数参数，传值调用
{
	printf("%.2f %d %s %s %d", t.no_1.high, t.no_1.weight, t.name, t.ID, t.age);
}
void printf_struct2(struct Stu* t)//结构体指针作为函数参数，传址调用
{
	printf("%.2f %d %s %s %d", t->no_1.high, t->no_1.weight, t->name, t->ID, t->age);
}
int main()
{
	struct Stu zhang_san = { {178.82,70},"张三","1111111",23 };
	struct Stu* a = &zhang_san;//结构体指针
	printf("%.2f\n", zhang_san.no_1.high);//这种就类似于嵌套调用了
	printf("%.2f\n", a->no_1.high);//指针指向内容no_1，再用.打印内容high

	printf_struct1(zhang_san);//传值调用，形参需要创建新的空间
	printf("\n");
	printf_struct2(&zhang_san);//传址调用
	//函数调用的参数压栈存储：先入后出，后入先出
	//每一个函数调用，都会在内存的栈区开辟空间
	return 0;
}