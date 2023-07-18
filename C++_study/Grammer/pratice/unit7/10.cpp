#include<iostream>

typedef double f(double,double);
f add;
f multi;
double calculate(double,double,f(*));
int main(void)
{
	using namespace std;
	double a,b;
	f *pf[2] = {add,multi}; 
	while(1)
	{
		cin>>a>>b;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"Error!Restart :";
			continue;
		}
		if(-1 == a|| -1 == b)
			break;
		double q;
		for(int i = 0;i < 2;i++)
		{
			q += calculate(a,b,pf[i]);	
		}
		cout<<"x + y + x * y is : "<<q<<endl;
		q = 0;
	}
	return 0;
}
double calculate(double x,double y,double (*pf)(double,double))
{
	return pf(x,y);
}
double add(double x,double y)
{
	return x+y;
}
double multi(double x,double y)
{
	return x*y;
}
