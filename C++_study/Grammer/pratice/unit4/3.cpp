#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
	string xing,ming;
	cout<<"Enter first name : ";
	getline(cin,xing);
	cout<<"Enter last name : ";
	getline(cin,ming);
	string name = ming + "," + xing;
	cout<<"your name : "<<name<<endl;
	return 0;
}
