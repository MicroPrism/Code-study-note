#include<iostream>
#include<array>
int main(void)
{
	using namespace std;
	array<long double,101> fi;
	fi[0]=1,fi[1]=1;
	for(int i = 2;i < 101;i++)
		fi[i]=i*fi[i-1];
	cout<<fi[3]<<endl;
	return 0;
}
