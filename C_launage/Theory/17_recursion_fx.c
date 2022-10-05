#define _CRT_SECURE_NO_WARNINGS 1

void print(unsigned int a)
{

	if (a > 9)//判断语句限制递归条件，递归必须越来越逼近跳出条件
	{
		print(a / 10);//进入下一次调用，使用新的值，先执行最深层的结果，一次往外
	}
	printf("%d\n", a % 10);
}
int my_strlen1(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;//地址向后移一位
	}
	return count;
}
int my_strlen2(char* arr)
{
	if (*arr != 0)//字符最后一定是0，不断向后移动指针的指向即可
	{
		return 1 + my_strlen2(arr + 1);
		//此处使用arr++会出问题，a++直接改变了指针指向，不再指向首地址
		//而arr+1，只是使用了以arr为参考的地址，arr的指向没有改变
	}
	else
	{
		return 0;
	}
}
int Fac(int a)
{
	if (a > 1)
	{
		return a * Fac(a - 1);//此处可以用a--
	}
	else
	{
		return 1;
	}
}
//递归
int Fibnacci(int n)//此种递归需要的运算量过大，每次都要重新计算同样的数，效率低
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fibnacci(n - 1) + Fibnacci(n - 2);//倒着递归，分叉重复运算
	}
}
//循环方式
int Fibonacci(int n)
{
	int a = 1, b = 1, c = 0;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;//通过一定次数的迭代进行计算，F（8）无非是迭代8次
	}
	return c;
}