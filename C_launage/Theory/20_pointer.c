#define _CRT_SECURE_NO_WARNINGS 1
#include"20_pointer.h"
//指针变量：存放地址的变量 
//指针类型决定了指针解引用的权限，int型解引用4字节，char1字节，使用char无法改变int变量的值
int main()
{
	{
		int arr[10] = { 0 };
		int* p = arr;
		char* pc = arr;
		//以下结果不同，指针+1即跳过一个什么类型的字节大小，int跳4，char跳1
		printf("%p\n", p);
		printf("%p\n", p + 1);
		printf("%p\n", pc);
		printf("%p\n", pc + 1);
	}
	{
		int i;
		int a[10] = { 0 };
		int* pa = a;//若为字符指针char* pa=a;循环赋值时并没有把数组给赋值，而是把a[10]前10个字节给置1
		for (i = 0; i < 10; i++)
		{
			*(pa + 1) = 1;//pa+i指向第i个元素
		}
	}

	//野指针：指向位置是不可知的/地址不是有主的
	{
		//1.指针未初始化
		int* p0;//局部变量不初始化，默认随机值
		////*p = 20;非法访问内存
		//2.指针越界
		int i = 0;
		int arr[10] = { 0 };
		int* p1 = arr;
		for (i = 0; i <= 10; i++)
		{
			*p1 = i;
			p1++;//当循环10次指向a[10]，越界生成野指针
		}
		//3.空间释放
		int* p2 = test();//返回的是局部变量a的地址，返回之后变量a就释放了
		*p2 = 0;//p2不再指向一个已知变量，成为野指针
		//避免方式：变量创建完就要初始化
		//指针初始化：1.指向一个已知变量 2.初始化为空指针
		int a = 0;
		int* p3 = &a;
		int* p4 = NULL;
		//*p4 = 10;//空指针无法赋值
	}

	//指针比较
	
	{
		int a[5]={1,2,3,4,5};
		int* pa;
		for (pa = &a[0]; pa < &a[5];)
		{
			printf("%d\n", *pa);
			pa++;//指针移动pa++就是指针+整数，移动一个类型单位
			
		}
		printf("%d\n", &a[4] - &a[0]);//结果为4，即相差的单元数
	}

	//指针比较函数例子

	{
		char a[] = "abc";
		int sum  = my_strlen1(a);//指针
		int sum1 = my_strlen2(a);
		int sum2 = my_strlen3(a);
		printf("%d\n", sum);
		printf("%d\n", sum1);
		printf("%d\n", sum2);
	}

	{
		int i = 0, a[5] = { 1,2,3,4,5 },*p=a;
		//两种运算格式，第一个会出问题，因为访问a[0]之前的地址
	/*	for (p = &a[4]; p >= &a[0]; p--)
		{
			*p = 0;
		}*/
		//第二个不会出问题，向后越界使用a[5]的地址，允许编译
	/*	for (p = &a[5]; p > &a[0]; )
		{
			*--p = 0;
		}*/
		//操作符转换
		{
			//以下结果均为3，需要注意[]是操作符，a[2]=*(a+2)=*(2+a)=2[a]
			printf("%d\n", *(p+2));
			printf("%d\n", *(a+2));
			printf("%d\n", p[2]);
			printf("%d\n", 2[p]);
			printf("%d\n", a[2]);
			printf("%d\n", 2[a]);
		}
	}

	//二级指针
	{
		int a = 0;
		int* pa = &a;//（int*）说明是指针，（int）表示指向的类型，
		int* *ppa = &pa;//（(int*)*）说明是指针，（int*）表示指向的类型，指针指向一个指针，被指的指针又指向整形
	}

	//指针数组
	{
		int* arr[5];//创建数组指针
	}


	char arr1[] = "abcd";
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int a = my_strlen1(arr1, sz);
	int b = my_strlen2(arr1);//实参太多也能参与运算
	int i = 2, j = 3;
	printf("%d\n", comp(i, j));
	printf("%d\n", comp2(i, j));

	int one[] = { 1,2,3,4,5 };//16进制存储（小端存储）：01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00 
	short* pone = (short*)&one;
	for (i = 0; i < 4; i++)
	{
		*(pone + i) = 0;
		//short指针更改时单步移动short 2个字节，解引用置0时，将前8个字节置0
		//00 00 00 00 00 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00 
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d  ", one[i]);
	}

	//补充：const修饰的变量，具有常属性
	const int ss = 10;
	int* p = &ss;
	//ss=20;//直接更改ss的值会报错
	*p = 20;//可以修改，有违初衷
	const int* pss = &ss;//const放在*左侧，pss不能再解引用修改地址内的值，但是指针变量指向可以改变
	//*pss=20;//会编译失败
	int y = 100;
	pss = &y;
	int* const pss1 = &ss;
	*pss1 = 20;//可以解引用
	//pss1 = &y;//不可更改指向
	printf("%d\n", ss);

	int ss2 = 0;
	const int* pss2 = &ss2;//不能解引用改值，但是可以直接改ss2
	ss2 = 20;
	return 0;
}
//编程常见错误
//1.编译错误--语法错误，大多数是缺少东西
//2.链接型错误--无法解析的外部符号 LNK XX：大多是拼写错误/符号不存在：找到错误然后回头看对应符号
//3.运行错误--调试