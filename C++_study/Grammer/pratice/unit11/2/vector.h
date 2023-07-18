#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
namespace VECTOR//注意：此时才算创建名称空间，而不能把一个类作为名称空间
{
	class Vector
	{
	public:
		//enum Mode{RECT,POL};
	private:
		double x;
		double y;
		//double mag;
		//double ang;
		//Mode mode;
		//void set_mag();
		//void set_ang();
		//void set_x();
		//void set_y();
	public:
		Vector();
		Vector(double n1,double n2);
		void reset(double n1,double n2);
		~Vector();
		double xval() const {return x;}
		double yval() const {return y;}
		double magval() const ;
		double angval() const ;
		
		void polar_mode();
		void rect_mode();
		
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		
		friend Vector operator*(double n,const Vector & a);
		friend std::ostream & 
			operator<<(std::ostream & os,const Vector & v);
	};
	
}
#endif
