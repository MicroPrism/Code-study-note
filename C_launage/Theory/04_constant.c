#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define N 30//�궨��

//����ö�ٱ�����ö�ٱ�����������������һ��������ֻ�����ӷֺţ������ڲ����ö��ŷָ������Ƿֺ�
enum Sex
{
	Male,//Ĭ��Ϊ0
	Female,//����+1
	secret
};
enum Sex1
{
	Male1,//0
	Female1=10,//10
	secret1//11
};
int main()
{
	//1.����
	3.14;
	'a';
	
	//2.const���εĳ�����
	const int num = 10;
	//��ʱnum�ǳ�������const���κ�������г����ԣ���ζ����ֵ���ܸ��ģ������Ǳ��������ǳ���
	//char ch[num] = {0};��������Ǵ���ģ������Сֻ��Ϊ�������ǳ�����  
	
	//3.#define ����ı�ʶ������
	int n = N;
	printf("%d\n",n);

	//4.ö������-����һһ�оٵĳ���
	enum Sex s = Male;//�������ڲ��������и�ֵ

	printf("%d\n",Male);//���Ϊ0������Famle��secret���ε���
	//�����ڶ���ʱ��enum Sex{ Male=3��...}�趨��ֵ
	//��Sex��Sex1������
	return 0;
}