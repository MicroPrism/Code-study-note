#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//���������� + - * / %������%���˱���Ϊ����
	printf("%d\n", 9 / 2);//4
	//tips������/����Ϊ����ʱ��ִ��������������������������
	printf("%f\n", 9.0 / 2);//4.5��������������С��������һ����С��
	printf("%d\n",( - 3) % 2);//-1

	//��λ������>>,<<-�ƶ���Ϊ������λ,����ʱ�涨�Ҳಹ0��ֻ��0
	int a1 = 3;
	int b1 = a1 << 1;//0011
	printf("%d\n", b1);//0110

	//λ������-��λ�룺&����|�����^
	//��ֵ������=��+=��-=��*=��/=��%=��^=��|=��&=
	//��Ŀ������-��������ֻ��һ�������ǡ�-��ֵ��+��ֵ��&ȡ��ַ��sizeof�ֽ�����~��λȡ�����Լ�--������++��*�����á������ͣ�����ǿ��ת������
	//sizeof�Ա������в���ʱ����ʡ�����ţ�sizeof��int����int a��sizeof��a����a���˵Ŀ�ʡ

	int a = 0;
	//~��λȡ��,�����߼�ȡ����
	//0-00000000 ...00000000
	//��λȡ����-11111111...11111111---Ϊ-1�Ĳ�����ʽ�����ʱ��Ҫ��Ϊԭ����ʽ
	//�������ڴ��д��-������ʽ
	//����������ԭ��-����-����
	//���ڸ�����ԭ��-����λ����������λȡ���õ�����-����+1�õ�����
	printf("%d\n",~a); 

	//++a�����Լ��ٵ��ã�a++�ȵ��ã��ٶ�a�Լ�
	//int b=(++a)+(a++)+(a++);���ڴ�����룬ʵ��Ӧ�ò�����

	int b = (int)3.14;//��ʽ���˾��Ȳ��ȣ���Ҫǿ��ת��

	a = 0, b = 1;
	//&&�߼��룬||�߼��������ж��Ƿ�ͬʱ��������
	int e = a && b;//ͬ����Ϊ��
	int f = a || b;//����Ϊ������

	//����������(��Ŀ) exp1��exp2:exp3������ʽ1���������Ϊexp2������Ϊexp3
	int max = a > b ? a : b;
	printf("%d\n",max);

	//���ű���ʽ��exp1,exp2,exp3....�������б���ʽ������������ִ��
	a = 0,b=0;
	int g = (a++, b++, a + b);//���ս��Ϊg=a+b��������ǰ��a++��b++��Ӱ��
	printf("%d\n", g);//���2
	//��������ʽ�Ľ��Ϊ����ʽ�����һ��������м�һЩʽ�ӿ��������ı�һЩֵ�Ĵ�С
	
	//[]�±����ò������������������÷���Ҳ���������޸ĺ������ȼ�
	return 0;
}