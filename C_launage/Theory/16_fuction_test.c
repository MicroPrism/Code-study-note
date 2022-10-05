void test()
{
	printf("hh");
}
int get_max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else 
	{
		return b;
	}
}
//2.值交换函数

int swap1(int a, int b)//传值交换，并不会改变实参的值，只是在创建形参的时候，让其值与实参相等而已！
{//形参在调用的时候才分配内存空间
	int temp = a;
	b = a;
	a = temp;
	return 0;
}

int swap2(int* pa, int* pb)//传址交换，改变地址内存放的内容
{
	int temp = *pa;
	*pb = *pa;
	*pa = temp;
	return 0;
}
//函数需要更改原来的值需要传址，只是使用值传值就可以

int is_prime(int i,int j)//判断是否是素数并打印，并不是功能最单一的
{
	int a = 0, b = 0,count=0;
	for (a = i; a<=j; a ++)
	{
		for (b = 2; b <=sqrt(a); b++)
		{
			if (a % b == 0)
			{
				break;
			}
		}
		if (b > sqrt(a))
		{
			printf("素数%d\n", a);
			count++;
		}
	}
	return count;
}
int is_leap_year(int a)//判断是否为闰年的函数
{
	if (((a % 4 == 0) && (a % 100) != 0) || (a % 400 == 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
	//return ((a % 4 == 0) && (a % 100) != 0) || (a % 400 == 0));也可以将表达式结果返回，实现判断
}
//二分法排序
int baniary_search(int a[], int k, int s)
{
	int left = 0, right = s, mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] < k)
		{
			left = mid + 1;
		}
		else if (a[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}