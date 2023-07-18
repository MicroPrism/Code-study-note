#include<iostream>
#include"6.h"
Move::Move(double a,double b)
{
	x = a;
	y = b;
}
void Move::showmove() const
{
	std::cout<<x<<" / "<<y<<std::endl;
}
Move Move::add(const Move & m) const
{
	Move *temp = new Move;
	(*temp).x = x + m.x;
	(*temp).y = y + m.y;
	return *temp;
}
void Move::reset(double a,double b)
{
	x = a;
	y = b;
}
