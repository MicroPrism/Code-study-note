void print(int a[3][5], int b, int c)//���鴫��
{
	int i = 0, j = 0;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*a)[5], int b, int c)//�β�Ϊָ��һά�����ָ�룬aΪar�ĵ�һ���׵�ַa=ar[0]��a+1=ar[1]
{
	int i = 0, j = 0;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(a + i) + j));//aΪ�����׵�ַ��a + i����i�еĵ�ַ
		}
		printf("\n");
	}
}
//һά���鴫�κ�������
void test(int arr[]) {};
void test1(int arr[10]) {};//�β�Ϊ���飬�����С���п���
void test2(int* arr) {};//ָ��ָ�������׵�ַ
void test3(int* arr[20]) {};//�β���ʵ����ͬ
void test4(int** arr) {};//ָ������Ҳ������,���ݾ�Ϊָ�룬ָ������Ԫ��int*��ַ��ָ���ַ�ĵ�ַ������ָ��
//��ά���鴫��
void test5(int arr[3][5]) {};
//void test6(int arr[][]) {};
void test7(int arr[][5]) {};//��ά�������β�ʱ���������붨�壬���Բ�֪�������У����Ǳ���֪��ÿ�ж���Ԫ��
void test8(int* arr) {};//����     arrΪ��һ�еĵ�ַ��������ĵ�ַ
void test9(int* arr[5]) {};//����  ָ������
void test10(int(*arr)[5]) {};//����  ָ��5������Ԫ�ص�ָ�룬�պ�ָ��ÿ����
void test11(int** arr) {};//����   ������Ϊ����ĵ�ַ����һ����ַ�����Ƕ�����ַ
int testa()
{
	return 0;
}
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Cot(int(*pf)(int, int))
{
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	return pf(x, y);
}