#include<iostream>
double Transmit(double);
int main(void)
{
	using namespace std;
	cout<<"plz input a length"<<endl;
	double temp;
	cin>>temp;
	cout<<"the length is (in unit)"<<Transmit(temp)<<endl;
	return 0;
}
double Transmit(double x)
{
	return x*63240;
}
