#include<iostream>

using namespace std;

int main(void)
{
	int tell[10]={1,2,3,4,5,6,7};
	int *ptell =tell,*pend=&tell[9];
	int differ=pend-ptell;
	cout<<differ<<endl;
	return 0;
}
