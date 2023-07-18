#include<iostream>

int main(void)
{
	using namespace std;
	char ch;
	int count = 0;
	cout<<"enter a char : ";
	ch = cin.get();
	while(ch != EOF)
	{
		cout.put(ch);
		++count;
		ch = cin.get();
	}
	cout<<endl<<count<<" characterize"<<endl;
	return 0;
}
