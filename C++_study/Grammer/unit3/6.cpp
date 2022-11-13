/*
	Selection 6 of Chapter 3
	data:2022.11.03
*/
#include <iostream>

int main(void)
{
	using namespace std;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;
	cout<<"tub = "<<tub;
	cout<<" , a million tub = "<<million*tub<<endl;
	cout<<"mint = "<<mint;
	cout<<" ,million mint = "<<million*mint<<endl;
	float a = 2.34e+6f;
	float b = a + 1.0f;
	cout<<b-a<<endl;
	return 0;
}
