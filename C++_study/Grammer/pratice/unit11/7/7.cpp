#include<iostream>
#include"7.h"
namespace COMPLEX
{
	Complex::Complex()
	{
		real = imaginary = 0.0;
	}
	Complex::Complex(double n1,double n2)
	{
		real = n1;
		imaginary = n2;
	}
	Complex::~Complex()
	{
	}
	Complex operator+(const Complex & cx1,const Complex & cx2)
	{
		Complex sum;
		sum.real= cx1.real+cx2.real;
		sum.imaginary= cx1.imaginary+cx2.imaginary;
		return sum;
	}
	Complex operator-(const Complex & cx1,const Complex & cx2)
	{
		Complex sub;
		sub.real= cx1.real - cx2.real;
		sub.imaginary= cx1.imaginary - cx2.imaginary;
		return sub;
	}
	Complex Complex::operator*(double n) const//const修饰即不改变隐式类对象值
	{
		return Complex( n * real, n * imaginary);
	}
	Complex operator*(double m,const Complex & cx)//报错会丢失限定符，
	//传参过程cx为const，但成员*参数隐饰不为const，导致传参失败
	{
		return cx * m;
	}
	Complex operator*(const Complex & cx1,const Complex & cx2)
	{
		Complex end;
		end.real = cx1.real * cx2.real - cx1.imaginary * cx2.imaginary;
		end.imaginary = cx1.real * cx2.imaginary + cx1.imaginary * cx2.real;
		return end;
	}
	Complex Complex::operator~() const
	{
		return Complex(real,-imaginary);
	}
	std::ostream & operator<<(std::ostream & os,const Complex & cx)
	{
		os<<"("<<cx.real<<","<<cx.imaginary<<"i )\n";
		return os;
	}
	std::istream & operator>>(std::istream & is, Complex & cx)
	{
		std::cout<<"Input the real part: ";
		is>>cx.real;
		std::cout<<"Input the imaginary part: ";
		is>>cx.imaginary;
		return is;
	}
}
