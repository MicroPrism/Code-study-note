#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
static int keyword_g_val1 = 10;//���徲̬ȫ�ֱ���
int keyword_g_val2 = 103;//ȫ�ֱ���

int Add(int a, int b)
{
	return a + b;
}
static int Sub(int a, int b)//static����ֻ����Դ�ļ���.c���ļ��ڲ�ʹ��
{
	return a - b;
}