#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct test
{
	double high;
	int weight;
};
struct Stu
{
	struct test no_1;//�ṹ��������԰��������ṹ��
	char name[20];
	char ID[20];
	int age;
}Li_si, Wang_wu;//Li_si,Wang_wuҲΪ�ṹ�����������Ϊȫ�ֽṹ�����
//struct test
//{
//	float high;
//	int weight;
//};//���·�ʱ����ʾδ����

void printf_struct1(struct Stu t)//�ṹ����Ϊ������������ֵ����
{
	printf("%.2f %d %s %s %d", t.no_1.high, t.no_1.weight, t.name, t.ID, t.age);
}
void printf_struct2(struct Stu* t)//�ṹ��ָ����Ϊ������������ַ����
{
	printf("%.2f %d %s %s %d", t->no_1.high, t->no_1.weight, t->name, t->ID, t->age);
}
int main()
{
	struct Stu zhang_san = { {178.82,70},"����","1111111",23 };
	struct Stu* a = &zhang_san;//�ṹ��ָ��
	printf("%.2f\n", zhang_san.no_1.high);//���־�������Ƕ�׵�����
	printf("%.2f\n", a->no_1.high);//ָ��ָ������no_1������.��ӡ����high

	printf_struct1(zhang_san);//��ֵ���ã��β���Ҫ�����µĿռ�
	printf("\n");
	printf_struct2(&zhang_san);//��ַ����
	//�������õĲ���ѹջ�洢���������������ȳ�
	//ÿһ���������ã��������ڴ��ջ�����ٿռ�
	return 0;
}