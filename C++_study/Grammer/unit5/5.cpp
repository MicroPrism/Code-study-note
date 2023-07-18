#include<iostream>

int main(void)
{
	using namespace std;
	char ch;
	int count = 0;
	cout<<"enter a char : ";
	while(cin.get(ch))
	{
		cout<<ch;
		++count;
	}
	cout<<endl<<count<<" characterize"<<endl;
	return 0;
}
