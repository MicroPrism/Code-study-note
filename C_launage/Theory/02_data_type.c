#define _CRT_SECURE_NO_WARNINGS 1
//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems,
//按照c语言安装路径，修改newc++file，创建新文件时的模板
#include<stdio.h>
int main()
{
	int ch = 0;
	int age = 20;
	short num = 10;
	printf("%d\n", ch);//定义字符并打印
	//sizeof-关键字-计算类型或变量所占的空间大小，单位为字节byte
	//printf("%d\n", sizeof(char));部分编译器会报警告，
	//原因：sizeof返回值为64位无符号整形，即8字节数据，不能直接用%d（4字节）。
	printf("%lld\n", sizeof(char));//1
	printf("%lld\n", sizeof(int));//4 
	printf("%lld\n", sizeof(short));//2
	printf("%lld\n", sizeof(long));//4
	printf("%lld\n", sizeof(long long));//8
	printf("%lld\n", sizeof(float));//4
	printf("%lld\n", sizeof(double));//8
	//byte字节=8bit；1kb=1024byte；1M=1024kb
	//这么多的数据类型分别有不同大小，能更合适的分配空间
	scanf("%d,%d", &ch, &age);
	int sum = ch + age;
	printf("%d\n", sum);//1
	//变量定义时初始化一个值，后续需要时再做更改
	//括号内部定义的变量为局部变量，外部定义的为全局变量，局部优先。不建议定义为相同名称
	return 0;
}