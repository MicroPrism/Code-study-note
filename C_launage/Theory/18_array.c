#define _CRT_SECURE_NO_WARNINGS 1
#include"18_array.h"

//&������---��������ʾ�������飬ȡ��������������ĵ�ַ
//sizeof������--������������Ĵ�С

//��������ͬ����Ԫ�صļ��ϣ�int arr[8];������СΪ8������
//����Ϊ����ʱ���У���ʹconstʹ�������г�����Ҳ����
int main()
{
	//int ��
	int arr1[10] = { 1,2,2,3,3,4,5,6,4,5 };//��ȫ��ʼ��
	int arr2[10] = { 1,2,2,3,3 };//���ֳ�ʼ���������Զ���ACSCII��0
	int arr3[] = { 1,2,3,4,5 };//���ݸ���ȷ�����鳤��

	//char��
	char arr4[5] = { 'a','b','c' };//���ֳ�ʼ��
	char arr5[] = { 'a','b','c' };
	char arr6[5] = "bit";//b i t \0 0��˫����Ĭ�ϲ�������
	char arr7[] = "bit";//b i t \0������Ϊ4

	printf("%s\n", arr4);
	printf("%s\n", arr5);//����5��ȫ���壬����ȷ�����޽�����
	printf("%s\n", arr6);
	printf("%d\n", strlen(arr5));//15
	printf("%d\n", sizeof(arr5) / sizeof(arr5[0]));//3
	printf("%d\n", strlen(arr6));//3,strlen�����һ�������������ĸ���
	printf("%d\n", sizeof(arr6) / sizeof(arr6[0]));//5��sizeof���������ֽ��ܳ���
	printf("%d\n", strlen(arr7));//3
	printf("%d\n", sizeof(arr7) / sizeof(arr7[0]));//4

	int arr8[10] = { 0 };//����ȫ��ʼ��
	arr8[1] = 1;
	arr8[2] = 2;
	int* parr8 = arr8;//��������Ϊ��Ԫ�ص�ַ
	//%p-ʮ�����ƴ�ӡ��ַ
	printf(" arr8:\t\t%p\n", arr8);
	printf(" &arr8:\t\t%p\t\n", &arr8);
	printf(" &arr8[0]:\t%p\t\n", &arr8[0]);//arr8��&arr8��&arr8[0]�������׵�ַ
	printf(" arr8+1:\t%p\n", arr8 + 1);//�����׵�ַ+1�����ս������4
	printf(" &arr8+1:\t%p\n", &arr8 + 1);//�����ַ+1,���ս������0x28=40
	printf("\n");

	printf(" parr8+1:\t%p\t\n", parr8 + 1);//ָ����������sizeof����λ��4�ֽڣ��������ƫ�ƺ�ĵ�ַ��ʵ����parr8��ָ��û��
	printf(" parr8:\t\t%p\t\n", parr8);
	printf(" ++parr8:\t%p\t\n", ++parr8);//��ַ��δ�ı䣿��
	printf(" parr8:\t\t%p\t\n", parr8);//++��parr��ָ�����仯
	printf(" *(++parr8):\t%d\t\n", *(++parr8));//
	printf(" *parr8 + 1:\t%d\t\n", *parr8 + 1);//�Ƚ�������+1
	printf(" *(parr8 + 1):\t%d\t\n", *(parr8 + 1));//��ͬ�ڴ�ӡarr[1]

	char arr[20] = {0};
	scanf("%s", arr);
	rever_array(arr);
	printf("%s\n", arr);
	rever_array1(arr);
	printf("%s\n", arr);
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	double c = my_Pow(a, b);//���⣺�������ֵ��ԭ��.h�ļ���������ʱ��δ�����ʹ�int��Ϊdouble
	printf("%f\n",c);

	//��ά������ȻΪm��n�У�������Ȼ��˳�����У��ȵ�һ���ٵڶ���...��
	//�����ʼ��
	int arr1[3][4] = { 1,2,3,4,1,2,3,4,1,2,3,4 };//��ȫ��ʼ��
	int arr2[3][4] = { 1,2,3,4,1,2,3 };//����ȫ��ʼ������ȱ����0
	//�ֿ��ʼ��
	int arr3[3][4] = { {1,2},{3,4},{1,2,3 } };//���г�ʼ������ȱ����0

	int arr4[][3] = { {1,2},{2,3},{1} };//����ֻ�����еĸ��������Զ�ʶ���ж����У���ֻȷ���У���ȷ��ÿ�ж��ٸ�
	//���ݵ�ַ���������Կ�����ָ��ȥ���� 

	//���ڶ�ά���飬ÿһ�е��������������Ϊarr[0]��arr[1]��arr[2]...
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//Bubble_arrange1(arr,sz);
	Bubble_arrange2(arr, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}