#include <iostream>

int main(void)
{
	using namespace std;
	const int SIZE = 20;
	char name[SIZE],dessert[SIZE];
	cout<<"what's your name :";
	cin.getline(name,SIZE);
	cout<<"what's your favorite dessert :";
	cin.getline(dessert,SIZE);
	cout<<endl;
	cout<<"ok,i have some "<<dessert<<" for you,"<<name<<"."<<endl;
	return 0;
}
