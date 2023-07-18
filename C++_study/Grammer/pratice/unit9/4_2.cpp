#include<iostream>
#include"4.h"
int main()
{
	using namespace SALES;
	double arr[4] = {1.0,2.0,3.0,4.0};
	Sales ax1,ax2={{2.0,4.0,6.0},0,0,0};
	setSales(ax1,arr,4);
	showSales(ax1);
	setSales(ax2);
	showSales(ax2);
	return 0;
}
