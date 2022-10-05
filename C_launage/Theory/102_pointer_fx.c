void print(int a[3][5], int b, int c)//数组传参
{
	int i = 0, j = 0;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
void print2(int(*a)[5], int b, int c)//形参为指向一维数组的指针，a为ar的第一行首地址a=ar[0]，a+1=ar[1]
{
	int i = 0, j = 0;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(a + i) + j));//a为数组首地址；a + i，第i行的地址
		}
		printf("\n");
	}
}
//一维数组传参函数定义
void test(int arr[]) {};
void test1(int arr[10]) {};//形参为数组，数组大小可有可无
void test2(int* arr) {};//指针指向数组首地址
void test3(int* arr[20]) {};//形参与实参相同
void test4(int** arr) {};//指针数组也是数组,内容均为指针，指向其首元素int*地址，指向地址的地址，二级指针
//二维数组传参
void test5(int arr[3][5]) {};
//void test6(int arr[][]) {};
void test7(int arr[][5]) {};//二维数组做形参时，列数必须定义，可以不知道多少行，但是必须知道每行多少元素
void test8(int* arr) {};//不可     arr为第一行的地址，是数组的地址
void test9(int* arr[5]) {};//不可  指针数组
void test10(int(*arr)[5]) {};//可以  指向5个整形元素的指针，刚好指向每个行
void test11(int** arr) {};//不可   传过来为数组的地址，是一级地址，不是二级地址
int testa()
{
	return 0;
}
int Add(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Cot(int(*pf)(int, int))
{
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);
	return pf(x, y);
}