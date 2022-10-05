#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16整个数组
	printf("%d\n", sizeof(a + 0));//4/8 第一个元素地址
	printf("%d\n", sizeof(*a));//4  *a 数组第一个元素大小
	printf("%d\n", sizeof(a + 1));//4/8第二个元素地址
	printf("%d\n", sizeof(a[1]));//4第二个元素大小

	printf("%d\n", sizeof(&a));//数组地址
	printf("%d\n", sizeof(*&a));//数组地址解引用得到数组，类似于整形变量取地址再解引用得到整形变量
	printf("%d\n", sizeof(&a + 1));//数组地址+1，跳过整个数组，还是地址
	printf("%d\n", sizeof(&a[0]));//首元素地址
	printf("%d\n", sizeof(&a[0] + 1));//首元素地址+1，

	char arr[] = { 'a','b','b','v','d','e' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr + 0));//4/8 第一个元素地址
	printf("%d\n", sizeof(*arr));//1  *a 数组第一个元素大小
	printf("%d\n", sizeof(arr[1]));//1第二个元素大小
	printf("%d\n", sizeof(&arr));//4/8数组地址
	printf("%d\n", sizeof(&arr + 1));//4/8第二个元素地址
	printf("%d\n", sizeof(&a[0] + 1));//首元素地址+1，

	printf("%d\n", strlen(arr));//随机值x，无结束符
	printf("%d\n", strlen(arr + 0));//同上x
	printf("%d\n", strlen(*arr));//错误 ，将常量作为地址，有问题
	printf("%d\n", strlen(arr[1]));//同上
	printf("%d\n", strlen(&arr));//随机值x
	printf("%d\n", strlen(&arr + 1));//随机值y=x-6
	printf("%d\n", strlen(&arr[0] + 1));//随机值z=x-1

	char brr[] = "abcdef";
	printf("%d\n", sizeof(brr));//7
	printf("%d\n", sizeof(brr + 0));//4/8 第一个元素地址
	printf("%d\n", sizeof(*brr));//1  *a 数组第一个元素大小
	printf("%d\n", sizeof(brr[1]));//1第二个元素大小
	printf("%d\n", sizeof(&brr));//4/8数组地址
	printf("%d\n", sizeof(&brr + 1));//4/8第二个元素地址
	printf("%d\n", sizeof(&brr[0] + 1));//首元素地址+1

	printf("%d\n", strlen(brr));//6
	printf("%d\n", strlen(brr + 0));//6
	printf("%d\n", strlen(*brr));//错误 ，将常量作为地址，有问题
	printf("%d\n", strlen(brr[1]));//同上
	printf("%d\n", strlen(&brr));//6
	printf("%d\n", strlen(&brr + 1));//跨越整个数组，随机值
	printf("%d\n", strlen(&brr[0] + 1));//5
	//strlen只收\0影响

	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4/8
	printf("%d\n", sizeof(p + 1));//4/8 第二个元素地址
	printf("%d\n", sizeof(*p));//1   指向的地址元素大小
	printf("%d\n", sizeof(p[0]));//1  p[0]=*（p+0=）0[p] 首地址元素
	printf("%d\n", sizeof(&p));//4/8指针地址
	printf("%d\n", sizeof(&p + 1));//4/8 跳过p的地址
	printf("%d\n", sizeof(&p[0] + 1));//4/8  首元素地址+1

	printf("%d\n", strlen(p));//7
	printf("%d\n", strlen(p + 1));//6
	printf("%d\n", strlen(*p));//错误，会将常量'a'作为地址
	printf("%d\n", strlen(p[0]));//同上  p[0]=*（p+0=）0[p] 首地址元素
	printf("%d\n", strlen(&p));//随机值x
	printf("%d\n", strlen(&p + 1));//随机值y  地址4/8字节，但是不确定&p与&p+1之间的四个字节是否会有\0结束符
	printf("%d\n", strlen(&p[0] + 1));//4/8  首元素地址+1
	return 0;
}