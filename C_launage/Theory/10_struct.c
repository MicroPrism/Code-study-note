#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ṹ���������Ӷ���,���Դ����µ�����
struct Stu
{
	char name[20];
	int age;
	double score;//double��ӡʱ��Ҫʹ��%f��%lf
};//�ṹ����䣬������������Ķ�����ԣ�����������

int main()
{
	struct Stu s = { "zhangsan",20,85 };//�ṹ������ĳ�ʼ�����ṹ�壡=�ṹ��������������ʱ��Ҫ��ÿ����Ա������
	printf("1: %s  %d  %f\n", s.name, s.age, s.score);

	struct Stu* ps = &s;
	printf("2: % s % d % f\n", (*ps).name, (*ps).age, (*ps).score);//ָ��ָ��ṹ�壬�����ú���ó�Ա
	printf("3: % s % d % f\n", ps->name, ps->age, ps->score);//ָ��ָ��ṹ�壬�����ú���ó�Ա

	return 0;
}