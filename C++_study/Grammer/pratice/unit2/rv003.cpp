#include<iostream>
using namespace std;
void mice(void);
void run(void);
int main(void)
{
	mice();
	mice();
	run();
	run();
	return 0;
}
void mice(void)
{
	cout<<"mice."<<endl;
}
void run(void)
{
	cout<<"run."<<endl;
}
