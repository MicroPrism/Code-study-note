#define _CRT_SECURE_NO_WARNINGS 1

void print(unsigned int a)
{

	if (a > 9)//�ж�������Ƶݹ��������ݹ����Խ��Խ�ƽ���������
	{
		print(a / 10);//������һ�ε��ã�ʹ���µ�ֵ����ִ�������Ľ����һ������
	}
	printf("%d\n", a % 10);
}
int my_strlen1(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;//��ַ�����һλ
	}
	return count;
}
int my_strlen2(char* arr)
{
	if (*arr != 0)//�ַ����һ����0����������ƶ�ָ���ָ�򼴿�
	{
		return 1 + my_strlen2(arr + 1);
		//�˴�ʹ��arr++������⣬a++ֱ�Ӹı���ָ��ָ�򣬲���ָ���׵�ַ
		//��arr+1��ֻ��ʹ������arrΪ�ο��ĵ�ַ��arr��ָ��û�иı�
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
		return a * Fac(a - 1);//�˴�������a--
	}
	else
	{
		return 1;
	}
}
//�ݹ�
int Fibnacci(int n)//���ֵݹ���Ҫ������������ÿ�ζ�Ҫ���¼���ͬ��������Ч�ʵ�
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return Fibnacci(n - 1) + Fibnacci(n - 2);//���ŵݹ飬�ֲ��ظ�����
	}
}
//ѭ����ʽ
int Fibonacci(int n)
{
	int a = 1, b = 1, c = 0;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;//ͨ��һ�������ĵ������м��㣬F��8���޷��ǵ���8��
	}
	return c;
}