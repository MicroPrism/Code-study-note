#include<iostream>

using namespace std;

struct bisa
{
	char name[20];//string name;
	double radious;
	double weight;
};

int main(void)
{
	bisa b1;
	cout<<"enter name : ";
	cin.getline(b1.name,20);
	cout<<"enter radious : ";
	cin>>b1.radious;
	cout<<"enter weight : ";
	cin>>b1.weight;
	cout<<b1.name<<" / "<<b1.radious<<" / "<<b1.weight<<endl;
	return 0;
}
