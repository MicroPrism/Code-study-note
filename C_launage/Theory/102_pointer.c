#define _CRT_SECURE_NO_WARNINGS 1
#include"102.pointer.h"
int main()
{
	{
		//指针指向数组的首地址
		char* a = "hello bit";
	}
	{
		//数组是开辟新的内存，指向不同
		char a[] = "aas";
		char b[] = "ass";//a！=b
		//"aas"是常量字符串，在系统中有唯一内存，即使多个指针也指向首地址，无法通过解引用修改其值
		//*c=‘b’是错误的，可以在前方加上const
		const char* c = "aas";
		const char* d = "ass";//c==d
	}

	//指针数组--存放指针的数组
	{
		int a[]={1,2,3};
		int b[]={2,2,3};
		int c[]={3,2,3};
		int* arr[3]={a,b,c};//存放整型指针的数组
		int i = 0, j = 0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				printf("%d  ", *(arr[i] + j));
				printf("%d  ", arr[i][j]);//相当于二维数组
			}
			printf("\n");
		}
	}
	//数组指针--指向数组的指针
	{
		int arr[10] = { 1,2,3,4 };
		int (* parr)[10]= & arr;//*parr说明是指针，[10]说明有10个元素，类型为int
		//[]的优先级比*高，如果不加括号（*parr），*与int结合int* ，parr成为指针数组。
		double* d[10];
		double* (*pd)[10] = &d;//指向指针数组的数组指针，其含有10个元素，每个元素为double*

		int* p1 = arr;//对于一个数组arr、&arr值相同但是意义不同，前置是首个元素的首地址，而后者是对整个数组取址
		int(*p2)[10] = &arr;
		//此时p1+1-p1=4,移动一个整形p2+1-p2=40移动一个整形数组
		printf("%p\n", p1+1);
		printf("%p\n", p2 + 1);
	}
	{
		int ar[3][5] = { {1,2,3},{4,5,6},{7,8,9,9} };
		print(ar, 3, 5);
		print2(&ar, 3, 5);

		int(*parr[10])[5];//parr是数组，存放10个数组指针元素，每个元素（数组指针）指向含有5个元素的整型数组
		//对比int（*a）[5];parr里相当与有10个数组指针a
	}
	//一维数组传参
	{
		int arr[10] = { 0 };
		int* arr2[20] = { 0 };//指针数组
		test(arr);
		test1(arr);
		test2(arr);
		test3(arr2);
		test4(arr2);
	}
	//二维数组传参
	{
		//函数传指针时保持形参实参一致，地址一致，类型一致，是指向一个元素，还是指向数组行（一个维度）
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

		int(*pArr[3])(int, int) = {NULL,Add,Sub};//函数指针数组变量名先与解引用符[]结合，形成数组
		int(*(*ppArr)[3])(int, int) = &pArr;//指向有三个元素的函数指针数组的指针

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
		printf("%p\n", pbb+1);//？数组地址+1为何等于首地址加一的地址,定义指针时失误
		printf("%p\n", pb+1);
		int(*pc)[4] = NULL;//数组指针，属于指针家族，指向的是整个数组
	}
	//函数指针--指向函数的指针，存放函数地址的指针
	{
		printf("%p\n", testa);
		printf("%p\n", &testa);//两个语句结果相同，都是函数的地址
		int(* ptesta)(int, int) = &testa;//类似于数组指针指向数组;函数指针指向函数地址，指向的函数形参类型要确定，返回类型也要已知
		int (*pf)(int, int) = &Add;
		printf("%d\n", ( * pf)(3, 5));//以下三者输出相同，如果要使用*pf必须加括号
		printf("%d\n", Add(3, 5));
		printf("%d\n", pf(3, 5));

		(* (void(*)())0)();
		//(void(*)())0--将0强制转换为函数指针
		//(* (void(*)())0)--解引用得到函数
		//(* (void(*)())0)()--对函数进行调用
		void(*signal(int, void(*)(int)))(int);
		//signal(int, void(*)(int))为一个函数，参数为整形与函数指针
		//剩余的为void(*  )(int)表明其返回类型是一个函数指针
		typedef void(*pfun_t)(int);//类型重命名void(*)(int)为pfun_t，但是语法上其只能放在括号内
		pfun_t signal(int, pfun_t);//类似于换元
		//typedef void(*pfun_t)(int)====typedef void(*)(int) pfun_t其中 pfun_t为新名称
		//第二局进行换元之后有 void(*)(int) signal(int, void(*)(int))，但是受限于语法规定，void(*signal(int, void(*)(int))放在括号内部)(int)
	}
	//函数指针数组
	{
		int(*pf1)(int, int) = Add;
		int(*pf2)(int, int) = Sub;
		int(*pArr[3])(int, int) = {NULL,Add,Sub};//函数指针数组，存放函数指针 
		//函数指针数组可以存放多个结构相同的函数，大大简化运算
		int i = 0,j = 0;
		int model = 0;
		int output = 0;
		scanf("%d %d", &i, &j);
		printf("选择模式\n");
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
	//回调函数---函数指针作为另一个函数的形参,函数指针在调用时使用变量名或者函数名即可
	//如下例，回调函数相当于在其他函数内通过指针 间接调用，Cot(Sub)实际是调用Sub
	//函数指针数组有同样功能 int(*pf[2])(int,int)={NULL,Add,Sub};
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