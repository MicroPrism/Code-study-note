#include<iostream>
#include"mytime2.h"
Time::Time()
{
	hours = minutes = 0;
}
Time::Time(int h,int m)
{
	hours = h;
	minutes = m;
}
void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes /60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h ,int m )
{
	hours = h;
	minutes = m;
}
Time Time::operator+(const Time & t) const
{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours +sum.minutes/60;
	sum.minutes %= 60;
	return sum;
}
Time Time::operator-(const Time & t) const
{
	Time sum;
	if(hours > t.hours)
		sum.hours = hours - t.hours;
	if(minutes > t.minutes)
		sum.minutes = minutes - t.minutes;
	else
	{
		sum.minutes = minutes - t.minutes + 60;
		sum.hours--;
	}
	return sum;	
}
Time Time::operator*(double n) const
{
	Time mul;
	mul.minutes = (minutes + hours * 60) * n;
	mul.hours = mul.minutes/60;
	mul.minutes %= 60;
	return mul;
}
void Time::Show() const
{
	std::cout<<hours<<"hours "<<minutes<<"minutes\n";
}
