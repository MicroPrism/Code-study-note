#include<iostream>

using namespace std;

double Revenue(double);

int main(void)
{
	double money;
	while(cin>>money)
	{
		double revenue = Revenue(money);
		cout<<"the revenue is : "<<revenue<<endl;
	}
	return 0;
}
double Revenue(double input)
{
	int temp=input/5000;
	switch(temp)
	{
		case 0:return 0.0;
		case 1:
		case 2:return (input-5000)*0.1;break;
		case 3:
		case 4:
		case 5:
		case 6:return 1000+(input-15000)*0.15;break;
		default :return 4000+(input-35000)*0.2;break;
	}
}
