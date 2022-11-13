#include<iostream>
#include<climits>

int main(void)
{
	using namespace std;
	short sam=SHRT_MAX;
	unsigned short sue=sam;
	cout<<"sam is "<<sam<<" sue is "<<sue<<endl;
	sam+=1;
	sue+=1;
	cout<<"sam is "<<sam<<" sue is "<<sue<<endl;
	sam=0;
	sue=0;
	sam-=1;
	sue-=1;
	cout<<sam<<"/"<<sue<<endl;
	return 0;
}
