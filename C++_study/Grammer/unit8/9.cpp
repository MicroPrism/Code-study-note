#include<iostream>

using namespace std;
template<typename T>
T Swap(T &a,T&b);

int main(void)
{
	int a,b;
	double c,d;
	cin>>a>>b>>c>>d;
	cout<<a<<" / "<<b<<endl;
	Swap(a,b);
	cout<<a<<" / "<<b<<endl;
	cout<<c<<" / "<<d<<endl;
	Swap(c,d);
	cout<<c<<" / "<<d<<" / "<<Swap(c,d)<<endl;
	return 0;
}
template <typename T>
T Swap(T &a,T&b)
{
	T temp = a;
	a = b;
	b = temp;
	return temp;
}
