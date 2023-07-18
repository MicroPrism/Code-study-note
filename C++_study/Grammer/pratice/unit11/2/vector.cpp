#include<iostream>
#include<cmath>
#include"vector.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45 /atan(1.0);
	double Vector::angval() const 
	{
		if(x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y,x);
	}
	double Vector::magval() const 
	{
		return sqrt(x * x + y * y);
	}
	
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1,double n2)
	{	
		x = n1;
		y = n2;	
	}
	void Vector::reset(double n1,double n2)
	//构造函数，类内使用Mode,不需加限定符
	//Mode的全称 VECTOR::Vector::Mode
	{
		x = n1;
		y = n2;
	}
	Vector::~Vector()
	{}
	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x,y + b.y);
	}
	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x,y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x,-y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(x*n,y*n);
	}
	Vector operator*(double n,const Vector & a)
	{
		return a * n;
	}
	std::ostream & 	operator<<(std::ostream & os,const Vector & v)
	{
		os<<"(x,y) = (" <<v.x<<","<<v.y<<")";
		return os;
	}
}
