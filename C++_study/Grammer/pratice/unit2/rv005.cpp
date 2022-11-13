#include<iostream>
double Transmit(double);
int main(void)
{
	using namespace std;
	cout<<"plz input a Temp"<<endl;
	double temp;
	cin>>temp;
	cout<<"the tempture is (in huashi)"<<Transmit(temp)<<endl;
	return 0;
}
double Transmit(double x)
{
	return x*1.8+32.0;
}
