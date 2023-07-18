#include<iostream>
#include"mytime1.h"

int main()
{
	using std::endl;
	using std::cout;
	Time planning;
	Time coding(2,40);
	Time fixing = Time(5,55);
	Time total;
	
	cout<<"Planning = ";
	planning.Show();
	cout<<endl;
	
	cout<<"fixing = ";
	fixing.Show();
	cout<<endl;
	
	//total = coding .Sum(fixing);
	total = coding + fixing;
	cout<<"coding .sum(fixing) = ";
	total.Show();
	cout<<endl;
	
	return 0;
}
