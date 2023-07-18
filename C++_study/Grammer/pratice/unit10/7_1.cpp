#include<iostream>
#include"7.h"
int main()
{
	Plorg pl;
	pl.show();
	int a = 20;
	Plorg pl2("Youngs",30);
	pl2.show();
	pl2.set_CI(10);
	pl2.show();
	return 0;
}
