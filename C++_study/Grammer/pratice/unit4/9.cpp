#include<iostream>

using namespace std;
struct CandyBar
{
	char brand[20];
	double weight;
	int calories;
};
int main(void)
{
	CandyBar *arr = new CandyBar [3];
	arr[0]={"one",2.4,440};
	arr[1]={"two",2.5,100};
	arr[2]={"three",33,1200};
	cout<<arr[0].brand<<" / "<<arr[0].weight<<" / "<<arr[1].calories<<endl;
	delete [] arr;
	return 0;
}
