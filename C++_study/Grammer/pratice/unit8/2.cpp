#include<iostream>
using namespace std;
struct candy
{
	char name[30];
	double weight;
	int calory;
};
void Set_candy(candy & a,const char * b="Millennium Munch",double c = 2.85,int d=250);
void Show_candy(const candy & a);
int main()
{
	candy ax1,ax2;
	char temp_c[30];
	cout<<"Name is :";
	cin.getline(temp_c,30);
	double temp_d;
	cin>>temp_d;
	int temp_i;
	cin>>temp_i;
	Set_candy(ax1);
	Show_candy(ax1);
	Set_candy(ax2,temp_c,temp_d,temp_i);
	Show_candy(ax2);
	return 0;
}
void Set_candy(candy & a,const char * b,double c,int d)
{
	int i = 0;
	while(*(b+i))
	{
		a.name[i] = *(b+i);
		i++;
	}
	a.weight = c;
	a.calory = d;
}
void Show_candy(const candy & a)
{
	cout<<"Name :"<<a.name<<endl;
	cout<<"weight :"<<a.weight<<endl;
	cout<<"calory :"<<a.calory<<endl;
}
