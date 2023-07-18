#include<iostream>

long double Total_part(int,int,int,int);

int main(void)
{
	using namespace std;
	long double possilbe;
	int filed_number,header_number;
	cout<<"Enter two number :";
	while(!(cin>>filed_number>>header_number))
	//if(!cin)
	{
		cin.clear();
		while(cin.get()!='\n');
			continue;
		cout<<"Error!Restart :";
//		cin>>filed_number>>header_number;
	}
	if(filed_number<=0||header_number<=0)
	{
		return 0;
	}
	possilbe = Total_part(filed_number,5,header_number,1);
	cout<<"The possible is :"<<100/possilbe<<" %"<<endl;
	return 0;
}
long double Total_part(int total,int count1,int part,int count2)
{
	long double temp = 1.0;
	for(int i = total,m = count1;m>0;i--,m--)
		temp *= i/m;
	for(int i = part,m = count2;m>0;i--,m--)
		temp *= i/m;
	return temp;
}
//出现错误：函数内部初始概率temp未置1.0,导致结果出错
//函数优化：最初函数内部for使用自增型,结果相同，但不便于理解
//for(int i = 1;i < count1;i++) temp *= i/(total-i); 
