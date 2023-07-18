#include<iostream>

int main(void)
{
	using namespace std;
	char ch;
	int count = 0;
	cout<<"enter a char : ";
	cin.get(ch);
	while(cin.fail() == false)
	{
		cout<<ch;
		++count;
		cin.get(ch);
	}
	cout<<endl<<count<<" characterize"<<endl;
	return 0;
}
