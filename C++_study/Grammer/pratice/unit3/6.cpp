#include<iostream>

int main(void)
{
	using namespace std;
	double miles,gallon;
	cout<<"plz input miles : ";
	cin>>miles;
	cout<<"plz input consumption : ";
        cin>>gallon;
	double miles_per_gallon = miles / gallon;
	cout<<"the consumption of miles per gallon is : "<<miles_per_gallon<<endl;
	return 0;
}
