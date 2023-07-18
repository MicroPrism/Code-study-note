#include<iostream>
#include<cstring>
int main(void)
{
	using namespace std;
	char in[20];
	double count = 0;
	cin>>in;
	while(strcmp(in,"done"))
	{
		cin>>in;
		count++;
	}
	cout<<count<<endl;
	return 0;
}
