#include<stdio.h>
int test()
{
	int a = 0;//����
	return &a;//���ص�ַ
}
//ָ��(��ַ)Ϊ�β�
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
//ָ�����
int my_strlen2(char* a)
{
	char* pa = a;
	while (*pa != '\0')//�˴�������if��ifֻѭ��һ��
	{
		pa++;
	}
	return pa - a;
}
//�ݹ�
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
//���⣺ͳ��������������λ��ͬ����
int comp(int x, int y)
{
	int i = 0, count = 0;
	while (i++ < 32)//������δ�Լ������
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
	while (temp)//ѭ������λ
	{
		temp = temp >> 1;
		count++;
	}
	return count;
}
//�ж��Ƿ���2^n--�����λ����Ϊ1�ĸ���
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
int my_strlen2(const char* a)//��һ��const���Ͳ����޸����ݣ���ˣ���³����/��׳�Ը���
{
	assert(a != NULL);
	const char* get = a;
	while (*a++ != '\0')
	{
		;
	}
	return a - get - 1;
}