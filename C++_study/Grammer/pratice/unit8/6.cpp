#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

template <typename T>
T maxn(T arr[],int n);
template <> char* maxn<char*>(char* arr[],int n);


int main()
{
	int arr1[6] = {1,2,8,3,65,8};
	double arr2[4] = {3.2,4.88,65,63};
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	cout<<maxn(arr1,size1)<<endl;
	cout<<maxn(arr2,size2)<<endl;
	const char *arr[3] = {"ha","hhh","hhhh"};
	cout<<maxn(arr,3)<<endl;
	return 0;
}
template <typename T>
T maxn(T arr[],int n)
{
	T temp;
	for(int i = 0; i < n; i++ )
	{
		temp = arr[i]>temp?arr[i]:temp;
	}
	return temp;
}
template <> char* maxn<char*>(char* arr[],int n)
{
	char* max;
	int size_str,temp;
	for(int i = 0; i < n; i++ )
	{
		size_str = strlen(arr[i]);
		if(temp<size_str)
		{
			temp = size_str;
			max = arr[i];
		}
	}
	return max;
}
