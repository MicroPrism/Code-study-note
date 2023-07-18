#include<iostream>
#include<cstring>
using namespace std;

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
	return 0;

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
