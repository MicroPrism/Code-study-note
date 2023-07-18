#include<iostream>
struct bot{char name[50];double amount;};
template <typename T>
void Showarray(T arr[],int n);
template <typename T>
void Showarray(T* arr[],int n);
int main()
{
	bot test[3] = {	{"AA",33.3},
			{"BB",66.6},
			{"CC",99.9},
			};
	int a[3] = {1,2,3};
	Showarray(a,2);
	double *ptest[3];
	for(int i = 0; i<3;i++)
	{
		ptest[i] = &test[i].amount;
	}
	Showarray(ptest,2);
	return 0;
}
template <typename T>
void Showarray(T arr[],int n)
{
	for(int i = 0; i < n;i++)
		std::cout<<arr[i]<<"\t";
	std::cout<<"\n";
}
template <typename T>
void Showarray(T* arr[],int n)
{
	for(int i = 0; i < n;i++)
		std::cout<<*arr[i]<<"\t";
	std::cout<<"\n";
}
