#include <iostream>

using namespace std;

union pal
{
	int age;
	char init;
};

int main(void)
{
	pal yang;
	cout<<"input a number : "<<endl;
	cin>>yang.age;
	cout<<"the yang initial name is : "<<yang.init<<endl;
	return 0;
}
