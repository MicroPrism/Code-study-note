#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//仅查找是否有无该数
int search(int a[][3], int r, int c, int s)
{
	int x = 0, y = c - 1;
	while ((x < r) && (y >= 0))
	{
		if (a[x][y] < s)
		{
			x++;
		}
		else if (a[x][y] > s)
		{
			y--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
//查找并输出脚标
int search1(int a[][3], int* r, int* c, int s)
{
	int x = 0, y = *c - 1;
	while ((x < *r) && (y >= 0))
	{
		if (a[x][y] < s)
		{
			x++;
		}
		else if (a[x][y] > s)
		{
			y--;
		}
		else
		{
			*r = x;
			*c = y;
			return 1;
		}
	}
	return 0;
}
//字符串左旋
void string_left_rotate(char* a, int count)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		char temp = *(a + i);
		*(a + i) = *(a + i + 1);
		*(a + i + 1) = temp;
	}
}
//打印
void print(const char* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c", *(arr + i));
	}
}
void test(int*p[5])
{
	;
}

//1.对二维有序数组进行查找
int main()
{
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int x = 3, y = 3;
	int wait_ser = 0;
	scanf("%d", &wait_ser);
	int ret = search1(a, &x, &y, wait_ser);
	if(ret)
	{
		printf("yes %d  %d",x,y);
	}
	else
	{
		printf("no %d  %d", x, y);
	}
	//test(a);二维数组形参不能传至int *p[5]形参，形参为存放指针的数组，可以把p理解为一级指针指向5个int*
	//实参a理解为首元素a[0]地址，可以理解为一级指针，但是指向是5个int的数组
	return 0;
}

//int main()
//{
//	char arr[] = { 'a','b','c','d','e' };
//	int x = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	scanf("%d", &x);
//	string_left_rotate(arr,x);
//	print(arr,sz);
//	int a[4][5] = { {1},{2},{3,4},5,6 };
//	test(a);
//	return 0;
//}