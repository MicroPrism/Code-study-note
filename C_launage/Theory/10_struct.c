#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//结构体描述复杂对象,可以创建新的类型
struct Stu
{
	char name[20];
	int age;
	double score;//double打印时需要使用%f或%lf
};//结构体语句，用以描述对象的多个属性，仅仅是属性

int main()
{
	struct Stu s = { "zhangsan",20,85 };//结构体变量的初始化，结构体！=结构体变量，定义变量时需要对每个成员都定义
	printf("1: %s  %d  %f\n", s.name, s.age, s.score);

	struct Stu* ps = &s;
	printf("2: % s % d % f\n", (*ps).name, (*ps).age, (*ps).score);//指针指向结构体，解引用后调用成员
	printf("3: % s % d % f\n", ps->name, ps->age, ps->score);//指针指向结构体，解引用后调用成员

	return 0;
}