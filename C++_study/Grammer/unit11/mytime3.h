#ifndef MYTIME3_H_
#define MYTIME3_H_

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0,int m = 0);
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	friend Time operator*(double m,const Time & t)
		{return t * m;}
	friend std::ostream & operator<<(std::ostream & os,const Time & t);
	//需要改变os的内容，不应对函数使用const
	void Show() const;
};
#endif
