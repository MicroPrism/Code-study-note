#include<iostream>

int main(void)
{
	using namespace std;
	const int MAX = 5;
	double fish[MAX],sum;
	int i = 0;
	cout<<"fish #1 : ";
	while(i<MAX&&cin>>fish[i])
	{
		if(++i<MAX)
		cout<<"\nfish #"<<i+1<<" : ";
	}
	for(int j = 0;j<MAX;j++)
	{
		sum+=fish[j];
	}
	cout<<"sum = "<<sum<<"\n"<<"average = "<<(sum/i)<<endl;
	return 0;
}
