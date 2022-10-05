#include<stdio.h>
int test()
{
	int a = 0;//创建
	return &a;//返回地址
}
//指针(地址)为形参
int my_strlen1(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;
	}
	return count;
}
//指针相减
int my_strlen2(char* a)
{
	char* pa = a;
	while (*pa != '\0')//此处不能用if，if只循环一次
	{
		pa++;
	}
	return pa - a;
}
//递归
int my_strlen3(char* a)
{
	if (*a != '\0')
	{
		a++;
		return 1 + my_strlen3(a);
	}
	else
	{
		return 0;
	}
}
//例题：统计两个数二进制位不同个数
int comp(int x, int y)
{
	int i = 0, count = 0;
	while (i++ < 32)//曾出错：未自加向后移
	{
		if ((x & 1) != (y & 1))
		{
			x = x >> 1;
			y = y >> 1;
			count++;
		}
	}
	return count;
}
int comp2(int x, int y)
{
	int count = 0;
	int temp = x ^ y;
	while (temp)//循环内移位
	{
		temp = temp >> 1;
		count++;
	}
	return count;
}
//判断是否是2^n--即检测位数中为1的个数
int bin_is_one(int n)
{
	int count = 0;
	while (n & (n - 1))
	{
		count++;
	}
	return count;
}
//1111 n
//1110 n-1
//1110 n
//1101 n-1
//1100 
int bin_is_one1(int n)
{
	int count = 0;
	while (n)
	{
		n = n >> 1;
		count++;
	}
	return count;
}
size_t my_strlen1(const char a[], int sz)//size_t:unsigned int
{
	int i = 0, count = 0;
	for (i = 0; i < sz; i++)
	{
		if (a[i] != '\0')
		{
			count++;
		}
	}
	return count;
}
int my_strlen2(const char* a)//加一个const，就不能修改内容，因此，其鲁棒性/健壮性更好
{
	assert(a != NULL);
	const char* get = a;
	while (*a++ != '\0')
	{
		;
	}
	return a - get - 1;
}