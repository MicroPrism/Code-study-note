#include<iostream>

int main(void)
{
	using namespace std;
	int count = 0;
	double donation,average,sum;
	double a[10];
	for(int i = 0;cin>>donation;i++)
	{
		a[i]=donation;
		count++;
		sum+=donation;
	}
	average=sum/count;
	int large,small;
	for(int i =count-1;i>=0;i--)
	{
	if(a[i]>average)
		large++;
	else if(a[i]<average)
		small++;
	}
	cout<<"This average is :"<<average<<"\n";
	cout<<"large average number is :"<<large<<endl;
	cout<<"small is :"<<small<<endl;
	return 0;
}
