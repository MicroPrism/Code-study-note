#include<iostream>
#include"5.h"
Stack::Stack()
{
	top = 0;
}
bool Stack::isempty() const
{
	return top == 0;
}
bool Stack::isfull() const
{
	return top ==MAX;
}
bool Stack::push(const Item & item)
{
	if(top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else 
		return false;
}
bool Stack::pop()
{
	if(top > 0)
	{
		total += items[--top].payment;
		show_tot();
		return true;
	}
	else 
		return false;
}
void Stack::show_tot() const
{
	std::cout<<total<<std::endl;
}
