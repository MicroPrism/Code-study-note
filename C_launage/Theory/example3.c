#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int sum_n(int m, int n);
int is_flower(int i);
void print(int arr[], int sz);
void move(int arr[], int sz);
//sizeof操作符返回的值为unsigned int
//在进行-1>sizeof(int)的计算时会将-1转化为unsigned int

//1.给定a，计算n项a+aa+aaa+aaaa
int main()
{
	int i = 0, j = 0;
	scanf("%d,%d", &i, &j);
	int sum=sum_n(i, j);
	printf("%d\n", sum);
	return 0;
}

//2.水仙花数
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 1000; i++)
//	{
//		if (is_flower(i))
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}

//3.打印菱形
//int main()
//{
//	int n = 0,i = 0,j = 0;
//	scanf("%d", &n);
//	for (i = 0; i <=n/2 ; i++)//打印上半部分和正中间的一行，主要看i究竟是从0还是从1开始
//	{
//		for (j=0;  j<n/2-i; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//		for (j = 0; j <= n / 2 - i; j++)
//		{
//			printf(" ");
//		}
//		printf("\n");
//	}
//	for (i; i < n; i++)
//	{
//		for (j = 0; j <i-n/2; j++)
//		{
//			printf(" ");
//		}
//		for (j = 0; j < 2 * (n-i-1) + 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//栈溢出属于运行中错误
//ctrl+F5是开始执行不调试

//4.
//int main()
//{
//	//交换奇偶位置 
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr,sz);
//	return 0;
//}
//5;杨辉三角，
/*
			1
		1		1
	1      2       1
  1	   3        3    1
  等效为
  1
  1 1
  1 2 1
  1 3 3 1
  属于二维数组问题，只是某个元素值不同
*/
//int main()
//{
//	int i = 0, j = 0;
//	int a[20][20]={0};
//	for (i = 0; i < 20; i++)
//	{
//		for (j = 0; j < 20; j++)
//		{
//			if ((j == 0)||(i == j))
//			{
//				a[i][j] = 1;
//			}
//			if (i >= 2 && j >= 1)
//			{
//				a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
//			}
//		}
//	}
//	for (i = 0; i < 20; i++)
//	{
//		for (j = 0; j <=i; j++)
//		{
//			printf("%d   ", a[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}
int sum_n(int m, int n)
{
	if (n == 1)
	{
		return m;
	}
	else
	{
		return m * n + sum_n(m * 10, n - 1);
	}
}
int is_flower(int n)
{
	int i = 0, temp = 0;
	int sum = 0, bit = 0, m = n;
	for (i = 0; n >= 1; i++)//判断位数
	{
		n /= 10;
		bit++;
	}
	n = m;//重新赋值，判断位数时n变化了
	for (i = 0; i <= bit; i++)
	{
		sum += pow(n % 10, bit);
		n /= 10;
	}
	if (sum == m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}
void move(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int temp = 0;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2))//纯奇数或者纯偶数防止越界
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 0))
		{
			right--;
		}
		if (left < right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
}