#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//if..else if ..else语句---if与else就近配合
int main()
{
	//int型函数执行return之后便退出
	int i = 0;
	scanf("%d", &i);
	if (i<18)
		printf("未成年\n");
	else
	{
		printf("成年");
		printf("可以进局子");
	}
	//if语句判断时使用等式表达式判断 if(2==i)可以避免判断符错误导致程序失败

	//switch语句用于多分支，switch（整形表达式）{case ：...}；
	//switch要求是整形表达式，case后要求是整形常量表达式，case后必须是常量
	int day = 0;
	scanf("%d",&day);
	switch (day)
	{
	case 1:
		printf("星期1");
		break;//switch是顺序执行，所以中间可以加入break跳出当前分支，但不是必须加
		//break只能跳出最近的switch选择语句
	case 2:
		printf("星期2");
		break;
	case 3:
		printf("星期3");
		break;
	case 4:
		printf("星期4");
		break;
	case 5:
		printf("星期5");
		break;
	case 6:
		printf("星期6");
		break;
	case 7:
		printf("星期7");
		break;
	default ://默认选项，不在其他选择范围内
		printf("ERROR!");
		break;
	}
	return 0;
}