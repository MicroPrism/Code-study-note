#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//if..else if ..else���---if��else�ͽ����
int main()
{
	//int�ͺ���ִ��return֮����˳�
	int i = 0;
	scanf("%d", &i);
	if (i<18)
		printf("δ����\n");
	else
	{
		printf("����");
		printf("���Խ�����");
	}
	//if����ж�ʱʹ�õ�ʽ���ʽ�ж� if(2==i)���Ա����жϷ������³���ʧ��

	//switch������ڶ��֧��switch�����α��ʽ��{case ��...}��
	//switchҪ�������α��ʽ��case��Ҫ�������γ������ʽ��case������ǳ���
	int day = 0;
	scanf("%d",&day);
	switch (day)
	{
	case 1:
		printf("����1");
		break;//switch��˳��ִ�У������м���Լ���break������ǰ��֧�������Ǳ����
		//breakֻ�����������switchѡ�����
	case 2:
		printf("����2");
		break;
	case 3:
		printf("����3");
		break;
	case 4:
		printf("����4");
		break;
	case 5:
		printf("����5");
		break;
	case 6:
		printf("����6");
		break;
	case 7:
		printf("����7");
		break;
	default ://Ĭ��ѡ���������ѡ��Χ��
		printf("ERROR!");
		break;
	}
	return 0;
}