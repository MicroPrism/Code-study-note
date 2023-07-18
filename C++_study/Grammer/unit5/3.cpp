#include<iostream>

int main(void)
{
	using namespace std;
	char ch;
	int count = 0;
	cout<<"enter a char : ";
	cin>>ch;
	while(ch != '#')
	{
		cout<<ch;
		++count;
		cin>>ch;
	}
	cout<<count<<" characterize"<<endl;
	return 0;
}
