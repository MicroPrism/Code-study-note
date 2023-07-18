#include<iostream>
double Average(double,double);

int main(void)
{
	using namespace std;
	double a,b;
	cin>>a>>b;
	while(1)
	{	
		if(!cin)
		{
			cin.clear();
			while(cin.get()!= '\n')
				continue;
			cout<<"plz input again :";
			cin>>a>>b;
			continue;
		}
		if(a&&b)
		{
			double aver = Average(a,b);
			cout<<"The fixed average is :"<<aver<<endl;
			cout<<"input two number :";
			cin>>a>>b;
		}
		else
			break;
	}
	return 0;
}
double Average(double a,double b)
{
	return 2.0*a*b/(a+b);
}
