#include<iostream>

int main(void)
{
	using namespace std;
	const int YEAR = 3;
	const int MONTH = 12;
	double sale[YEAR][MONTH];
	const string str_year="年";
	const string str_month="月";
	for(int i = 0;i<YEAR;i++)
		for(int j = 0;j<MONTH;j++)
		{
			cout<<i+1<<str_year<<j+1<<str_month<<'\t';
			cin>>sale[i][j];
		}
	for(int i = 0;i<YEAR;i++)  
        {
		cout<<i+1<<str_year<<":\t";
		 for(int j = 0;j<MONTH;j++)
                {
                       cout<<sale[i][j]<<'\t';
                }
		cout<<'\n';
	}
	return 0;
}
