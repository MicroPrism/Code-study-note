#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//���Լ���-��Ҫ����ʽ�ĵ���
//���Ի�������
//���ִ���--��������--ȷ������ԭ��--�������취-��������-���²���
//Debug--���԰汾���������ֵ�����Ϣ���ļ���Ը���
//release--���а汾�������˸����Ż��������ڴ����С�������ٶ������ŵ�

int main()
{
	int i = 0;
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < sz; i++)
	{
		arr[i] = i + 1;//���öϵ������Ϊ�����ϵ� 
	}
	return 0;
}

//windows����-ѡ��debug
//��ݼ�F5���������ԡ�F9������/���߶ϵ㣬������Ӷϵ����ֱ������û������Ķϵ�
//F11���Խ��뺯���ڲ�

//����-����-�ϵ㣬���Բ鿴���жϵ㣬ͬʱ���Թ�ѡʱ���öϵ���Ч
//����-����-��ջ�����Բ鿴�����߼�������˼·
//����ʱ�������Ӧ�ò���ʲô��������ʵ�ʽ������ƫ����ҵ�������

void my_strcpy1(char* destination, char* source)
{
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = *source;
}
void my_strcpy2(char* destination, char* source)
{
	while (*source != '\0')
	{
		*destination++ = *source++;
	}
	*destination = *source;//��ӽ�����
}
void my_strcpy3(char* destination, char* source)//����������ֿ�ָ�룬�����û������
{
	assert(source != NULL);//���ԣ�assert.h
	assert(destination != NULL);//����,��ֹ���ֿ�ָ��
	while (*destination++ = *source++)//�ж������Ϊ��ֵ��䣬����������ʱ�ȸ�ֵ��Ȼ��'\0'������ѭ������������
	{
		;
	}
}
void my_strcpy4(char* destination, const char* source)
{
	assert(source != NULL);
	assert(destination != NULL);
	while (*destination++ = *source++)//�ж�������д���������������ַ�������⣬���Ǽ�const֮�����д��������뱨��
	{
		;
	}
}
char* my_strcpy5(char* destination, const char* source)
{
	assert(source != NULL);
	assert(destination != NULL);
	char* temp = destination;
	while (*destination++ = *source++)//�ж�������д���������������ַ�������⣬���Ǽ�const֮�����д��������뱨��
	{
		;
	}
	return temp;
}
//int main()
//{
//	//���´��������ѭ��
//	//���Իᷢ��a[12]=0ʱ��iͬ����Ϊ0
//	//ԭ�򣺾ֲ�������ʹ��ʱ��ջ����ռ��ȷ���ߵ�ַ��iΪ�ߵ�ַ��arrΪ�͵�ַ�����Խ�����ǡ��Խ�絽i������ģ�����ѭ��
//	//vc6.0-i������arr�����0������
//	//Linux gcc-���1������
//	//vs2013-2019-�����������
//
//	//int i = 0;
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	////�����int i=0�������ڴ˴��ȷ���arr���ٷ���i�����л����������ѭ��
//	//for (i = 0; i <= 12; i++)
//	//{
//	//	arr[i] = 0;
//	//	printf("hh\n");
//	//}
//
//	//������Ҫ��ҲҪ����Ԥ��bug
//	//1.��������
//	//2.bug��
//	//3.Ч�ʸ�
//	//4.�ɶ��Ժ�
//	//5.��ά���Ժ�
//	//6.ע������
//	char arr1[20] = "XXXXXXXXXXX";
//	char arr2[20] = "XXXXXXXXXXX";
//	char arr3[] = "hello";
//	my_strcpy3(arr1, arr3);
//	//my_strcpy3(arr1, NULL);//������ʹ��ʹ��assart��ᱨ��
//	//my_strcpy3(NULL, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy5(arr2, arr3));//����һ��ָ�룬�ַ���ӡ
//	return 0;
//}