#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int a[] = { 1,2,3,4 };
	printf("%d\n", sizeof(a));//16��������
	printf("%d\n", sizeof(a + 0));//4/8 ��һ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*a));//4  *a �����һ��Ԫ�ش�С
	printf("%d\n", sizeof(a + 1));//4/8�ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(a[1]));//4�ڶ���Ԫ�ش�С

	printf("%d\n", sizeof(&a));//�����ַ
	printf("%d\n", sizeof(*&a));//�����ַ�����õõ����飬���������α���ȡ��ַ�ٽ����õõ����α���
	printf("%d\n", sizeof(&a + 1));//�����ַ+1�������������飬���ǵ�ַ
	printf("%d\n", sizeof(&a[0]));//��Ԫ�ص�ַ
	printf("%d\n", sizeof(&a[0] + 1));//��Ԫ�ص�ַ+1��

	char arr[] = { 'a','b','b','v','d','e' };
	printf("%d\n", sizeof(arr));//6
	printf("%d\n", sizeof(arr + 0));//4/8 ��һ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*arr));//1  *a �����һ��Ԫ�ش�С
	printf("%d\n", sizeof(arr[1]));//1�ڶ���Ԫ�ش�С
	printf("%d\n", sizeof(&arr));//4/8�����ַ
	printf("%d\n", sizeof(&arr + 1));//4/8�ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(&a[0] + 1));//��Ԫ�ص�ַ+1��

	printf("%d\n", strlen(arr));//���ֵx���޽�����
	printf("%d\n", strlen(arr + 0));//ͬ��x
	printf("%d\n", strlen(*arr));//���� ����������Ϊ��ַ��������
	printf("%d\n", strlen(arr[1]));//ͬ��
	printf("%d\n", strlen(&arr));//���ֵx
	printf("%d\n", strlen(&arr + 1));//���ֵy=x-6
	printf("%d\n", strlen(&arr[0] + 1));//���ֵz=x-1

	char brr[] = "abcdef";
	printf("%d\n", sizeof(brr));//7
	printf("%d\n", sizeof(brr + 0));//4/8 ��һ��Ԫ�ص�ַ
	printf("%d\n", sizeof(*brr));//1  *a �����һ��Ԫ�ش�С
	printf("%d\n", sizeof(brr[1]));//1�ڶ���Ԫ�ش�С
	printf("%d\n", sizeof(&brr));//4/8�����ַ
	printf("%d\n", sizeof(&brr + 1));//4/8�ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(&brr[0] + 1));//��Ԫ�ص�ַ+1

	printf("%d\n", strlen(brr));//6
	printf("%d\n", strlen(brr + 0));//6
	printf("%d\n", strlen(*brr));//���� ����������Ϊ��ַ��������
	printf("%d\n", strlen(brr[1]));//ͬ��
	printf("%d\n", strlen(&brr));//6
	printf("%d\n", strlen(&brr + 1));//��Խ�������飬���ֵ
	printf("%d\n", strlen(&brr[0] + 1));//5
	//strlenֻ��\0Ӱ��

	char* p = "abcdef";
	printf("%d\n", sizeof(p));//4/8
	printf("%d\n", sizeof(p + 1));//4/8 �ڶ���Ԫ�ص�ַ
	printf("%d\n", sizeof(*p));//1   ָ��ĵ�ַԪ�ش�С
	printf("%d\n", sizeof(p[0]));//1  p[0]=*��p+0=��0[p] �׵�ַԪ��
	printf("%d\n", sizeof(&p));//4/8ָ���ַ
	printf("%d\n", sizeof(&p + 1));//4/8 ����p�ĵ�ַ
	printf("%d\n", sizeof(&p[0] + 1));//4/8  ��Ԫ�ص�ַ+1

	printf("%d\n", strlen(p));//7
	printf("%d\n", strlen(p + 1));//6
	printf("%d\n", strlen(*p));//���󣬻Ὣ����'a'��Ϊ��ַ
	printf("%d\n", strlen(p[0]));//ͬ��  p[0]=*��p+0=��0[p] �׵�ַԪ��
	printf("%d\n", strlen(&p));//���ֵx
	printf("%d\n", strlen(&p + 1));//���ֵy  ��ַ4/8�ֽڣ����ǲ�ȷ��&p��&p+1֮����ĸ��ֽ��Ƿ����\0������
	printf("%d\n", strlen(&p[0] + 1));//4/8  ��Ԫ�ص�ַ+1
	return 0;
}