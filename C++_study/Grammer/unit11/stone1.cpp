#include<iostream>
using std::cout;
#include"stonewt1.h"

int main()
{
	Stonewt poppins(9,2.8);
	double p_wt = poppins;
	cout<<"convert to double => ";
	cout<<p_wt<<" pounds.\n";
	cout<<"convert to int => ";
	cout<<int(poppins)<<" pounds.\n";
	return 0;
}

