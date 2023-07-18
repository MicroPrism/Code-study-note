#include<iostream>
using namespace std;
const int* sum(int arr[],int n);
const int* sqrt(int arr[],int n);
int unit(const int*(*pf)(int arr[],int n));

int main(void)
{
//	using namespace std;
	int income[8] = {1,2,3,4,5,6,7,8};
	int n;
	cout<<"Enter a number : ";
	cin>>n;
	const int* (*math[2])(int arr[],int n) = {sum,sqrt};
	auto pmath = &math;
	cout<<"math[0](income,n) : "<<math[0](income,n)<<"  value is : "
		<<*math[0](income,n)<<endl;
	cout<<"(*math[0])(income,n):"<<(*math[0])(income,n)<<" value is : "
		<<*(*math[0])(income,n)<<endl;
	cout<<"*(*pmath)[0](income,n) "<<(*(*pmath)[0])(income,n)<<" value is :"
		<<*(*(*pmath)[0])(income,n)<<endl;
	unit(sqrt);
	delete math[0](income,n);
	delete (*math[0])(income,n);
	return 0;
}
const int* sum(int arr[],int n)
{
	int* sum = new int;
	for(int i = 0; i < n;i++)
	{
		*sum+=arr[i];
	}
	return sum;
}
const int* sqrt(int arr[],int n)
{
	int *pa = new int;
	*pa = arr[n-1]*arr[n-1];
	return pa;
}
int unit(const int*(*pf)(int arr[],int n))
{
	int arr[4] = {2,3,4,5};
	int n;
	cout<<"input n : ";
	cin>>n;
	cout<<*pf(arr,n)<<endl;;
	return 0;
}
