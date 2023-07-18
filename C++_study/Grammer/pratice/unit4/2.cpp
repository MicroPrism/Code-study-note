#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	cout<<"what is your name? ";
	string str1,str2;
	getline(cin,str1);
//	cin.getline(str1);
	cout<<"last name ? ";
	getline(cin,str2);
//	cout<<name<<endl;
	cout<<"your age? ";
	int age;
	cin>>age;
	cout<<"Name : "<<str1;
	cout<<","<<str2<<endl;
	cout<<"Age : "<<age<<endl;
	return 0;
}
