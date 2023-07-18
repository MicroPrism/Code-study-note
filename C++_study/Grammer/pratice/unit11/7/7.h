#ifndef UNIT11_7_H
#define UNIT11_7_H
namespace COMPLEX
{
	class Complex
	{
	private:
		double real;
		double imaginary;
	public:
		Complex();
		Complex(double n1,double n2);
		~Complex();
		friend Complex operator+(const Complex & cx1,const Complex & cx2);
		friend Complex operator-(const Complex & cx1,const Complex & cx2);
		Complex operator*(double n) const ;
		friend Complex operator*(double n,const Complex & cx);
		friend Complex operator*(const Complex & cx1,const Complex & cx2);
		Complex operator~() const;
		friend std::ostream & operator<<(std::ostream & os,const Complex & cx);
		friend std::istream & operator>>(std::istream & os, Complex & cx);	
	};
}
#endif
