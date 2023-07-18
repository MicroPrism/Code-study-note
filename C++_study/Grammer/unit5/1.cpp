#include<iostream>
#include<cstring>
#include<string>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::string,std::endl;
	string str;
	cout<<"Enter a word : ";
	cin>>str;
	for (int i =str.size() - 1 ; i >= 0; i--)
	{
		cout<<str[i];
	}
	cout<<endl;
	return 0;
}
