#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>//字符串库函数
//字符串就是一串字符，使用双引号（Double Quote）括起的一串字符，称为字符串字面值（String Literal）
int main()
{
	char arr[] = "abcdef";//F10-调试-窗口-监视，可以发现是7个字符，最后一个为结束符‘\0’
	char arr1[] = { 'a','b','c' };//{内部为单引号字符，而非双引号字符串，除非是更高阶的数组}
	//printf打印时，会不停输出直到检测到‘\0’
	int len = strlen("abc");
	printf("%d\n", len);//输出值为3，结束符并不算到长度里
	printf("%d\n", strlen(arr1));
	//arr1元素个数为3，但是，strlen计算长度是直到检测到0或'\0'为止，因此输出随机值
	return 0;
}
//字符串的存储只能使用数组或者字符指针，char a="abc";是错误的