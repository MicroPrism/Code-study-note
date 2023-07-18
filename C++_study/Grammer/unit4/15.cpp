#include<iostream>
#include<vector>
#include<array>

using namespace std;

int main(void)
{
	int sp1[4]={1,2,3};
	vector<double> sp2(4);//={3.1,4.2,5.3,6.4};
	array<int,4>sp3={4,6,7};
	array<int,4>sp4;
	sp4=sp3;
	cout<<sp1[1]<<" is sp1[1]."<<endl;
	cout<<sp2[1]<<" is sp2[1]."<<endl;
	cout<<sp3[1]<<" is sp3[1]."<<endl;
	cout<<sp4[1]<<" is sp4[1]."<<endl;
	return 0;
}
