#define _CRT_SECURE_NO_WARNINGS 1
#include"102.pointer.h"
int main()
{
	{
		//ָ��ָ��������׵�ַ
		char* a = "hello bit";
	}
	{
		//�����ǿ����µ��ڴ棬ָ��ͬ
		char a[] = "aas";
		char b[] = "ass";//a��=b
		//"aas"�ǳ����ַ�������ϵͳ����Ψһ�ڴ棬��ʹ���ָ��Ҳָ���׵�ַ���޷�ͨ���������޸���ֵ
		//*c=��b���Ǵ���ģ�������ǰ������const
		const char* c = "aas";
		const char* d = "ass";//c==d
	}

	//ָ������--���ָ�������
	{
		int a[]={1,2,3};
		int b[]={2,2,3};
		int c[]={3,2,3};
		int* arr[3]={a,b,c};//�������ָ�������
		int i = 0, j = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d  ", *(arr[i] + j));
				printf("%d  ", arr[i][j]);//�൱�ڶ�ά����
			}
			printf("\n");
		}
	}
	//����ָ��--ָ�������ָ��
	{
		int arr[10] = { 1,2,3,4 };
		int (* parr)[10]= & arr;//*parr˵����ָ�룬[10]˵����10��Ԫ�أ�����Ϊint
		//[]�����ȼ���*�ߣ�����������ţ�*parr����*��int���int* ��parr��Ϊָ�����顣
		double* d[10];
		double* (*pd)[10] = &d;//ָ��ָ�����������ָ�룬�京��10��Ԫ�أ�ÿ��Ԫ��Ϊdouble*

		int* p1 = arr;//����һ������arr��&arrֵ��ͬ�������岻ͬ��ǰ�����׸�Ԫ�ص��׵�ַ���������Ƕ���������ȡַ
		int(*p2)[10] = &arr;
		//��ʱp1+1-p1=4,�ƶ�һ������p2+1-p2=40�ƶ�һ����������
		printf("%p\n", p1+1);
		printf("%p\n", p2 + 1);
	}
	{
		int ar[3][5] = { {1,2,3},{4,5,6},{7,8,9,9} };
		print(ar, 3, 5);
		print2(&ar, 3, 5);

		int(*parr[10])[5];//parr�����飬���10������ָ��Ԫ�أ�ÿ��Ԫ�أ�����ָ�룩ָ����5��Ԫ�ص���������
		//�Ա�int��*a��[5];parr���൱����10������ָ��a
	}
	//һά���鴫��
	{
		int arr[10] = { 0 };
		int* arr2[20] = { 0 };//ָ������
		test(arr);
		test1(arr);
		test2(arr);
		test3(arr2);
		test4(arr2);
	}
	//��ά���鴫��
	{
		//������ָ��ʱ�����β�ʵ��һ�£���ַһ�£�����һ�£���ָ��һ��Ԫ�أ�����ָ�������У�һ��ά�ȣ�
		int arr[3][5] = { 0 };
		test5(arr);
		test7(arr);
		test8(arr);
		test9(arr);
		test10(arr);
		test11(arr);
	}

		/*
		int arr[10]={0};
		int* parr=a;

		int* arr[10]={0};
		int* (*parr)[10]=&a;

		int(*pArr[3])(int, int) = {NULL,Add,Sub};//����ָ�������������������÷�[]��ϣ��γ�����
		int(*(*ppArr)[3])(int, int) = &pArr;//ָ��������Ԫ�صĺ���ָ�������ָ��

		*/

	{
		int arr[10] = { 1,2,3,4,5,6,7,8,9 };
		arr;
		&arr;
		int a = 1;
		int* pa = &a;
		int** ppa = &pa;
		printf("%d\n", **ppa);
		int b[10] = { 1,2,3,5,4,6,7,8,9 ,10};
		int* pb = b;
		int(*pbb)[10] = &b;
		printf("%p\n", pbb);
		printf("%p\n", pb);
		printf("%p\n", pbb+1);//�������ַ+1Ϊ�ε����׵�ַ��һ�ĵ�ַ,����ָ��ʱʧ��
		printf("%p\n", pb+1);
		int(*pc)[4] = NULL;//����ָ�룬����ָ����壬ָ�������������
	}
	//����ָ��--ָ������ָ�룬��ź�����ַ��ָ��
	{
		printf("%p\n", testa);
		printf("%p\n", &testa);//�����������ͬ�����Ǻ����ĵ�ַ
		int(* ptesta)(int, int) = &testa;//����������ָ��ָ������;����ָ��ָ������ַ��ָ��ĺ����β�����Ҫȷ������������ҲҪ��֪
		int (*pf)(int, int) = &Add;
		printf("%d\n", ( * pf)(3, 5));//�������������ͬ�����Ҫʹ��*pf���������
		printf("%d\n", Add(3, 5));
		printf("%d\n", pf(3, 5));

		(* (void(*)())0)();
		//(void(*)())0--��0ǿ��ת��Ϊ����ָ��
		//(* (void(*)())0)--�����õõ�����
		//(* (void(*)())0)()--�Ժ������е���
		void(*signal(int, void(*)(int)))(int);
		//signal(int, void(*)(int))Ϊһ������������Ϊ�����뺯��ָ��
		//ʣ���Ϊvoid(*  )(int)�����䷵��������һ������ָ��
		typedef void(*pfun_t)(int);//����������void(*)(int)Ϊpfun_t�������﷨����ֻ�ܷ���������
		pfun_t signal(int, pfun_t);//�����ڻ�Ԫ
		//typedef void(*pfun_t)(int)====typedef void(*)(int) pfun_t���� pfun_tΪ������
		//�ڶ��ֽ��л�Ԫ֮���� void(*)(int) signal(int, void(*)(int))�������������﷨�涨��void(*signal(int, void(*)(int))���������ڲ�)(int)
	}
	//����ָ������
	{
		int(*pf1)(int, int) = Add;
		int(*pf2)(int, int) = Sub;
		int(*pArr[3])(int, int) = {NULL,Add,Sub};//����ָ�����飬��ź���ָ�� 
		//����ָ��������Դ�Ŷ���ṹ��ͬ�ĺ�������������
		int i = 0,j = 0;
		int model = 0;
		int output = 0;
		scanf("%d %d", &i, &j);
		printf("ѡ��ģʽ\n");
		scanf("%d", &model);
		if (model < 4 && model > 0)
		{
			output = pArr[model](i, j);
			printf("The output=%d\n",output);
		}
		else
		{
			printf("Error!");
		}
	}
	//�ص�����---����ָ����Ϊ��һ���������β�,����ָ���ڵ���ʱʹ�ñ��������ߺ���������
	//���������ص������൱��������������ͨ��ָ�� ��ӵ��ã�Cot(Sub)ʵ���ǵ���Sub
	//����ָ��������ͬ������ int(*pf[2])(int,int)={NULL,Add,Sub};
	int model = 0;
	scanf("%d", &model);
	switch (model)
	{
	case 1:
		printf("%d\n", Cot(Add));
		break;
	case 2:
		printf("%d\n", Cot(Sub));
		break;
	default:
		printf("Error!");
		break;
	}

	return 0;
}