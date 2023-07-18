#include<iostream>
#include"1.h"
int main()
{
	Stock cat;
	cat.acquire("Nanosmaret",20,12.50);
	cat.show();
	cat.buy(15,18.125);
	cat.show();
	cat.sell(400,20.0);
	cat.show();
	cat.buy(40000,40.125);
	cat.show();
	return 0;
}
