#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char password[20] = { 0 };
	scanf("%s", password);//�س��ᴥ��scanf��ȡ�����������س����������123456�س���123456�ᱻscanf��ȡ
	
	int temp = 0;//char�������ASCII������
	while ((temp=getchar())!='\n')
	{
		;//getchar();//�������䣬�ᴦ���\n�س������ǲ��ܴ���123 abc\n��scanf�����ո񡢻س���ֹ������abc\n�޷�����
	}//����һ��ѭ���������������������������
	
	int ch = getchar(); //�س��ᱻgetchar��ȡ
	if (ch == 'N')
	{
		printf("GG");
	}
	else
	{
		printf("OK");
	}
	return 0;
} 