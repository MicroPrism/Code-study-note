#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int ADD(int x, int y)//���庯��
{
	return x + y;
}
int main()
{
	int input = 0;
	printf("ѡ����ɫҩ�軹�Ǻ�ɫҩ�裿\n");
	scanf("%d",&input);
	if (input)
		printf("��ɫҩ��\n");
	else
		printf("��ɫҩ��\n");
	//ѭ��while��do...while��for
	//����-�Զ��庯��-�����൱�������ִ�и��ã������ظ�����

	int a = 0, b = 0;
	scanf("%d,%d",&a,&b);
	printf("%d\n",ADD(a,b));//���ú������һ���������ת������
	
	//����-һ����ͬ����Ԫ�صļ���
	int arr[10] = {1,2,3};//����ȫ��ʼ����ʣ��Ĭ��Ϊ0
	int i = 0;
	while (i < 10)
	{
		printf("%d\n",arr[i]);
		i++;
	}
	return 0;
}