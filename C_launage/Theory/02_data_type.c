#define _CRT_SECURE_NO_WARNINGS 1
//C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\VC\VCProjectItems,
//����c���԰�װ·�����޸�newc++file���������ļ�ʱ��ģ��
#include<stdio.h>
int main()
{
	int ch = 0;
	int age = 20;
	short num = 10;
	printf("%d\n", ch);//�����ַ�����ӡ
	//sizeof-�ؼ���-�������ͻ������ռ�Ŀռ��С����λΪ�ֽ�byte
	//printf("%d\n", sizeof(char));���ֱ������ᱨ���棬
	//ԭ��sizeof����ֵΪ64λ�޷������Σ���8�ֽ����ݣ�����ֱ����%d��4�ֽڣ���
	printf("%lld\n", sizeof(char));//1
	printf("%lld\n", sizeof(int));//4 
	printf("%lld\n", sizeof(short));//2
	printf("%lld\n", sizeof(long));//4
	printf("%lld\n", sizeof(long long));//8
	printf("%lld\n", sizeof(float));//4
	printf("%lld\n", sizeof(double));//8
	//byte�ֽ�=8bit��1kb=1024byte��1M=1024kb
	//��ô����������ͷֱ��в�ͬ��С���ܸ����ʵķ���ռ�
	scanf("%d,%d", &ch, &age);
	int sum = ch + age;
	printf("%d\n", sum);//1
	//��������ʱ��ʼ��һ��ֵ��������Ҫʱ��������
	//�����ڲ�����ı���Ϊ�ֲ��������ⲿ�����Ϊȫ�ֱ������ֲ����ȡ������鶨��Ϊ��ͬ����
	return 0;
}