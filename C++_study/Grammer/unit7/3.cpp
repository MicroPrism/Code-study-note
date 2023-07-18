#include<iostream>
#include<cmath>

struct polar
{
	double distance;
	double angle;
};
struct rect
{
	double x;
	double y;
};

polar trans(rect);
void show(polar);


int main(void)
{
	using namespace std;
	rect input;
	cout<<"Input rect two number x,y:";
	while(cin>>input.x>>input.y)
	{
		show(trans(input));
		cout<<"continue input :";
	}
	return 0;
}
polar trans(rect a)
{
	polar temp;
	const double RAD_TO_DEG = 57.29577951;
	temp.distance = sqrt(a.x*a.x + a.y * a.y);
	temp.angle = atan2(a.y,a.x)*RAD_TO_DEG;
	return temp;
}
void show(polar a)
{
	using namespace std;
	cout<<"Distance is :"<<a.distance
		<<" Angle is :"<<a.angle<<endl;
}
