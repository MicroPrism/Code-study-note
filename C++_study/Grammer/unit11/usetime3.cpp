#include<iostream>
#include"mytime3.h"

int main()
{
	using std::endl;
	using std::cout;
	
	Time aida(3,35);
	Time tosca(2,48);
	Time temp;
	
	cout<<"Aida: ";
	cout<<aida<<" / "<<tosca<<endl;

	
	cout<<"total = ";
	temp = aida + tosca;
	cout<<temp;
	cout<<endl;

	
	cout<<"10.0 * tosca = ";
	cout<<10.0 * tosca <<endl;
	return 0;
}
