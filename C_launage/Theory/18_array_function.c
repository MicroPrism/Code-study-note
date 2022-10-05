//测长度
int  sz_length(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		a++;
		count++;
	}
	return count;
}

//循环型两两交换值，每交换一次，指针向后移一次
//<=号判别，可以确保中间的项可以交换，奇数个偶数个都能考虑到
void rever_array(char* a)
{
	int i = 0;
	int temp = 0;
	int sz = sz_length(a);
	int left = 0, right = sz - 1;
	for (i = 0; i <= (left + right) / 2; i++)
	{
		temp = *(a + i);//改变指针内容
		*(a + i) = *(a + right - i);
		*(a + right - i) = temp;
	}
}

//递归自定义函数
//每次递归先把第一位取出，将最后一位放置在第一位，末位置‘\0’
//接着判断a+1，指针后移，判断字符串长度，字符串长度小于2，剩余0个或1个就结束
void rever_array1(char* a)
{
	char temp = *a;//char temp = 0;
	int sz = sz_length(a);
	*a = *(a + sz - 1);
	*(a + sz - 1) = '\0';
	if (sz_length(a + 1) >= 2)
	{
		rever_array1(a + 1);
	}
	*(a + sz - 1) = temp;
}

//x^y指数函数
double my_Pow(int x, int y)
{
	if (y == 0)
	{
		return 1.0;
	}
	else if (y > 0)
	{
		return (x * my_Pow(x, y - 1));
	}
	else
	{
		return 1.0 / (my_Pow(x, -y));
	}
}

//两种冒泡排序方法
void Bubble_arrange1(int a[], int sz)//形参a本质是指针
{
	int i = 0, j = 0, temp = 0;
	//int sz = sizeof(a) / sizeof(a[0]);//a是指针，sizeof(a)=4
	for (i = 0; i < sz - 1; i++)//冒泡的趟数，一次冒泡一个，至少需要sz-1趟
	{
		int flag = 1;
		for (j = 0; j < sz - 1 - i; j++)//把最大值冒泡到最后，并且不再参与后续比较
		{
			if (a[j] < a[j + 1])//传值条件，找最小值
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 0;//判断一趟大循环内是否没有任何交换，没有任何交换说明已经有序，跳出即可
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
void Bubble_arrange2(int* a, int sz)
{
	int i = 0, j = 0, temp = 0;
	//int sz = sizeof(a) / sizeof(a[0]);//a是指针，sizeof(a)=4
	for (i = 0; i < sz - 1; i++)//冒泡的趟数，一次冒泡一个，至少需要sz-1趟
	{
		int flag = 1;
		for (j = 0; j < sz - 1 - i; j++)//把最大值冒泡到最后，并且不再参与后续比较
		{
			if (*(a + j) < *(a + j + 1))//传值条件，找最小值
			{
				temp = *(a + j);
				*(a + j) = *(a + j + 1);
				*(a + j + 1) = temp;
				flag = 0;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//无论是使用指针+偏移量还是直接使用数组元素，只在进行判断和值交换时用的到
//充分理解循环条件
//冒泡，一次大循环只能出来一个，n个数需要n-1次大循环
//小循环就是内部两两比较，n个数比较n-1次，外部大循环循环一次少一个数，内部响应减少比较次数