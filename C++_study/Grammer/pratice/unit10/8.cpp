#include<iostream>
#include"8.h"
List::List()
{
	array[0] = '\0';
}
List::List(int a)
{
	array[0] = a;
	top++;
}
List::~List()
{}
void List::add_data(Item a)
{
	if(isfull())
		std::cout<<"Error!Space is full!\n";
	else
		array[top++] = a;
}
bool List::isfull() const
{
	if(top == MAX) 
		return true;
	else
		return false;
}
bool List::isempty() const
{
	if(top == 0) 
		return true;
	else
		return false;
}
/*void List::visit(void (*pf)(int & a));
{
	int i;
	std::cin>>i;
	if(i<top)
		pf(array[i]);
	else
		std::cout<<"The top is "<<top<<std::endl;
}*/
