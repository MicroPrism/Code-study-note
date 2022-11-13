/*
the problem of unit2 is 2.7 7 
*/
#include<iostream>
void Display(int,int);
int main(void)
{
	using namespace std;
	cout<<"enter the number of hours:";
	int hour;
	cin>>hour;
	cout<<endl;
	cout<<"enter the number of minutes:";
	int mini;
	cin>>mini;
	cout<<endl;
	Display(hour,mini);
	return 0;
}
void Display(int x,int y)
{
	using namespace std;
	cout<<"Time: "<<x<<":"<<y<<endl;
}
