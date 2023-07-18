#include<iostream>

inline double square(double x){return x*x;};

int main(void)
{
	using namespace std;
	double a;
	cin>>a;
	cout<<square(a)<<endl;
	cout<<square(3.5+4.5);
	return 0;
}
