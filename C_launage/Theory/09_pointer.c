#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//指针，就是地址与内容的关系；比如地图上划分为省市区再到小区门牌，可以精确找到住户
//内存编号原则：32位机、64位机，即地址线的条数，通过电位不同确定0、1，即将电位信息转化为了数字信息
//每一种序列、组合对应一个地址，2^32bit位，/8得到2^29byte，/1024得到524288KB，/1024得到512MB=0.5GB
//一个内存单元是一个字节，1byte

int main()
{
	int a = 0;//定义时分配存储空间大小，连续n个，n为类型所占字节大小
	printf("%p\n",&a);
	int* pa = &a;//pa用于存放地址，c语言中pa是指针变量
	//*说明pa是指针变量，int说明pa指向int型变量，指向什么类型就说明指针是什么类型

	//地址的目的不是仅仅为了取地址，而是为了使用地址内的内容
	*pa = 20;//该语句就修改了地址内的内容，pa里存放的是地址，需要解引用才能调用内容

	//指针是用来存放地址的，指针所占空间取决于地址存储需要多大空间，32位机(x86环境)32bit=4byte，大小为4字节，x64环境为8字节
	printf("%d\n", sizeof(char*));
	printf("%d\n", sizeof(int*));
	printf("%d\n", sizeof(short*));
	printf("%d\n", sizeof(long*));
	printf("%d\n", sizeof(long long*));
	return 0;
}