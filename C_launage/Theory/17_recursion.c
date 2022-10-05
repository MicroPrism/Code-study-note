#define _CRT_SECURE_NO_WARNINGS 1
#include"17_recursion.h"
//递归-自身调用，同样的模型，重复用一段程序
//1.依次从前往后打印一个数的个十百位
int main()
{
	print(1234);
	return 0;
}

//递归常见错误--stack overflow，栈溢出
//栈区空间有限，每个函数都分栈区，当函数过多分配的栈帧空间过多而不释放空间会溢出
//因此必须要有跳出条件，防止死递归，逼近条件及判断，不要递归太多次
//死递归只是一直在分配空间而没有释放 

//2.strlen的两种实现
//int main()
//{
//	char arr[] = "like";
//	printf("%d\n", my_strlen1(arr));
//	printf("%d\n", my_strlen2(arr));
//	return 0;
//}

//3.阶乘
//int main()
//{
//	int n = 5;
//	printf("%d\n", Fac(n));
//	return 0;
//}

//4.斐波那契数列
//int main()
//{
//	int n = 3;
//	printf("%d\n", Fibnacci(9));
//	printf("%d\n", Fibonacci(9));
//	return 0;
//}

//5.幂次实现
//int main()
//{
//	double i = 0;
//	double sum = 0;
//	for (i = 1.0; i <= 100; i++)
//	{
//		sum -= (pow(-1, i) * 1.0 / i);//使用pow函数可以实现正负交替
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//6.打印乘法表
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d\t", i, j, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}