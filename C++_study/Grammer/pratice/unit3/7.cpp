#include<iostream>

int main(void)
{
	using namespace std;
	double per_100km;
	cout<<"plz input consumption L/100km : ";
	cin>>per_100km;
	const double MILE_TO_YMI = 62.14;
	const double GALLON_TO_L =3.875;
	double gallon_per_ymi = per_100km / MILE_TO_YMI / GALLON_TO_L;
	double us_consum = 1 / gallon_per_ymi;
	cout<<"the us consumption is :"<<us_consum<<" mpg."<<endl;
	return 0;
}
