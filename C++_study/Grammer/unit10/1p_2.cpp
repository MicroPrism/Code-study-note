#include<iostream>
#include"1p.h"
int main()
{
	{
	using std::cout;
	cout<<"using constructors to create new objects\n";
	Stock stock1("nanosmart",12,20.0);
	stock1.show();
	Stock stock2 = Stock("Boffo",2,2.0);
	stock2.show();
	
	cout<<"Assigning stock1 to stock2:\n";
	stock2 = stock1;
	stock1.show();
	stock2.show();
	
	cout<<"Using a constructor to reset an object\n";
	stock1 = Stock("Nif",10,50.0);
	cout<<"revised stock1:\n";
	stock1.show();
	}
	
	return 0;
}
