#include <iostream>

int main(void)
{
	using namespace std;
	cout<<"plz input a degree : ";
	int degree,minute,second;
	cin>>degree;
	cout<<"plz input a minute : ";
        cin>>minute;
	cout<<"plz input a second : ";
        cin>>second;
	const double  TO_SUPERIOR = 60;
	double latitude = degree +( minute + second / TO_SUPERIOR) / TO_SUPERIOR ;
	cout<<"The latitude is : "<<latitude<<endl;
	return 0;
}
