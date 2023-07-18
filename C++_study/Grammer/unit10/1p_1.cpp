#include<iostream>
#include"1p.h"

Stock::Stock()
{
	std::cout<<"Default constructor called\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const std::string & co,long n,double pr)
{
	company = co;
	if(n<0)
	{
		std::cout<<"Number of share can't be negative;"
		<<company<<" shares set to 0.";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock()
{
	//std::cout<<"End\n";
}
void Stock::buy(long num,double price)
{
	if(num<0)
	{
		std::cout<<"Number of shares purchased can't be negative."
			<<"Transacetin is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num,double price)
{
        if(num<0)
        {
                std::cout<<"Number of shares sold can't be negative."
                        <<"Transacetin is aborted.\n";
        }
        else  if(num>shares)
	{
		std::cout<<"You can't sell more than you have!"
			<<"Transaction is aborted.\n";
	}
	else
        {
                shares -= num;
                share_val = price;
                set_tot();
        }
}
void Stock::show() const
{
//类成员函数内部设定格式时，
//需要保留进入函数的格式并在函数尾恢复，
//防止影响其他部分的格式
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig = cout.setf(std::ios_base::fixed);
	std::streamsize prec = cout.precision(3);
	
	std::cout<<"Company: "<<company
		<<" Shares: "<<shares<<"\n"
		<<" Share Price: $"<<share_val;
	cout.precision(2);
	cout<<" Total Worth: $"<<total_val<<"\n";
	
	cout.setf(orig,ios_base::floatfield);
	cout.precision(prec);
}
const Stock & Stock::topval(const Stock & s) const
{
    if(s.total_val > total_val)
        return s;//返回显式对象
    else
        return *this;//返回调用对象
}
