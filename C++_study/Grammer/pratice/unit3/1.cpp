/*
	code 1 of chapter practice 3
*/
#include <iostream>

int main(void)
{
	using namespace std;
	cout<<"plz input you height :___\b\b\b";
	int height;
	cin>>height;
	const int FOOT_TO_INCH = 12;
	cout<<height/FOOT_TO_INCH<<" + "<<height % FOOT_TO_INCH <<" inch."<<endl;
	return 0;
}
