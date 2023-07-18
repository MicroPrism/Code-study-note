#include<iostream>
#include"2.h"
//Person::Person(){lname = "";fname[0] = '\0';};
Person::Person(const std::string & ln,const char * fn)
{
	lname = ln;
	for(int i = 0;i< LIMIT & fn[i]!='\0';i++)
		fname[i] = fn[i];
}
void Person::Show() const
{
	std::cout<<"firstname: ";
	for(int i = 0;i < LIMIT & fname[i]!='\0';i++)
		std::cout<<fname[i];
	std::cout<<"\nlastname: "<<lname<<std::endl;
}
void Person::FormalShow() const
{
	std::cout<<"lastname: "<<lname<<std::endl;
	std::cout<<"firstname: ";
	for(int i = 0;i < LIMIT & fname[i]!='\0';i++)
		std::cout<<fname[i];
	std::cout<<std::endl;
}
Person::~Person()
{}
