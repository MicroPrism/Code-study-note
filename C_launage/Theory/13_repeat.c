#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//ѭ����while��do...while��for��
int main()
{
	//while��break��continue
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", i);
		i++;
	}//{}���������Ҫִ�е����
	i = 0;
	while (i < 10)
	{
		if (5 == i)
			break;//break������ǰѭ����ֱ����ֹѭ��
		printf("%d\n", i);
		i++;
	}
	i = 0;
	//while (i < 10)
	//{
	//	if (5 == i)
	//		continue;//continue��������ѭ��������һ��
	//	printf("%d\n", i);
	//	i++;
	//}
	int ch = 0;
	while (((ch = getchar()) != EOF))//getchar�ǽ����ݷ��ڻ�������Ȼ��ӻ������������������Ļ���س�Ҳ���ַ�
	{
		putchar(ch);
	}
	return 0;
}