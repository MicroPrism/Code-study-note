#include <iostream>

int main(void)
{
	using namespace std;
	cout<<"plz input a number for seconds : ";
	long long seconds;
	cin>>seconds;
	int days,hours,minutes,second;
	const int  TO_SUPERIOR = 60;
	second = seconds % TO_SUPERIOR;
	int temp = seconds / TO_SUPERIOR ;
	minutes = temp % TO_SUPERIOR;
	temp /= TO_SUPERIOR; 
	hours = temp % TO_SUPERIOR;
	const int TO_DAY = 24;
	days = temp /TO_DAY;
	cout<<seconds<<" seconds= "<<days<<" days,"<<hours<<" hours,"
		<<minutes<<" minutes,"<<second<<" seconds."<<endl;
	return 0;
}
