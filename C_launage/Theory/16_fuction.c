//����������Ϊ���������飬���Էֱ��ע�Ͳ鿴Ч��
#define _CRT_SECURE_NO_WARNINGS 1
#include"16_fuction.h" //���������Զ��庯����
//��������-�⺯�����Զ��庯�����Զ��庯����д��������ʱĬ�Ϸ���int
//��������Ƕ�׵��ã����ǲ���Ƕ�׶���
//ͬ���ģ������ķ���ֵ������Ϊ���ֱ�ӵ���

//��������
//����������ȷ���������ͣ����������������
//��������һ�����ʹ��֮ǰ������ͷ�ļ���
//����һ��.h�ļ�ר�����ں�������
int main()
{
	test();//�Զ��庯�������ں�ʱ����Ҫ������
	return 0;
}

//int main()//���ֵ
//{
//	int i = 0, j = 0;
//	scanf("%d %d", &i, &j);
//	int max = get_max(i, j);
//	printf("%d\n", max);
//}

//int main()//�ж�����
//{
//	int first = 0, over = 0;
//	int count_prime = 0;
//	scanf("%d %d", &first, &over);
//	count_prime=is_prime(first, over);
//	printf("\n%d\n", count_prime);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int key = 7,flag=0;
//	int sz = sizeof(arr) / sizeof(arr[0])-1;
//	if ((flag = baniary_search(arr, key, sz))!=-1)
//	{
//		printf("\n%d\n",flag);
//	}
//	else
//	{
//		printf("�Ҳ���\n");
//	}
//	return 0;
//}