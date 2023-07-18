#include<iostream>

double Frac_digui(int);
double Frac_fuc(int);

int main(void)
{
	using namespace std;
	int n,m1,m2;
	cout<<"Enter a number :";
	while(1)
	{
		if(!(cin>>n))
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"Error!Restart :";
			continue;
	//		cin>>filed_number>>header_number;
		}
		if(n<0)
		{
			break;
		}
		else
		{
			m1=Frac_digui(n);
			m2=Frac_fuc(n);
		}
		cout<<"The number of "<<n<<" frac on digui is "<<m1
			<<"\tfrac on repeated is "<<m2<<endl;
	}
	return 0;
}
double Frac_digui(int n)
{
	if(n == 0)
		return 1;
	else
		return n*Frac_digui(n-1);
}
double Frac_fuc(int n)
{
	double temp = 1;
	while( n > 0)
		temp *= n--;
	return temp;
}
