#include<iostream>
using namespace std;
template <typename T>
T max5(T a[]);
int main()
{
	int a[5] ;
	for(int i = 0; i < 5; i++)
		cin>>a[i];
	cout<<max5(a)<<endl;
}
template <typename T>
T max5(T a[])
{
	T temp = 0;
	for(int i = 0;i < 5;i++)
		temp = a[i]>temp? a[i] : temp;
	return temp;
}
