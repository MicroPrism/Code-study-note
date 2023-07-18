#include<iostream>
#include<cstring>
#include<string>
using namespace std;//string
struct donate
{
	string name;
	double money;
};
int main(void)
{
	const int SIZE = 10;
	struct donate *pd = new donate [SIZE];
	for(int i = 0;i<SIZE;i++)
	{
	cout<<"Enter the name of donation in "<<i<<" : ";
	getline(cin,(pd+i)->name);
	cout<<"Enter the accout : ";
	cin>>(pd+i)->money;
	cin.get();
	}
	int count_g=0,count=0;
	cout<<"----------Grand patrons-----------"<<endl;
	for(int i = 1;i<SIZE;i++)
	{
	if((pd+i)->money>10000)
	{
		cout<<(pd+i)->name<<"\t"<<(pd+i)->money<<endl;
		count_g++;
	}
	}
	if(count_g==0)
		cout<<"None."<<endl;
	cout<<"-------------patrons-----------"<<endl;
	for(int i = 1;i<SIZE;i++)
	{
	if((pd+i)->money<10000)
        {
	        cout<<(pd+i)->name<<"\t"<<(pd+i)->money<<endl;
        	count++;
	}
	}
	if(!count)
		cout<<"None."<<endl;
	return 0;
}
