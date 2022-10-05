#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.两个数的最大公约数

//常规方法，同样可以用m向上递增计算公倍数

int main()
{
	int m = 0 ;
	int n = 0;
	scanf("%d %d", &m, &n);
	int max = m > n ? n : m;
	while (1)
	{
		if ((m % max == 0) && (n % max == 0))
		{
			printf("%d\n",max);
			break;
		}
		max--;
	}
	return 0;
}

//辗转相除法

int main()
{
	int m = 0 ;
	int n = 0;
	scanf("%d %d", &m, &n);	//辗转相除一次，即可将数据按大小排列18%24=18，数据轮换m=24，n=18
	int t = 0;
	while (m % n)
	{
		t = m % n;//此处可以直接放在while判断语句内
		m = n;
		n = t;
	}
	printf("最大公约数为：%d\n",n);
	//最小公倍数=m*n/最大公约数
	return 0;
}

//2.打印素数-仅能被1与自身整除

int main()
{
	int i = 0;
	for (i = 100; i < 200; i++)
	{
		int j = 2;
		for (j=2;j<=i-1;j++)
		{
			if (i % j == 0)
			{
				break;//被整除意味着不是素数
			}
		}
		if (j == i)
		{
			printf("质数%d\n", i);
		}
		j++;
	}
}

//优化：如果不是素数，一定能写为m=a*b，其中a<sqrt(m),因此右端循环到sqrt（m）即可
//另外，调整i的值时，可以i+=2，排除所有偶数
//
//goto语句只能在一个函数内跳，不能出函数
//用于跳出多层循环嵌套，不建议使用

int main()
{
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	printf("去二仙桥该走哪条道？\n");
	while (1)
	{
		scanf("%s", input);
		if (strcmp(input,"成华大道") == 0)
		{
			printf("答对~");
			system("shutdown -a");
			break;
		}
	}
	return 0;
}