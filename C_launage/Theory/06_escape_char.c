#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//转义字符
int main()
{
	printf("D:c学习\tect9_03\n");//\t制表符；？？）三字母词，早期编译器识别为]
	//想要打印单个引号"或 '时需要加\让计算机识别为转义字符\'或\"
	printf("D:c学习\\tect9_03\n");//其中\\为转义字符，会输出为\符合
	
	//输出字符 \ddd为八进制数，\xdd为十六进制
	printf("%c\n", '\130');//不能在后面直接输出\130，会报错
	//8进制130<->10进制88-对比ASCII表输出字符
	printf("%c\n", '\77');//量为也可以

	printf("%c\n", '\x30');//16进制30-10进制48-ASCII表字符‘0’
	printf("%d\n", strlen("C:\test\323\328text.c"));
	//注意区分\328是两个字符\32与8，8进制数只有0-7
	
	//int a=10;C++注释风格
	/*
	a=0；C语言注释，/*只能识别到最近的，类似于if..else嵌套
	*/
	return 0;
}