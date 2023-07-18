//compile order: g++ 17_9.cpp -lm //链接数学库
#include <iostream>
#include <cmath>

int main(void)
{
	using namespace std;
	cout.setf(ios_base::left,ios_base::adjustfield);//参数1,2设定左对齐
	cout.setf(ios_base::showpos);//显示正数标志+
	cout.setf(ios_base::showpoint);//设定显示小数点
	cout.precision(3);
	
	ios_base::fmtflags old = cout.setf(ios_base::scientific,ios_base::floatfield);
	cout << "Left Justification:\n";
	long n;
	for(n = 1;n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	
	cout.setf(ios_base::internal,ios_base::adjustfield);
	cout.setf(old,ios_base::floatfield);//恢复以前的设置，默认计数法
	cout << "Internal Justification:\n";
	for(n = 1;n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	
	cout.setf(ios_base::right,ios_base::adjustfield);
	cout.setf(ios_base::fixed,ios_base::floatfield);//定点计数
	cout << "Right Justification:\n";
	for(n = 1;n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	//scientific and fixed 将显示小数点后的位数为precision
	//对于setf设定的参数，则使用unsetf取消设定
	return 0;
}
