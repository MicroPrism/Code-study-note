#define _CRT_SECURE_NO_WARNINGS 1
#include"17_recursion.h"
//�ݹ�-������ã�ͬ����ģ�ͣ��ظ���һ�γ���
//1.���δ�ǰ�����ӡһ�����ĸ�ʮ��λ
int main()
{
	print(1234);
	return 0;
}

//�ݹ鳣������--stack overflow��ջ���
//ջ���ռ����ޣ�ÿ����������ջ������������������ջ֡�ռ��������ͷſռ�����
//��˱���Ҫ��������������ֹ���ݹ飬�ƽ��������жϣ���Ҫ�ݹ�̫���
//���ݹ�ֻ��һֱ�ڷ���ռ��û���ͷ� 

//2.strlen������ʵ��
//int main()
//{
//	char arr[] = "like";
//	printf("%d\n", my_strlen1(arr));
//	printf("%d\n", my_strlen2(arr));
//	return 0;
//}

//3.�׳�
//int main()
//{
//	int n = 5;
//	printf("%d\n", Fac(n));
//	return 0;
//}

//4.쳲���������
//int main()
//{
//	int n = 3;
//	printf("%d\n", Fibnacci(9));
//	printf("%d\n", Fibonacci(9));
//	return 0;
//}

//5.�ݴ�ʵ��
//int main()
//{
//	double i = 0;
//	double sum = 0;
//	for (i = 1.0; i <= 100; i++)
//	{
//		sum -= (pow(-1, i) * 1.0 / i);//ʹ��pow��������ʵ����������
//	}
//	printf("%lf\n", sum);
//	return 0;
//}

//6.��ӡ�˷���
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