#include<iostream>

int main(void)
{
	using namespace std;
	const int MAX = 5;
	double fish[MAX],sum=0.0;
	int i = 0;
	//cout<<"fish #1 : ";
	while(i<MAX)
	{
		cout<<"\nfish #"<<i+1<<" : ";
		while(!(cin>>fish[i]))
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"error,reinput : ";
		}
		i++;
	}
	for(int j = 0;j<MAX;j++)
	{
		sum+=fish[j];
	}
	cout<<"sum = "<<sum<<"\n"<<"average = "<<(sum/i)<<endl;
	return 0;
}
