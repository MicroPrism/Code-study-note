#include <iostream>

int main(void)
{
	using namespace std;
	const int cities = 5;
	const int year = 4;
	const string pst[cities]=
	{
	"Beijing","shanghai","Guangzhou","shenzhen","chengdu"
	};
	int temp[year][cities]=
	{
		{33,34,36,66},{22,33,33,45},{24,24,22},{}
	};
	int test[5]={1,0,2,3};
	for(int i = 0;i<cities;i++)
	{
		cout<<pst[i]<<" :\t";
		for(int j = 0;j<year;j++)
			cout<<temp[j][i]<<'\t';
		cout<<'\n';
	}
	return 0;
}
