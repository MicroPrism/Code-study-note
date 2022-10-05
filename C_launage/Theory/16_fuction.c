//此主函数分为几个函数块，可以分别解注释查看效果
#define _CRT_SECURE_NO_WARNINGS 1
#include"16_fuction.h" //可以引用自定义函数库
//函数分类-库函数、自定义函数，自定义函数不写返回类型时默认返回int
//函数可以嵌套调用，但是不能嵌套定义
//同样的，函数的返回值可以作为结果直接调用

//函数声明
//函数声明，确定返回类型，函数名与变量类型
//函数声明一般放在使用之前，放在头文件中
//创建一个.h文件专门用于函数声明
int main()
{
	test();//自定义函数定义在后方时，需要先声明
	return 0;
}

//int main()//最大值
//{
//	int i = 0, j = 0;
//	scanf("%d %d", &i, &j);
//	int max = get_max(i, j);
//	printf("%d\n", max);
//}

//int main()//判断素数
//{
//	int first = 0, over = 0;
//	int count_prime = 0;
//	scanf("%d %d", &first, &over);
//	count_prime=is_prime(first, over);
//	printf("\n%d\n", count_prime);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	int key = 7,flag=0;
//	int sz = sizeof(arr) / sizeof(arr[0])-1;
//	if ((flag = baniary_search(arr, key, sz))!=-1)
//	{
//		printf("\n%d\n",flag);
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}