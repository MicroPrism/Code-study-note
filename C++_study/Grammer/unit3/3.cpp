/*
	Section 3 Code of Chapter 3
	date:2022.11.03
*/
#include<iostream>

int main(void)
{
	using namespace std;
	int a=42;
	int b=042;
	int c=0x42;
	cout<<a<<" / "<<b<<" / "<<c<<" / "<<endl;
	cout<<dec<<a<<" / ";
	cout<<oct<<b<<" / ";
	cout<<hex<<c<<endl;
	return 0;
}
