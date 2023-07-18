#include<iostream>
#include<cstring>
using namespace std;

unsigned long int Left(unsigned long int put,int n);
char * Left(const char *,int n = 1);

int main()
{
	const char *a = "Youngs";//常量字符串建议使用const限定
	char *b = Left(a);
	cout<<b<<endl;
	delete [] b;
	char *c = Left(a,10);
	cout<<c<<endl;
	delete [] c;
	
	unsigned long int init = 123456;
	int n;
	cin>>n;
	unsigned long int output = Left(init,n);
	cout<<output<<endl;
	
	return 0;

}
unsigned long int Left(unsigned long int input,int n)
{
	if(input == 0||n ==0)
		return 0;
	unsigned digits = 1;
	unsigned long temp = input;
	while(temp/=10)
		digits++;
	if(digits > n)
	{
		n = digits -n;
		while( n-- )
			input /=10;
		return input;
	}
	else
		return input;	
}
char * Left(const char* pa,int n)
{
	if(n<0)
		n = 0;
	int size = strlen(pa) < n ? strlen(pa) : n;
	char *str = new char [size + 1];
	int i;
	for(i = 0 ; i < size && pa[i]; i++)
	{
		str[i] = pa[i];
	}
	while(i <= n)
	{
		str[i++] = '\0';
	}
	return str;
}
