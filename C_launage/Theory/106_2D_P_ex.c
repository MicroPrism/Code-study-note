#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�������Ƿ����޸���
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
//���Ҳ�����ű�
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
//�ַ�������
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
//��ӡ
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

//1.�Զ�ά����������в���
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
	//test(a);��ά�����ββ��ܴ���int *p[5]�βΣ��β�Ϊ���ָ������飬���԰�p���Ϊһ��ָ��ָ��5��int*
	//ʵ��a���Ϊ��Ԫ��a[0]��ַ���������Ϊһ��ָ�룬����ָ����5��int������
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