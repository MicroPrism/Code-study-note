#include<iostream>
#include<cmath>
#include"1.h"

polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	answer.distance = sqrt(xypos.x*xypos.x +xypos.y*xypos.y);
	answer.angle = atan2(xypos.y,xypos.x);
	return answer;
}
void show_polar(polar dapos)
{
	using namespace std;
	const double RADTODEG = 57.29577951;
	cout<<dapos.distance<<" / "<<dapos.angle*RADTODEG<<endl;
}
