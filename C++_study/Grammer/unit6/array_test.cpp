#include<iostream>

int main(void)
{
	using namespace std;
	char ss[4][6] = {{"abac"},{"hah"},{"yeah"},{"hai"}};
	char (*pss)[6] = ss;
	cout<<pss[1]<<endl;
//	char *ps[4] = &ss;
//	cout<<ps[1]<<endl;
	return 0;
}
