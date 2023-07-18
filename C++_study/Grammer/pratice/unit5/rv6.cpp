#include<iostream>
int main(void)
{
	using namespace std;
	int sum = 1;
	for(int i = 1;i < 8; sum*=2,i++)
		cout<<sum<<'\t';
	//for(int i =1;i<8;i++)
	//	cout<<(sum=sum*2)<<'\t';
	cout<<endl;
	return 0;
}
