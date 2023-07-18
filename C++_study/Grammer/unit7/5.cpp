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

polar* trans(const rect*,polar *);
void show(const polar*);


int main(void)
{
	using namespace std;
	rect input;
	polar output;
	cout<<"Input rect two number x,y:";
	while(cin>>input.x>>input.y)
	{
		show(trans(&input,&output));
		cout<<"continue input :";
	}
	return 0;
}
polar* trans(const rect* a,polar *b)
{
	//polar *temp = new polar;
	const double RAD_TO_DEG = 57.29577951;
	b->distance = sqrt(a->x*a->x + a->y * a->y);
	b->angle = atan2(a->y,a->x)*RAD_TO_DEG;
	return b;
}
void show(const polar* a)
{
	using namespace std;
	cout<<"Distance is :"<<a->distance
		<<" Angle is :"<<a->angle<<endl;
}
