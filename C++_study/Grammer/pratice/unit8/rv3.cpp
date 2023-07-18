#include<iostream>

using namespace std;

void iquote(int );
void iquote(double);
void iquote(string);
int main()
{
	int a = 10;
	double b = 11.1;
	string c = "test";
	iquote(a);
	iquote(b);
	iquote(c);
	return 0;
}
void iquote(int a)
{
	cout<<a<<endl;
}
void iquote(double a)
{
	cout<<a<<endl;
}
void iquote(string a)
{
	cout<<a<<endl;
}
