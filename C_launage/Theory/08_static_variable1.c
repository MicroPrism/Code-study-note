#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define SUM(a,b) (a+b)//�궨��
typedef unsigned int u_int;//������������ȡ����
//*********************������***********************
extern int keyword_g_val1;//����������Ҳ�޷����ù���������.c�ļ��ڵı���
keyword_g_val2;//extern���������int������ʡ��
int Add(int a, int b);//��������
extern int Sub(int a, int b);//��ʹ����Ҳ�޷�ʹ��static����ĺ���
//**********************������**********************
int test1()
{
	int a = 1;
	a++;
	printf("%d\t", a);
	return 0;
}
int test2()
{
	static int a = 1;
	a++;
	printf("%d\t", a);
	return 0;
}
int main()
{
	//�ؼ��֣�c�����Ѿ�����õģ���������������;
	//�ֲ���������Ϊauto��ʽ��ʡ�Ե�
	//register �Ĵ����ؼ���
	register int x = 100;//����num��ֵ����ڼĴ����У�Ŀǰ�����������Զ�ʶ��
	//����������ݿ��Դ�����ڴ桢Ӳ�̡����̡����ٻ��桢�Ĵ�����cpu�У����ÿ죩�У�Խ�������Խ���ٶ�Խ�졣

	//signed���з��ţ�unsigned���޷���
	//include��define���ǹؼ��֣�����Ԥ����ָ�� 

	//typedef����typedefine,�����ض���
	unsigned int num = 0;
	u_int max = 0;

	//������ڲ���3������������
	//ջ�����ֲ������������Ĳ���
	//��������̬�ڴ�����
	//��̬����ȫ�ֱ�����static���εľֲ�����
	
	//static-��̬����
	//1.���ξֲ��������Զ��庯��test1��test2������static�ı����a�Ĵ洢���ͣ��ı��˴洢����
	int i = 0;
	while (i < 10)
	{
		test1();//�Զ��庯��test1�����10��2����ӡ�ֲ�����a
		printf("\n");
		test2();
		i++;
	}
	//2.����ȫ�ֱ�������08_static_variable2.c�ļ�����
	//static���κ󣬱�����ڲ��������ԣ�����ǰ�����ⲿ��������
	 //printf("%d\n", keyword_g_val1);//��̬ȫ�ֱ����޷�����
		printf("%d\n", keyword_g_val2);
	//3.���κ���:static int Sub(int a, int b){}��Ч��ͬȫ�ֱ���
	printf("%d\n", Add(2, 3));
	//printf("%d\n", Sub(2, 3));//ͬ��

	//define�����-#define SUM(a,b) (a+b),�����ֻ���ڱ���֮ǰ���򵥵��滻�������˳����ܻ�������⣬��Ҫ�õĻ��ǵü�����
	printf("%d\n",3*SUM(2,3));
	return 0;
}