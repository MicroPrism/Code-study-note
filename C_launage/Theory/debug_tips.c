#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//调试技巧-不要迷信式的调试
//调试基本步骤
//发现错误--隔离消除--确定产生原因--提出解决办法-改正错误-重新测试
//Debug--调试版本，包含各种调试信息，文件相对更大
//release--发行版本，进行了各种优化，程序在代码大小和运行速度上最优的

int main()
{
	int i = 0;
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < sz; i++)
	{
		arr[i] = i + 1;//设置断点可以设为条件断点 
	}
	return 0;
}

//windows环境-选中debug
//快捷键F5：启动调试、F9：设置/曲线断点，合理添加断点可以直接跳过没有问题的断点
//F11可以进入函数内部

//调试-窗口-断点，可以查看所有断点，同时可以勾选时候让断点生效
//调试-窗口-堆栈，可以查看调用逻辑，理清思路
//调试时搞清楚，应该产生什么结果，如果实际结果产生偏差，就找到问题了

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
	*destination = *source;//添加结束符
}
void my_strcpy3(char* destination, char* source)//但是如果出现空指针，解引用会出问题
{
	assert(source != NULL);//断言，assert.h
	assert(destination != NULL);//断言,防止出现空指针
	while (*destination++ = *source++)//判断语句内为赋值语句，当到结束符时先赋值，然后'\0'不满足循环条件，跳出
	{
		;
	}
}
void my_strcpy4(char* destination, const char* source)
{
	assert(source != NULL);
	assert(destination != NULL);
	while (*destination++ = *source++)//判断语句故意写反，如果不做处理，址传递问题，但是加const之后如果写反，会编译报错
	{
		;
	}
}
char* my_strcpy5(char* destination, const char* source)
{
	assert(source != NULL);
	assert(destination != NULL);
	char* temp = destination;
	while (*destination++ = *source++)//判断语句故意写反，如果不做处理，址传递问题，但是加const之后如果写反，会编译报错
	{
		;
	}
	return temp;
}
//int main()
//{
//	//以下代码出现死循环
//	//调试会发现a[12]=0时，i同步变为0
//	//原因：局部变量在使用时，栈分配空间先分配高地址，i为高地址，arr为低地址，如果越界访问恰好越界到i将其更改，将死循环
//	//vc6.0-i紧挨着arr，间隔0个整型
//	//Linux gcc-间隔1个整形
//	//vs2013-2019-间隔两个整形
//
//	//int i = 0;
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	////如果将int i=0；设置在此处先分配arr，再分配i，运行会出错，不会死循环
//	//for (i = 0; i <= 12; i++)
//	//{
//	//	arr[i] = 0;
//	//	printf("hh\n");
//	//}
//
//	//调试重要，也要合理预防bug
//	//1.运行正常
//	//2.bug少
//	//3.效率高
//	//4.可读性好
//	//5.可维护性好
//	//6.注释清晰
//	char arr1[20] = "XXXXXXXXXXX";
//	char arr2[20] = "XXXXXXXXXXX";
//	char arr3[] = "hello";
//	my_strcpy3(arr1, arr3);
//	//my_strcpy3(arr1, NULL);//这两句使用使用assart后会报错
//	//my_strcpy3(NULL, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", my_strcpy5(arr2, arr3));//返回一个指针，字符打印
//	return 0;
//}