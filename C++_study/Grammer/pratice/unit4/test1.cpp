#include<iostream>
#include<cstring>

using namespace std;

int main(void)
{
	char a[] = { "abcdefghkm"};
	char* pa = a;
	cout<<*pa<<" / "<<*(pa+strlen(a)-1)<<endl;
	return 0;
}
