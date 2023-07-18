#include<iostream>
#include"4.h"
namespace SALES
{
	void setSales(Sales & s,const double ar[],int n)
	{
		int i = 0;
		double sum = 0.0;
		s.min = ar[0],s.max = ar[0];
		for(i = 0;i < QUARTERS && i < n;i++)
		{
			s.sales[i] = ar[i];
			sum += s.sales[i];
			if(s.min > s.sales[i])
				s.min = s.sales[i];
			if(s.max < s.sales[i])
				s.max = s.sales[i];
		}
		s.average = sum/i;
	}
	void setSales(Sales & s)
	{
		int i = 0;
		double sum = 0.0;
		for(i = 0;i < QUARTERS;i++)
		{
			sum += s.sales[i];
			if(s.min > s.sales[i])
				s.min = s.sales[i];
			if(s.max < s.sales[i])
				s.max = s.sales[i];
		}
		s.average = sum/i;
	}
	void showSales(const Sales & s)
	{
		using std::cout;
		using std::endl;
		using std::ios_base;
		cout.setf(ios_base::fixed);//将对象设为定点表示方式
		cout.setf(ios_base::showpoint);//小数点显示模式，即使没有小数
		cout.precision(3);//设定小数位个数，可任意数
		for(int i = 0;i < QUARTERS;i++)
		{
			cout<<s.sales[i]<<"\t";
		}
		cout<<"average: "<<s.average<<endl;
		cout<<"min: "<<s.min<<endl;
		cout<<"max: "<<s.max<<endl;
	}
}
