#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int ADD(int x, int y)//定义函数
{
	return x + y;
}
int main()
{
	int input = 0;
	printf("选择蓝色药丸还是红色药丸？\n");
	scanf("%d",&input);
	if (input)
		printf("蓝色药丸\n");
	else
		printf("红色药丸\n");
	//循环while、do...while、for
	//函数-自定义函数-函数相当于外包，执行更好，可以重复调用

	int a = 0, b = 0;
	scanf("%d,%d",&a,&b);
	printf("%d\n",ADD(a,b));//调用函数，右击函数名跳转到定义
	
	//数组-一组相同类型元素的集合
	int arr[10] = {1,2,3};//不完全初始化，剩余默认为0
	int i = 0;
	while (i < 10)
	{
		printf("%d\n",arr[i]);
		i++;
	}
	return 0;
}