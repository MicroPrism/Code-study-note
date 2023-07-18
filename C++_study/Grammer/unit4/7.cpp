#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
	using namespace std;
	char ch1[20];
	string str1;
	cout<<"Enter a string : "<<endl;
	cin.getline(ch1,20);
	cout<<"Enter another string : "<<endl;
	getline(cin,str1);
	cout<<ch1<<" / size= "<<strlen(ch1)<<endl;
	cout<<str1<<" / size = "<<str1.size()<<endl;
}
