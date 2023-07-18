#include<iostream>

int main(void)
{
	using namespace std;
	int i,j;
	cout<<"Enter a number :";
	cin>>i;
	cout<<"Enter another number :";
	cin>>j;
	int sum = 0;
	for(i;i<=j;i++)
		sum+=i;
	cout<<"sum = "<<sum<<endl;
	return 0;
}
