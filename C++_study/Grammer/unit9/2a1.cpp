#include<iostream>
using namespace std;
double warming = 0.3;
void update(double dt);
void local();

int main()
{
	cout<< "Global warming is "<<warming <<" ."<<endl;
	update(0.1);
	cout<< "Global warming is "<<warming <<" ."<<endl;
	local();
	cout<< "Global warming is "<<warming <<" ."<<endl;
	return 0;
}
