#include<iostream>
#include"1.h"
using namespace std;
int main()
{
	rect rplace;
	polar pplace;
	cout<<"Enter x and y :";
	while(cin>>rplace.x>>rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout<<"Next two number :";
	}
	cout<<"Bye!"<<endl;
	return 0;
}
