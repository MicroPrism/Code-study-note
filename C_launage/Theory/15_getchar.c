#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	char password[20] = { 0 };
	scanf("%s", password);//回车会触发scanf读取，但不会读入回车，如果输入123456回车，123456会被scanf读取
	
	int temp = 0;//char本身就是ASCII码整型
	while ((temp=getchar())!='\n')
	{
		;//getchar();//插入此语句，会处理掉\n回车，但是不能处理123 abc\n，scanf遇到空格、回车终止，后续abc\n无法处理
	}//插入一个循环可以清理掉缓存区的所有内容
	
	int ch = getchar(); //回车会被getchar读取
	if (ch == 'N')
	{
		printf("GG");
	}
	else
	{
		printf("OK");
	}
	return 0;
} 