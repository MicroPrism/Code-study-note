#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu
{
	int age;
	char name[20];
};
void print_arr(int arr[], int sz);
void swap(char* a, char* b, int size);
void bubble_sort(void* base, size_t num, size_t size, int(*cmp)(const char* e1, const char* e2));
int cmp_int(const void* e1, const void* e2);
int cmp_stu_age(const void* e1, const void* e2);
int cmp_stu_name(const void* e1, const void* e2);
//int main()
//{
//	int i = 0, j = 0;
//	int a[10] = { 1,1,2,5,4,6,5,8,7,9 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j = 0; j < sz - i -1; j++)//�˴��ж�����j < sz - i -1�����ÿѭ��һ��ʣ����Ҫ�ȽϵĶ�������1�����Ƚ�sz-1��
//		{
//			if (a[j] < a[j + 1])
//			{
//				int temp = a[j];
//				a[j] = a[j + 1];
//				a[j+1]=temp;
//			}
//		}
//	}
//	print_arr(a,sz);
//	return 0;
//}

//void qsort(void* base,size_t num,size_t size,int (*cmp)(const void* e1,const void* e1 )//���ٱȽϺ����Ķ���
//ʹ�ÿ�ָ����Խ����κ�����
//base�����������׵�ַ��num�������ȣ�size����Ԫ�س��ȣ�cmp�ǱȽϴ���������Ԫ�صĺ���

int main()
{
	int i = 0, j = 0;
	int a[10] = { 1,1,2,5,4,6,5,8,7,9 };
	int sza = sizeof(a) / sizeof(a[0]);
	//qsort(a, sza, sizeof(a[0]), cmp_int);//qsortΪstdlib��ĺ���������ıȽϺ�����Ҫ�Լ��� 
	bubble_sort(a, sza, sizeof(a[0]), cmp_int);
	print_arr(a, sza);
	struct stu member[3] = { { 20,"zhangsan" },{30,"lisi"},{40,"wangwu"} };
	int szm = sizeof(member) / sizeof(member[0]);
	qsort(member, szm, sizeof(member[0]), cmp_stu_age);//����age����
	qsort(member, szm, sizeof(member[0]), cmp_stu_name);//����name����
	return 0;
}
//ģ��ʵ��qsort����  ��������  ����������һ������Ϊ�βΣ�����ֵΪ���Σ�ͨ������ֵ�����������Ƿ����swap����
//�ڱȽ�ʱ�����ڲ�ȷ���������ͣ�����ֱ����Ϊbase+1��Խ�����ֽڣ���Ԫ�س���size��֪��
//ֻ����ͨ��ǿ��ת��char*��ƫ��i��size�ֽ���ָ����һ��Ԫ�أ�cmp���ж��������ڵ�ַ��С�� ����ֵ
void bubble_sort(void* base, size_t num, size_t size, int(*cmp)(const char* e1, const char* e2))
{
	int i = 0, j = 0;
	for (i = 0; i < num - 1; i++)//numΪ������Ԫ���ܸ�����ͬʱ��������Ƚϴ���
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (cmp((char*)base + size * j, (char*)base + size * (j + 1)) > 0)
				//cmpֻ���ڱȽϣ�ʹ��const��ָ�벻���ٸı䣬�����ı�ֵ��ͨ��swap��base��ƫ��
			{
				swap((char*)base + size * j, (char*)base + size * (j + 1), size);
			}
			//�˴�void*ָ�����ָ������������ܲ������㣬Ҳ���ܽ�����void*p=&a;��  *p����   p++����
		}
	}
}
void swap(char* a, char* b, int size)
{
	int i = 0;
	int temp = 0;
	for (i = 0; i < size; i++)
	{
		temp = *(a + i);
		*(a + i) = *(b + i);
		*(b + i) = temp;
	}
}
void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}
int cmp_int(const void* e1, const void* e2)
{
	return  * (int*)e1- * (int*)e2;//��ʱ��e1-e2>0,��Ϊ����ʱ�������൱������
}
int cmp_stu_age(const void* e1, const void* e2)
{
	return (*(struct stu*)e1).age - (*(struct stu*)e2).age;//�Ƚ���ǿ������ת����ת��Ϊ�ṹ��ָ����ٽ���ָ��
}
int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp((*(struct stu*)e1).name, (*(struct stu*)e2).name);//�Ƚ���ǿ������ת����ת��Ϊ�ṹ��ָ����ٽ���ָ��
}