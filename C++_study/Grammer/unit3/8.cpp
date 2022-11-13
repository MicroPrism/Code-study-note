/*
	Selection n of Chapter n
	data:
*/
#include <iostream>

int main(void)
{
	using namespace std;
	int a = 3.4;
	float b = 4,c = 5.5,*pc=&c;
	int d =*(int *)pc;
	cout<<a<<" / "<<d<<endl;
	return 0;
}
