#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>//�ַ����⺯��
//�ַ�������һ���ַ���ʹ��˫���ţ�Double Quote�������һ���ַ�����Ϊ�ַ�������ֵ��String Literal��
int main()
{
	char arr[] = "abcdef";//F10-����-����-���ӣ����Է�����7���ַ������һ��Ϊ��������\0��
	char arr1[] = { 'a','b','c' };//{�ڲ�Ϊ�������ַ�������˫�����ַ����������Ǹ��߽׵�����}
	//printf��ӡʱ���᲻ͣ���ֱ����⵽��\0��
	int len = strlen("abc");
	printf("%d\n", len);//���ֵΪ3�������������㵽������
	printf("%d\n", strlen(arr1));
	//arr1Ԫ�ظ���Ϊ3�����ǣ�strlen���㳤����ֱ����⵽0��'\0'Ϊֹ�����������ֵ
	return 0;
}
//�ַ����Ĵ洢ֻ��ʹ����������ַ�ָ�룬char a="abc";�Ǵ����