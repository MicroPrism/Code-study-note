#define _CRT_SECURE_NO_WARNINGS 1
#include"18_array.h"

//&数组名---数组名表示整个数组，取出的是整个数组的地址
//sizeof数组名--计算整个数组的大小

//数组是相同类型元素的集合，int arr[8];创建大小为8的数组
//长度为变量时不行，即使const使变量具有常属性也不行
int main()
{
	//int 型
	int arr1[10] = { 1,2,2,3,3,4,5,6,4,5 };//完全初始化
	int arr2[10] = { 1,2,2,3,3 };//部分初始化，余下自动补ACSCII码0
	int arr3[] = { 1,2,3,4,5 };//根据个数确定数组长度

	//char型
	char arr4[5] = { 'a','b','c' };//部分初始化
	char arr5[] = { 'a','b','c' };
	char arr6[5] = "bit";//b i t \0 0，双引号默认补结束符
	char arr7[] = "bit";//b i t \0，长度为4

	printf("%s\n", arr4);
	printf("%s\n", arr5);//数组5完全定义，但不确定有无结束符
	printf("%s\n", arr6);
	printf("%d\n", strlen(arr5));//15
	printf("%d\n", sizeof(arr5) / sizeof(arr5[0]));//3
	printf("%d\n", strlen(arr6));//3,strlen计算第一次遇到结束符的个数
	printf("%d\n", sizeof(arr6) / sizeof(arr6[0]));//5，sizeof计算数组字节总长度
	printf("%d\n", strlen(arr7));//3
	printf("%d\n", sizeof(arr7) / sizeof(arr7[0]));//4

	int arr8[10] = { 0 };//不完全初始化
	arr8[1] = 1;
	arr8[2] = 2;
	int* parr8 = arr8;//数组名即为首元素地址
	//%p-十六进制打印地址
	printf(" arr8:\t\t%p\n", arr8);
	printf(" &arr8:\t\t%p\t\n", &arr8);
	printf(" &arr8[0]:\t%p\t\n", &arr8[0]);//arr8、&arr8、&arr8[0]均是区首地址
	printf(" arr8+1:\t%p\n", arr8 + 1);//数组首地址+1，最终结果增大4
	printf(" &arr8+1:\t%p\n", &arr8 + 1);//数组地址+1,最终结果增大0x28=40
	printf("\n");

	printf(" parr8+1:\t%p\t\n", parr8 + 1);//指针相对向后移sizeof个单位，4字节，输出的是偏移后的地址，实际上parr8的指向没变
	printf(" parr8:\t\t%p\t\n", parr8);
	printf(" ++parr8:\t%p\t\n", ++parr8);//地址并未改变？？
	printf(" parr8:\t\t%p\t\n", parr8);//++后，parr的指向发生变化
	printf(" *(++parr8):\t%d\t\n", *(++parr8));//
	printf(" *parr8 + 1:\t%d\t\n", *parr8 + 1);//先解引用再+1
	printf(" *(parr8 + 1):\t%d\t\n", *(parr8 + 1));//等同于打印arr[1]

	char arr[20] = {0};
	scanf("%s", arr);
	rever_array(arr);
	printf("%s\n", arr);
	rever_array1(arr);
	printf("%s\n", arr);
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	double c = my_Pow(a, b);//问题：输出错误值；原因：.h文件声明函数时，未将类型从int改为double
	printf("%f\n",c);

	//二维数组虽然为m行n列，但是仍然是顺序排列，先第一行再第二行...、
	//整体初始化
	int arr1[3][4] = { 1,2,3,4,1,2,3,4,1,2,3,4 };//完全初始化
	int arr2[3][4] = { 1,2,3,4,1,2,3 };//不完全初始化，空缺仍置0
	//分块初始化
	int arr3[3][4] = { {1,2},{3,4},{1,2,3 } };//按行初始化，空缺仍置0

	int arr4[][3] = { {1,2},{2,3},{1} };//可以只定义列的个数，会自动识别有多少行，若只确定行，不确定每行多少个
	//根据地址连续的特性可以用指针去调用 

	//对于多维数组，每一行的数组名可以理解为arr[0]、arr[1]、arr[2]...
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