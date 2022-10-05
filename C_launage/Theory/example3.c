#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int sum_n(int m, int n);
int is_flower(int i);
void print(int arr[], int sz);
void move(int arr[], int sz);
//sizeof���������ص�ֵΪunsigned int
//�ڽ���-1>sizeof(int)�ļ���ʱ�Ὣ-1ת��Ϊunsigned int

//1.����a������n��a+aa+aaa+aaaa
int main()
{
	int i = 0, j = 0;
	scanf("%d,%d", &i, &j);
	int sum=sum_n(i, j);
	printf("%d\n", sum);
	return 0;
}

//2.ˮ�ɻ���
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

//3.��ӡ����
//int main()
//{
//	int n = 0,i = 0,j = 0;
//	scanf("%d", &n);
//	for (i = 0; i <=n/2 ; i++)//��ӡ�ϰ벿�ֺ����м��һ�У���Ҫ��i�����Ǵ�0���Ǵ�1��ʼ
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
//ջ������������д���
//ctrl+F5�ǿ�ʼִ�в�����

//4.
//int main()
//{
//	//������żλ�� 
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr,sz);
//	return 0;
//}
//5;������ǣ�
/*
			1
		1		1
	1      2       1
  1	   3        3    1
  ��ЧΪ
  1
  1 1
  1 2 1
  1 3 3 1
  ���ڶ�ά�������⣬ֻ��ĳ��Ԫ��ֵ��ͬ
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
	for (i = 0; n >= 1; i++)//�ж�λ��
	{
		n /= 10;
		bit++;
	}
	n = m;//���¸�ֵ���ж�λ��ʱn�仯��
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
		while ((left < right) && (arr[left] % 2))//���������ߴ�ż����ֹԽ��
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