#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
	int age;
	char name[20];
};
void print_arr(int arr[], int sz);
void swap(char* a, char* b, int size);
void bubble_sort(void* base, size_t num, size_t size, int(*cmp)(const char* e1, const char* e2));
int cmp_int(const void* e1, const void* e2);
int cmp_stu_age(const void* e1, const void* e2);
int cmp_stu_name(const void* e1, const void* e2);
//int main()
//{
//	int i = 0, j = 0;
//	int a[10] = { 1,1,2,5,4,6,5,8,7,9 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - i -1; j++)//此处判断条件j < sz - i -1，外层每循环一次剩下需要比较的对数就少1，最多比较sz-1次
//		{
//			if (a[j] < a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j+1]=temp;
//			}
//		}
//	}
//	print_arr(a,sz);
//	return 0;
//}

//void qsort(void* base,size_t num,size_t size,int (*cmp)(const void* e1,const void* e1 )//快速比较函数的定义
//使用空指针可以接收任何数据
//base待排序数据首地址，num变量长度，size单个元素长度，cmp是比较待排序数据元素的函数

int main()
{
	int i = 0, j = 0;
	int a[10] = { 1,1,2,5,4,6,5,8,7,9 };
	int sza = sizeof(a) / sizeof(a[0]);
	//qsort(a, sza, sizeof(a[0]), cmp_int);//qsort为stdlib库的函数，具体的比较函数需要自己定 
	bubble_sort(a, sza, sizeof(a[0]), cmp_int);
	print_arr(a, sza);
	struct stu member[3] = { { 20,"zhangsan" },{30,"lisi"},{40,"wangwu"} };
	int szm = sizeof(member) / sizeof(member[0]);
	qsort(member, szm, sizeof(member[0]), cmp_stu_age);//按照age排序
	qsort(member, szm, sizeof(member[0]), cmp_stu_name);//按照name排序
	return 0;
}
//模拟实现qsort，对  任意类型  均可以排序，一个函数为形参，返回值为整形，通过返回值的正负决定是否进行swap交换
//在比较时，由于不确定传入类型，不能直接认为base+1跨越多少字节，但元素长度size已知，
//只可以通过强制转换char*在偏移i个size字节来指向下一个元素，cmp来判断两个相邻地址大小并 返回值
void bubble_sort(void* base, size_t num, size_t size, int(*cmp)(const char* e1, const char* e2))
{
	int i = 0, j = 0;
	for (i = 0; i < num - 1; i++)//num为数组内元素总个数，同时决定参与比较次数
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (cmp((char*)base + size * j, (char*)base + size * (j + 1)) > 0)
				//cmp只用于比较，使用const其指针不能再改变，真正改变值是通过swap中base加偏移
			{
				swap((char*)base + size * j, (char*)base + size * (j + 1), size);
			}
			//此处void*指针可以指向变量，但不能参与运算，也不能解引用void*p=&a;√  *p；×   p++；×
		}
	}
}
void swap(char* a, char* b, int size)
{
	int i = 0;
	int temp = 0;
	for (i = 0; i < size; i++)
	{
		temp = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = temp;
	}
}
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return  * (int*)e1- * (int*)e2;//此时是e1-e2>0,即为正数时交换，相当于升序
}
int cmp_stu_age(const void* e1, const void* e2)
{
	return (*(struct stu*)e1).age - (*(struct stu*)e2).age;//先进行强制类型转化，转换为结构体指针后再进行指向
}
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp((*(struct stu*)e1).name, (*(struct stu*)e2).name);//先进行强制类型转化，转换为结构体指针后再进行指向
}