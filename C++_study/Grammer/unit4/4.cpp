#include <iostream>

int main(void)
{
	using namespace std;
	const int SIZE = 80;
	int year;
	char built[SIZE];
	cout<<"what's your house built :";
	cin>>year;
	cout<<"what's your favorite address";
	cin.getline(built,80);
	cout<<"Year built : "<<year<<endl;
	cout<<"Address : "<<built<<"."<<endl;
	return 0;
}
