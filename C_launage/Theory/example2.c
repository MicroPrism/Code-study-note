#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.�����������Լ��

//���淽����ͬ��������m���ϵ������㹫����

int main()
{
	int m = 0 ;
	int n = 0;
	scanf("%d %d", &m, &n);
	int max = m > n ? n : m;
	while (1)
	{
		if ((m % max == 0) && (n % max == 0))
		{
			printf("%d\n",max);
			break;
		}
		max--;
	}
	return 0;
}

//շת�����

int main()
{
	int m = 0 ;
	int n = 0;
	scanf("%d %d", &m, &n);	//շת���һ�Σ����ɽ����ݰ���С����18%24=18�������ֻ�m=24��n=18
	int t = 0;
	while (m % n)
	{
		t = m % n;//�˴�����ֱ�ӷ���while�ж������
		m = n;
		n = t;
	}
	printf("���Լ��Ϊ��%d\n",n);
	//��С������=m*n/���Լ��
	return 0;
}

//2.��ӡ����-���ܱ�1����������

int main()
{
	int i = 0;
	for (i = 100; i < 200; i++)
	{
		int j = 2;
		for (j=2;j<=i-1;j++)
		{
			if (i % j == 0)
			{
				break;//��������ζ�Ų�������
			}
		}
		if (j == i)
		{
			printf("����%d\n", i);
		}
		j++;
	}
}

//�Ż����������������һ����дΪm=a*b������a<sqrt(m),����Ҷ�ѭ����sqrt��m������
//���⣬����i��ֵʱ������i+=2���ų�����ż��
//
//goto���ֻ����һ���������������ܳ�����
//�����������ѭ��Ƕ�ף�������ʹ��

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("ȥ�����Ÿ�����������\n");
	while (1)
	{
		scanf("%s", input);
		if (strcmp(input,"�ɻ����") == 0)
		{
			printf("���~");
			system("shutdown -a");
			break;
		}
	}
	return 0;
}