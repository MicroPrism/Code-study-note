#include <iostream>

int main(void)
{
	using namespace std;
	cout<<"plz input the wordld population : ";
	long long wor_pop,us_pop;
	cin>>wor_pop;
	cout<<"plz input the us population : ";
        cin>>us_pop;
	double proportation = (double)us_pop / wor_pop;
	cout<<"The proportation is : "<<proportation*100<<"%"<<endl;
	return 0;
}
